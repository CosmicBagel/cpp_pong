// math stuff, pure functions that can be easily inlined

#include <cmath>
#include <cstdlib>
#include <type_traits>

template <typename T>
concept int_or_float = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <int_or_float T>
[[nodiscard]] inline T lerp(T a, T b) {
    return abs(b - a) * 0.01F;
};

