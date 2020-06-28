//#include "gtest/gtest.h"
//#include "../Utls/Types.h"
//#include "../Lib/OlechowskiTimer.h"
//
//namespace Tests {
//    using namespace std::chrono_literals;
//
//    TEST(Period_timer_tests, simple_test) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 1;
//
//        auto callback = [&]() {
//            counter++;
//        };
//
//        timer->set_period_timer(callback, 100ms);
//        std::this_thread::sleep_for(500ms);
//
//        EXPECT_EQ(5, counter);
//    }
//
//    TEST(Period_timer_tests, stop_on_destructor) {
//        uint32 counter = 1;
//        auto callback = [&]() {
//            counter++;
//        };
//        {
//            auto timer = Timer::OlechowskiTimer::Create();
//            timer->set_period_timer(callback, 100ms);
//            std::this_thread::sleep_for(450ms);
//        }
//        std::this_thread::sleep_for(500ms);
//        EXPECT_EQ(5, counter);
//    }
//
//    TEST(Period_timer_tests, manual_stop) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 1;
//
//        auto callback = [&]() {
//            counter++;
//        };
//
//        timer->set_period_timer(callback, 200ms);
//        std::this_thread::sleep_for(300ms);
//        timer->stop_timer();
//        timer->throw_last_error();
//
//        std::this_thread::sleep_for(300ms);
//        EXPECT_EQ(2, counter);
//    }
//
//    TEST(Period_timer_tests, std_exception_in_callback) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 1;
//
//        auto callback = [&]() {
//            if (counter++ == 3) {
//                throw std::exception();
//            }
//        };
//
//        timer->set_period_timer(callback, 100ms);
//        std::this_thread::sleep_for(1s);
//        EXPECT_EQ(4, counter);
//        ASSERT_THROW(timer->throw_last_error(), std::exception);
//    }
//
//    TEST(Period_timer_tests, not_std_exception_in_callback) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 1;
//
//        auto callback = [&]() {
//            if (counter++ == 3) {
//                throw 111;
//            }
//        };
//
//        timer->set_period_timer(callback, 100ms);
//        std::this_thread::sleep_for(1s);
//        EXPECT_EQ(4, counter);
//        ASSERT_THROW(timer->throw_last_error(), int);
//    }
//
//    TEST(Period_timer_tests, stop_timer_from_calback) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 1;
//
//        auto callback = [&]() {
//            counter++;
//            if (counter==4){
//                timer->stop_timer();
//            }
//        };
//
//        timer->set_period_timer(callback, 20ms);
//        timer->wait_until_stop();
//        EXPECT_EQ(4, counter);
//    }
//
//    TEST(Period_timer_tests, reset_timeer_simple) {
//        auto timer = Timer::OlechowskiTimer::Create();
//
//        auto callback = [&]() {
//            FAIL();
//        };
//
//        timer->set_period_timer(callback, 500ms);
//        std::this_thread::sleep_for(300ms);
//        timer->set_period_timer(callback, 500ms);
//        std::this_thread::sleep_for(300ms);
//    }
//
//    TEST(Period_timer_tests, cancel_long_task) {
//        auto timer = Timer::OlechowskiTimer::Create();
//
//        auto callback = [&]() {
//            FAIL();
//        };
//
//        EXPECT_EQ(timer->is_running(), false);
//        timer->set_period_timer(callback, 100s);
//        std::this_thread::sleep_for(100ms);
//        timer->stop_timer();
//        timer->wait_until_stop();
//
//        timer->throw_last_error();
//    }
//
//    TEST(Period_timer_tests, control_timer_from_calback) {
//        uint32 counter = 0;
//        auto timer = Timer::OlechowskiTimer::Create();
//
//        auto callback_2 = [&]() {
//            counter = 10;
//        };
//
//        auto callback_1 = [&]() {
//            timer->set_period_timer(callback_2, 50ms);
//        };
//
//        timer->set_period_timer(callback_1, 50ms);
//
//        std::this_thread::sleep_for(1s);
//        EXPECT_EQ(10, counter);
//    }
//
//}