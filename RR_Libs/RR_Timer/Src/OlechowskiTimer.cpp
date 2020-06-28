//#include "OlechowskiTimer.h"
//
//
//namespace Timer {
//
//    OlechowskiTimerPtr OlechowskiTimer::Create() {
//        return std::make_shared<OlechowskiTimer>();
//    }
//
//    void OlechowskiTimer::set_period_timer(const CallbackType& callback, TimeDuration period) noexcept {
//        set_timer(callback, period, false);
//    }
//
//    void OlechowskiTimer::set_single_timer(const CallbackType& callback, TimeDuration delay) noexcept {
//        set_timer(callback, delay, true);
//    }
//
//    void OlechowskiTimer::set_timer(const CallbackType& callback, TimeDuration delta_time, bool is_single) noexcept {
//        set_thread_state(ThreadState::Stopping);
//        m_last_exception = nullptr;
//        m_callback = callback;
//        m_period_or_delay = delta_time.count();
//        m_invoke_only_once = is_single;
//        mode_has_changed = true;
//        set_thread_state(ThreadState::Runing);
//    }
//
//    void OlechowskiTimer::stop_timer() noexcept {
//        set_thread_state(ThreadState::Stopping);
//    }
//
//    void OlechowskiTimer::invoke_callback() noexcept {
//        try {
//            m_callback();
//        } catch (...) {
//            m_last_exception = std::current_exception();
//            set_thread_state(ThreadState::Stopping);
//        }
//    }
//
//    void OlechowskiTimer::set_thread_state(ThreadState state) noexcept {
//
//        if ((state == m_thread_state) ||
//            (state == ThreadState::Stopping && m_thread_state == ThreadState::Stoped)) {
//            return;
//        }
//
//        {
//            std::lock_guard<std::mutex> lock1(m_state_mutex);
//            if (m_thread_state == ThreadState::Terminating) {
//                return;
//            }
//
//            if (state != ThreadState::Runing) {
//                m_callback = nullptr;
//            }
//
//            m_thread_state = state;
//        }
//        m_state_cv.notify_all();
//
//        if (state == ThreadState::Stopping) {
//
//            if (m_thread.get_id() == std::this_thread::get_id()) {
//                return;
//            }
//
//            std::unique_lock<std::mutex> lock(m_state_mutex);
//            const auto pred = [&] {
//                return
//                        m_thread_state == ThreadState::Stoped ||
//                        m_thread_state == ThreadState::Terminating;
//            };
//            m_state_cv.wait(lock, pred);
//        }
//    }
//
//    void OlechowskiTimer::throw_last_error() const {
//        if (m_last_exception != nullptr) {
//            std::rethrow_exception(m_last_exception);
//        }
//    }
//
//    void OlechowskiTimer::thread_function(OlechowskiTimer& self) noexcept{
//
//        const auto stop_pred = [&self] { return self.m_thread_state != ThreadState::Stoped; };
//        const auto run_pred = [&self] { return self.m_thread_state != ThreadState::Runing; };
//
//        while (true) {
//            std::unique_lock<std::mutex> lock(self.m_state_mutex);
//            self.m_state_cv.wait(lock, stop_pred);
//
//            if (self.m_thread_state == ThreadState::Stopping) {
//                self.m_thread_state = ThreadState::Stoped;
//                lock.unlock();
//                self.m_state_cv.notify_all();
//                continue;
//            }
//
//            if (self.m_thread_state == ThreadState::Terminating) {
//                return;
//            }
//
//            bool cv_result = self.m_state_cv.wait_for(lock, TimeDuration(self.m_period_or_delay), run_pred);
//
//            if (!cv_result && self.m_thread_state == ThreadState::Runing) {
//
//                lock.unlock(); //We dont want to lock for possibly long time (calback execution)
//                self.mode_has_changed = false;
//
//                self.invoke_callback();
//
//                if (self.m_invoke_only_once && !self.mode_has_changed) {
//                    self.set_thread_state(ThreadState::Stopping);
//                }
//            }
//        }
//    }
//
//    //=========================================
//
//    OlechowskiTimer::OlechowskiTimer() noexcept
//            : m_thread_state(ThreadState::Stoped), m_thread(&thread_function, std::ref(*this)) {
//    }
//
//    OlechowskiTimer::~OlechowskiTimer() {
//        set_thread_state(ThreadState::Terminating);
//        m_thread.join();
//    }
//
//    void OlechowskiTimer::wait_until_stop() noexcept {
//        const auto pred = [&] {
//            return
//                    m_thread_state == ThreadState::Stoped ||
//                    m_thread_state == ThreadState::Terminating;
//        };
//        std::unique_lock<std::mutex> lock(m_state_mutex);
//        m_state_cv.wait(lock, pred);
//    }
//
//    bool OlechowskiTimer::is_running() const noexcept {
//        return m_thread_state == ThreadState::Runing;
//    }
//
//}