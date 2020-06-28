# Interval Map

## What is, the purpose of this project?
It is container to effectively store ranges and associate value to them.

## How to use it?
```cpp
#include <iostream>

#include "IntervalMap.h"

int main() {
    RR_Containers::IntervalMap<uint64_t, char> obj('X');
    obj.reserve_range(10, 20, 'A');
    obj.reserve_range(15, 30, 'B');

    std::cout << obj[5] << std::endl;    // X
    std::cout << obj[11] << std::endl;   // A
    std::cout << obj[18] << std::endl;   // B
    std::cout << obj[100] << std::endl;  // X
}
```

## What are requirements to **Key** type?
 * Implements less-than operator.
 * Is copyable.
 * Is assignable.
 * Works with **std::numeric_limits<K>::min()**

## What are requirements to **Value** type?
 * Implements operator==.
 * Is copyable.
 * Is assignable.
 
## How effective is this container?
 * operator[] is as fast as std::map::upper_bound(), so it is **log(n)**
 * reserve_range() is also **log(n)** as it uses only std::map::upper_bound() and std::map::insert(). The while loop will have at most 2 iterations.

## How is it implemented?
Look to **IntervalMap.h**

## Where can I find more information?
There is [blog post](https://blog.robertolechowski.com/Interval_Container/).




