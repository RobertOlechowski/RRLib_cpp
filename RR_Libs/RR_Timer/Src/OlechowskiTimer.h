//#pragma once
//
//#include "TimerEnums.h"
//
//#include "../Utls/NonCopyableNotMoveable.h"
//#include "../Utls/Types.h"
//
//#include <memory>
//#include <functional>
//#include <chrono>
//#include <thread>
//#include <mutex>
//#include <atomic>
//#include <condition_variable>
//
//namespace Timer {
//    class OlechowskiTimer;
//
//    using OlechowskiTimerPtr = std::shared_ptr<OlechowskiTimer>;
//    using CallbackType = std::function<void()>;
//    using TimeDuration = std::chrono::milliseconds;
//}
//
//namespace Timer {
//    class OlechowskiTimer : public Utls::NonCopyableNotMoveable {
//    public:
//        static OlechowskiTimerPtr Create();
//
//        explicit OlechowskiTimer() noexcept;
//
//        virtual ~OlechowskiTimer();
//
//        void set_period_timer(const CallbackType& callback, TimeDuration period) noexcept;
//
//        void set_single_timer(const CallbackType& callback, TimeDuration delay) noexcept;
//
//        void stop_timer() noexcept;
//
//        void wait_until_stop() noexcept;
//
//        bool is_running() const noexcept;
//
//        void throw_last_error() const;
//
//    private:
//        CallbackType m_callback;
//
//        std::mutex m_state_mutex;
//        std::condition_variable m_state_cv;
//
//        std::thread m_thread;
//        std::atomic<ThreadState> m_thread_state;
//        volatile bool m_invoke_only_once;
//        volatile bool mode_has_changed;
//        volatile uint64 m_period_or_delay;
//
//        std::exception_ptr m_last_exception;
//
//        void set_timer(const CallbackType& callback, TimeDuration delta_time, bool is_single) noexcept;
//
//        void invoke_callback() noexcept;
//
//        void set_thread_state(ThreadState state) noexcept;
//
//        static void thread_function(OlechowskiTimer& self) noexcept;
//    };
//
//}
//
//
//