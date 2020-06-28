//#include "gtest/gtest.h"
//#include "../Utls/Types.h"
//#include "../Lib/OlechowskiTimer.h"
//
//namespace Tests {
//    using namespace std::chrono_literals;
//
//    TEST(Mix_timer_tests, multiple_stop) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback = [&]() {
//            counter++;
//        };
//
//        timer->stop_timer();
//        timer->stop_timer();
//
//        timer->set_single_timer(callback, 100ms);
//
//        timer->stop_timer();
//
//        timer->set_single_timer(callback, 100ms);
//        EXPECT_EQ(timer->is_running(), true);
//        timer->stop_timer();
//        timer->set_period_timer(callback, 100ms);
//        timer->stop_timer();
//        timer->set_single_timer(callback, 100ms);
//
//        std::this_thread::sleep_for(300ms);
//
//        EXPECT_EQ(timer->is_running(), false);
//        EXPECT_EQ(1, counter);
//    }
//
//    TEST(Mix_timer_tests, change_calback) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback_1 = [&]() {
//            counter=5;
//        };
//
//        auto callback_2 = [&]() {
//            FAIL();
//        };
//
//        EXPECT_EQ(timer->is_running(), false);
//        timer->set_period_timer(callback_1, 500ms);
//        EXPECT_EQ(timer->is_running(), true);
//        std::this_thread::sleep_for(100ms);
//        EXPECT_EQ(timer->is_running(), true);
//        timer->set_period_timer(callback_2, 500ms);
//        std::this_thread::sleep_for(100ms);
//        timer->set_period_timer(callback_2, 500ms);
//        timer->set_period_timer(callback_2, 500ms);
//        std::this_thread::sleep_for(200ms);
//        timer->set_period_timer(callback_2, 500ms);
//        timer->set_single_timer(callback_1, 10ms);
//        std::this_thread::sleep_for(100ms);
//        EXPECT_EQ(timer->is_running(), false);
//
//        timer->throw_last_error();
//
//        EXPECT_EQ(5, counter);
//    }
//
//    TEST(Mix_timer_tests, change_timer_type) {
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback_1 = [&]() {
//            FAIL();
//        };
//
//        auto callback_2 = [&]() {
//            FAIL();
//        };
//
//        auto callback_3 = [&]() {
//            counter = 500;
//        };
//
//        timer->set_single_timer(callback_1, 500ms);
//        std::this_thread::sleep_for(100ms);
//        timer->set_single_timer(callback_2, 500ms);
//        EXPECT_EQ(0, counter);
//        EXPECT_EQ(timer->is_running(), true);
//        std::this_thread::sleep_for(100ms);
//        EXPECT_EQ(timer->is_running(), true);
//        timer->set_period_timer(callback_1, 500ms);
//        EXPECT_EQ(timer->is_running(), true);
//        EXPECT_EQ(0, counter);
//        std::this_thread::sleep_for(100ms);
//        EXPECT_EQ(0, counter);
//        EXPECT_EQ(timer->is_running(), true);
//        timer->set_period_timer(callback_2, 500ms);
//        std::this_thread::sleep_for(100ms);
//        timer->set_period_timer(callback_2, 500ms);
//        timer->set_period_timer(callback_2, 500ms);
//        std::this_thread::sleep_for(200ms);
//        timer->set_period_timer(callback_2, 50ms);
//        EXPECT_EQ(0, counter);
//        timer->stop_timer();
//        std::this_thread::sleep_for(100ms);
//        EXPECT_EQ(0, counter);
//        timer->set_single_timer(callback_3, 50ms);
//        std::this_thread::sleep_for(100ms);
//        EXPECT_EQ(timer->is_running(), false);
//
//        timer->throw_last_error();
//
//        EXPECT_EQ(500, counter);
//    }
//
//
//}