//#include "gtest/gtest.h"
//
//#define RR_CONTAINER_INTEGRITY_TEST
//#include "../IntervalMap.h"
//
//TEST (IntervalMapTest, DefaultValue_0) {
//    RR_Containers::IntervalMap<uint64_t, uint64_t> obj(0);
//    EXPECT_EQ (0, obj[0]);
//    EXPECT_EQ (0, obj[10]);
//    EXPECT_EQ (0, obj[100]);
//    EXPECT_EQ (0, obj[999999]);
//}
//
//TEST (IntervalMapTest, DefaultValue_5) {
//    RR_Containers::IntervalMap<uint64_t, uint64_t> obj(5);
//    EXPECT_EQ (5, obj[0]);
//    EXPECT_EQ (5, obj[10]);
//    EXPECT_EQ (5, obj[100]);
//    EXPECT_EQ (5, obj[999999]);
//}


//TEST (IntervalMapTest, range) {
//    RR_Containers::IntervalMap<uint64_t, uint64_t> obj(0);
//    obj.reserve_range(10, 20, 1);
//    EXPECT_EQ (0, obj[9]);
//    EXPECT_EQ (1, obj[10]);
//    EXPECT_EQ (1, obj[11]);
//    EXPECT_EQ (1, obj[19]);
//    EXPECT_EQ (0, obj[20]);
//
//    obj.reserve_range(10, 20, 5);
//    EXPECT_EQ (0, obj[9]);
//    EXPECT_EQ (5, obj[10]);
//    EXPECT_EQ (5, obj[11]);
//    EXPECT_EQ (5, obj[19]);
//    EXPECT_EQ (0, obj[20]);
//
//
//    obj.reserve_range(5, 15, 6);
//    EXPECT_EQ (0, obj[4]);
//    EXPECT_EQ (6, obj[5]);
//    EXPECT_EQ (6, obj[9]);
//    EXPECT_EQ (6, obj[14]);
//    EXPECT_EQ (5, obj[15]);
//    EXPECT_EQ (5, obj[19]);
//    EXPECT_EQ (0, obj[20]);
//}
//
//
//TEST (IntervalMapTest, integrity) {
//    constexpr uint64_t TESTS_COUNT = 500;
//    constexpr uint64_t VALUE_MAX = 50;
//    constexpr uint64_t RANGE_MAX = 200;
//
//    RR_Containers::IntervalMap<uint64_t, uint64_t> obj(0);
//
//    std::mt19937 gen(2); //Standard mersenne_twister_engine seeded with rd()
//    std::uniform_int_distribution<> range_distribution(0, RANGE_MAX);
//    std::uniform_int_distribution<> value_distribution(0, VALUE_MAX);
//
//    for( auto i = 0; i < TESTS_COUNT; ++i) {
//        auto range_start = static_cast<uint64_t>(range_distribution(gen));
//        auto range_end = static_cast<uint64_t>(range_distribution(gen));
//        auto value = static_cast<uint64_t>(value_distribution(gen));
//
//        obj.reserve_range(range_start, range_end, value);
//
//        for(auto j = range_start; j < range_end; ++j){
//            EXPECT_EQ (value, obj[j]);
//        }
//
//        EXPECT_TRUE(obj.test_integrity());
//    }
//
//}
//
//