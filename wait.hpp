#ifndef _WAIT_H_P_P_
#define _WAIT_H_P_P_

#include <chrono>
template<typename T, typename F = void(*)(), typename... Params>
inline void wait(T delay, F unary_predicate = [](Params...) {}, Params... params) noexcept
{
    using namespace std::chrono;
    auto const start = high_resolution_clock().now();
    while(duration_cast<T>(high_resolution_clock().now() - start) < delay) 
        unary_predicate(params...);
}

#endif /* _WAIT_H_P_P_ */
