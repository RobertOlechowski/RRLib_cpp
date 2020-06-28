# Recruitment Task - C++ 
General usage one-shot or a periodic timer C++

## Task Description ([Link](https://github.com/RobertOlechowski/RR_Timer/raw/master/Task/Recruitment%20Task%20-%20C%2B%2B%20.pdf))
* Implement a class that provides general usage one-shot or a periodic timer
* API should provide a way to schedule the following callbacks:
    * Timer starting after the defined delay
    * Timer with the possibility to schedule action with the defined period
* API should provide a way to stop the timer
* Implement possible use cases with a timer written by you
* Create unit tests for your implementation

## How to run example & tests
* Make sure you have google_test library installed and $ENV{gtest_DIR} is properly set.
* Run cmake and have fun

## Solution (what I can do with this class)
### Set periodic or delayed action
```
TEST(Readme_timer_tests, simple_example) {
    using namespace std::chrono_literals;
    uint32 counter = 0;

    auto timer1 = Timer::OlechowskiTimer::Create();
    timer1->set_period_timer([&]() { counter++;}, 50ms);

    auto timer2 = Timer::OlechowskiTimer::Create();
    timer2->set_single_timer([&]() { timer1->stop_timer();}, 275ms);

    EXPECT_EQ(timer1->get_timer_state(), Timer::ThreadState::Runing);
    EXPECT_EQ(timer2->get_timer_state(), Timer::ThreadState::Runing);

    timer2->wait_until_stop();

    EXPECT_EQ(timer1->get_timer_state(), Timer::ThreadState::Stoped);
    EXPECT_EQ(timer2->get_timer_state(), Timer::ThreadState::Stoped);

    EXPECT_EQ(5, counter);
}
```

### Cache exception and throw it latter
```
TEST(Readme_timer_tests, cache_and_throw_exception) {
    using namespace std::chrono_literals;
    auto timer = Timer::OlechowskiTimer::Create();
    uint32 counter = 0;

    auto callback = [&]() {
        counter++;
        if (counter==5){
            throw "Some exception";
        }
    };

    timer->set_period_timer(callback, 20ms);
    timer->wait_until_stop();
    EXPECT_EQ(5, counter);
    ASSERT_THROW(timer->throw_last_error(), const char*);
}
```

### Control timer from inside callback code (without manual lock)
```
TEST(Readme_timer_tests, Control_timer_from_callback_code) {
    using namespace std::chrono_literals;
    auto timer = Timer::OlechowskiTimer::Create();
    uint32 counter = 0;

    auto callback_3 = [&]() {
        counter++;
        if (counter == 10) {
            timer->stop_timer();
        }
    };

    auto callback_2 = [&]() {
        counter++;
        if (counter == 4) {
            timer->set_period_timer(callback_3, 30ms);
        }
    };

    auto callback_1 = [&]() {
        timer->set_period_timer(callback_2, 50ms);
    };

    EXPECT_EQ(timer->get_timer_state(), Timer::ThreadState::Stoped);
    timer->set_single_timer(callback_1, 20ms);
    EXPECT_EQ(timer->get_timer_state(), Timer::ThreadState::Runing);
    timer->wait_until_stop();
    EXPECT_EQ(timer->get_timer_state(), Timer::ThreadState::Stoped);
    EXPECT_EQ(10, counter);
}
```
