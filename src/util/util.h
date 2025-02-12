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

inline constexpr void shift_up(u64& current_position)
{
    current_position <<= 8;
}

// @Param current_position: Any bitboard
// @Return: The bitboard shifted right eight bits.

inline constexpr void shift_down(u64& current_position)
{
    current_position >>= 8;
}

// @Param current_position: Any bitboard
// @Return: If the file is h, return 0. Otherwise return the posititon shifted right one bit.

inline constexpr void shift_right(u64& current_position)
{
    current_position = (current_position & ~Types::file_h) << 1;
}

// @Param current_position: Any bitboard
// @Return: If the file is h, return 0. Otherwise return the posititon shifted left one bit.

inline constexpr void shift_left(u64& current_position)
{
    current_position = (current_position & ~Types::file_a) >> 1;
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

inline constexpr void clear_least_sig_bit(u64& bitboard)
{
    bitboard &= (bitboard - 1);
}

} // namespace Util

#endif
