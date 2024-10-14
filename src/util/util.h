#ifndef UTIL_H
#define UTIL_H

#include "types.h"

namespace Util
{

[[nodiscard]]
inline constexpr std::uint64_t shift_up(const std::uint64_t current_position)
{
    return current_position << 8;
}

[[nodiscard]]
inline constexpr std::uint64_t shift_down(const std::uint64_t current_position)
{
    return current_position >>  8;
}

[[nodiscard]]
inline constexpr std::uint64_t shift_right(const std::uint64_t current_position)
{
    return (current_position & Types::file_h) ? 0 : current_position << 1;
}

[[nodiscard]]
inline constexpr std::uint64_t shift_left(const std::uint64_t current_position)
{
    return (current_position & Types::file_a) ? 0 : current_position >> 1;
}

}

#endif
