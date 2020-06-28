//#include "../Lib/OlechowskiTimer.h"
//
//#include <iostream>
//#include <exception>
//
//
//int main() {
//    using namespace std::chrono_literals;
//    std::cout << std::endl;
//    std::cout << "=== Robert Olechowski ===" << std::endl;
//    std::cout << "=== Api DEMO ===" << std::endl;
//
//    uint32 counter = 1;
//
//    auto timer_1_ptr = Timer::OlechowskiTimer::Create();
//    auto callback_1 = [&]() {
//        std::cout << "  Tick: " << counter++ << std::endl;
//        if (counter==5) {
//            throw std::exception();
//        }
//    };
//    timer_1_ptr->set_period_timer(callback_1, 500ms);
//
//
//    auto timer_2_ptr = Timer::OlechowskiTimer::Create();
//    auto callback_2 = [&]() { timer_1_ptr->stop_timer(); };
//    timer_2_ptr->set_single_timer(callback_2, 4s);
//
//
//    timer_1_ptr->wait_until_stop();
//
//    std::cout << "  EXIT  " << std::endl;
//    try {
//        timer_1_ptr->throw_last_error();
//    }catch (const std::exception& e){
//        std::cout << "Caught " << e.what() << "\n";
//    }
//    catch (...){
//        std::cout << "Caught not std::exception \n";
//    }
//
//
//    return 0;
//}