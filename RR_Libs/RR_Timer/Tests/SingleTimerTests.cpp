//#include "gtest/gtest.h"
//#include "../Utls/Types.h"
//#include "../Lib/OlechowskiTimer.h"
//
//namespace Tests {
//    using namespace std::chrono_literals;
//
//    TEST(Single_timer_tests, simple_test) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback = [&]() {
//            counter++;
//        };
//
//        timer->set_single_timer(callback, 100ms);
//        timer->wait_until_stop();
//
//        EXPECT_EQ(timer->is_running(), false);
//        EXPECT_EQ(1, counter);
//    }
//
//    TEST(Single_timer_tests, stop_on_destructor) {
//        uint32 counter = 0;
//        auto callback = [&]() {
//            counter++;
//        };
//        {
//            auto timer = Timer::OlechowskiTimer::Create();
//            timer->set_single_timer(callback, 10s);
//            std::this_thread::sleep_for(200ms);
//        }
//        std::this_thread::sleep_for(200ms);
//        EXPECT_EQ(0, counter);
//    }
//
//    TEST(Single_timer_tests, manual_stop) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback = [&]() {
//            counter++;
//        };
//
//        timer->set_single_timer(callback, 10s);
//        std::this_thread::sleep_for(300ms);
//        timer->stop_timer();
//        timer->throw_last_error();
//
//        timer->wait_until_stop();
//        EXPECT_EQ(0, counter);
//    }
//
//    TEST(Single_timer_tests, std_exception_in_callback) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback = [&]() {
//            throw std::exception();
//        };
//
//        timer->set_single_timer(callback, 100ms);
//        timer->wait_until_stop();
//        EXPECT_EQ(0, counter);
//        ASSERT_THROW(timer->throw_last_error(), std::exception);
//    }
//
//    TEST(Single_timer_tests, not_std_exception_in_callback) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback = [&]() {
//            throw 111;
//        };
//
//        timer->set_single_timer(callback, 100ms);
//        timer->wait_until_stop();
//        EXPECT_EQ(0, counter);
//        ASSERT_THROW(timer->throw_last_error(), int);
//    }
//
//    TEST(Single_timer_tests, stop_timer_from_calback) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 1;
//
//        auto callback = [&]() {
//            counter = 5;
//            timer->stop_timer();
//        };
//
//        timer->set_single_timer(callback, 20ms);
//        timer->wait_until_stop();
//        EXPECT_EQ(5, counter);
//    }
//
//    TEST(Single_timer_tests, cancel_long_task) {
//        auto timer = Timer::OlechowskiTimer::Create();
//
//        auto callback = [&]() {
//            FAIL();
//        };
//
//        EXPECT_EQ(timer->is_running(), false);
//        timer->set_single_timer(callback, 100s);
//        std::this_thread::sleep_for(100ms);
//        timer->stop_timer();
//        timer->wait_until_stop();
//
//        timer->throw_last_error();
//    }
//
//    TEST(Single_timer_tests, control_timer_from_calback) {
//        uint32 counter = 0;
//        auto timer = Timer::OlechowskiTimer::Create();
//
//        auto callback_2 = [&]() {
//            counter = 10;
//        };
//
//        auto callback_1 = [&]() {
//            timer->set_single_timer(callback_2, 50ms);
//        };
//
//        timer->set_single_timer(callback_1, 50ms);
//        timer->wait_until_stop();
//
//        EXPECT_EQ(timer->is_running(), false);
//        EXPECT_EQ(10, counter);
//    }
//}