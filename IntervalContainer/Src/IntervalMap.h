#pragma once

#include <assert.h>
#include <map>
#include <limits>
#include <iterator>

namespace RR_Containers {

    template<class K, class V>
    class IntervalMap {
    private:
        using LimitsK = std::numeric_limits<K>;
        using KVMap = std::map<K, V>;
        KVMap m_db;

    public:
        IntervalMap(V const& value) {
            m_db.insert(m_db.begin(), std::make_pair(LimitsK::min(), value));
        };

        void reserve_range(K const& range_start, K const& range_end, const V& val) {
            if (!(range_start < range_end)) return;

            auto EndTempIt = --m_db.upper_bound(range_end);
            auto EndIt = m_db.insert(EndTempIt, std::make_pair(range_end, EndTempIt->second));
            EndIt->second = EndTempIt->second;

            auto BeginIt = --m_db.upper_bound(range_start);
            BeginIt = m_db.insert(BeginIt, std::make_pair(range_start, val));
            BeginIt->second = val;

            while (BeginIt != m_db.begin() && std::prev(BeginIt)->second == val)
                BeginIt--;

            while (EndIt != m_db.end() && BeginIt->second == EndIt->second)
                EndIt++;

            m_db.erase(++BeginIt, EndIt);
        }

        V const& operator[](K const& key) const {
            return (--m_db.upper_bound(key))->second;
        }

#ifdef RR_CONTAINER_INTEGRITY_TEST
        bool test_integrity() const {

            auto prev_value = m_db.begin()->second;
            for ( auto it = std::next(m_db.begin()); it != m_db.end(); it++ )
            {
                auto value = it->second;
                if (prev_value == value){
                    return false;
                }
                prev_value = value;
            }
            return true;
        }
#endif
    };
}



