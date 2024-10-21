//Author: Caden LeCluyse

#ifndef UTIL_H
#define UTIL_H

#include "types.h"
#include <cstdint>

using u64 = std::uint64_t;

namespace Util
{

// @Param current_position: Any bitboard
// @Return: The bitboard shifted left eight bits.

[[nodiscard]]
inline constexpr u64 shift_up(const u64 current_position)
{
    return current_position << 8;
}

// @Param current_position: Any bitboard
// @Return: The bitboard shifted right eight bits.

[[nodiscard]]
inline constexpr u64 shift_down(const u64 current_position)
{
    return current_position >> 8;
}

// @Param current_position: Any bitboard
// @Return: If the file is h, return 0. Otherwise return the posititon shifted right one bit.

[[nodiscard]]
inline constexpr u64 shift_right(const u64 current_position)
{
    return (current_position & ~Types::file_h) << 1;
}

// @Param current_position: Any bitboard
// @Return: If the file is h, return 0. Otherwise return the posititon shifted left one bit.

[[nodiscard]]
inline constexpr u64 shift_left(const u64 current_position)
{
    return (current_position & ~Types::file_a) >> 1;
}

// @Param current_position: Any bitboard
// @Return: The least significant bit of a given bitboard. 

[[nodiscard]]
inline constexpr u64 get_least_sig_bit(const u64 bitboard)
{
    return bitboard & -bitboard;
}

// @Param current_position: Any bitboard
// @Return: A bitboard with the least signficant bit cleared.

[[nodiscard]]
inline constexpr u64 clear_least_sig_bit(const u64 bitboard)
{
    return bitboard & (bitboard - 1);
}

} // namespace Util

#endif
