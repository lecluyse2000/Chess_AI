//Author: Caden LeCluyse

#ifndef ENGINE_H
#define ENGINE_H

#include <array>
#include <cstdint>
#include "util/util.h"

namespace Engine
{

// @Param pos: A valid bitboard with at least one knight on it 
// @Return: A bitboard with all available knight moves

[[nodiscard]] static consteval std::uint64_t get_knight_moves(const std::uint64_t pos)
{
    std::uint64_t move_board = 0;

    move_board = (Util::shift_left(pos) | Util::shift_right(pos)) << 16;
    move_board |= (Util::shift_left(pos) | Util::shift_right(pos)) >> 16;
    move_board |= (Util::shift_left(Util::shift_left(pos)) | Util::shift_right(Util::shift_right(pos))) << 8;
    move_board |= (Util::shift_left(Util::shift_left(pos)) | Util::shift_right(Util::shift_right(pos))) >> 8;

    return move_board;
}

// @Desc: Compile time function to generate the lookup table for knights
// @Return: The lookup table

[[nodiscard]] static consteval std::array<std::uint64_t, 64> generate_knight_lookup_table()
{
    std::array<std::uint64_t, 64> table;
    for (int i = 0; i < 64; ++i) {
        table[i] = get_knight_moves(1ULL << i); 
    }

    return table;
}

inline constexpr auto knight_table = generate_knight_lookup_table();

[[nodiscard]] int run(const bool analysis_mode);

}

#endif
