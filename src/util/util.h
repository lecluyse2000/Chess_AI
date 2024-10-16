//Author: Caden LeCluyse

#ifndef UTIL_H
#define UTIL_H

#include "types.h"

namespace Util
{

// @Param current_position: Any bitboard
// @Return: The bitboard shifted left eight bits.

[[nodiscard]]
inline constexpr std::uint64_t shift_up(const std::uint64_t current_position)
{
    return current_position << 8;
}

// @Param current_position: Any bitboard
// @Return: The bitboard shifted right eight bits.

[[nodiscard]]
inline constexpr std::uint64_t shift_down(const std::uint64_t current_position)
{
    return current_position >> 8;
}

// @Param current_position: Any bitboard
// @Return: If the file is h, return 0. Otherwise return the posititon shifted right one bit.

[[nodiscard]]
inline constexpr std::uint64_t shift_right(const std::uint64_t current_position)
{
    return (current_position & ~Types::file_h) << 1;
}

// @Param current_position: Any bitboard
// @Return: If the file is h, return 0. Otherwise return the posititon shifted left one bit.

[[nodiscard]]
inline constexpr std::uint64_t shift_left(const std::uint64_t current_position)
{
    return (current_position & ~Types::file_a) >> 1;
}

// @Param current_position: Any bitboard
// @Return: The least significant bit of a given bitboard. 

[[nodiscard]]
inline constexpr std::uint64_t get_least_sig_bit(const std::uint64_t bitboard)
{
    return bitboard & -bitboard;
}

// @Param current_position: Any bitboard
// @Return: A bitboard with the least signficant bit cleared.

[[nodiscard]]
inline constexpr std::uint64_t clear_least_sig_bit(std::uint64_t bitboard)
{
    return bitboard & (bitboard - 1);
}

} // namespace Util

#endif
