//#include "gtest/gtest.h"
//#include "../Utls/Types.h"
//#include "../Lib/OlechowskiTimer.h"
//
//namespace Tests {
//
//    TEST(Readme_timer_tests, simple_example) {
//        using namespace std::chrono_literals;
//        uint32 counter = 0;
//
//        auto timer1 = Timer::OlechowskiTimer::Create();
//        timer1->set_period_timer([&]() { counter++;}, 50ms);
//
//        auto timer2 = Timer::OlechowskiTimer::Create();
//        timer2->set_single_timer([&]() { timer1->stop_timer();}, 275ms);
//
//        EXPECT_EQ(timer1->is_running(), true);
//        EXPECT_EQ(timer2->is_running(), true);
//
//        timer2->wait_until_stop();
//
//        EXPECT_EQ(timer1->is_running(), false);
//        EXPECT_EQ(timer2->is_running(), false);
//
//        EXPECT_EQ(4, counter);
//
//    }
//
//    TEST(Readme_timer_tests, cache_and_throw_exception) {
//        using namespace std::chrono_literals;
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback = [&]() {
//            counter++;
//            if (counter==5){
//                throw "Some exception";
//            }
//        };
//
//        timer->set_period_timer(callback, 20ms);
//        timer->wait_until_stop();
//        EXPECT_EQ(5, counter);
//        ASSERT_THROW(timer->throw_last_error(), const char*);
//    }
//
//    TEST(Readme_timer_tests, Control_timer_from_callback_code) {
//        using namespace std::chrono_literals;
//        auto timer = Timer::OlechowskiTimer::Create();
//        uint32 counter = 0;
//
//        auto callback_3 = [&]() {
//            counter++;
//            if (counter == 10) {
//                timer->stop_timer();
//            }
//        };
//
//        auto callback_2 = [&]() {
//            counter++;
//            if (counter == 4) {
//                timer->set_period_timer(callback_3, 30ms);
//            }
//        };
//
//        auto callback_1 = [&]() {
//            timer->set_period_timer(callback_2, 50ms);
//        };
//
//        EXPECT_EQ(timer->is_running(), false);
//        timer->set_single_timer(callback_1, 20ms);
//        EXPECT_EQ(timer->is_running(), true);
//        timer->wait_until_stop();
//        EXPECT_EQ(timer->is_running(), false);
//        EXPECT_EQ(10, counter);
//    }
//
//
//}