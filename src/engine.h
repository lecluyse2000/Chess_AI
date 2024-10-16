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

// @Desc: Compile time function to generate the lookup table for white pawn attacks
// @Return: The lookup table

[[nodiscard]] static consteval std::array<std::uint64_t, 64> generate_white_pawn_attacks()
{
    std::array<std::uint64_t, 64> attack_array;
    for (int i = 0; i < 64; ++i) {
        attack_array[i] = (Util::shift_left(1ULL << i) << 8) | (Util::shift_right(1ULL << i) << 8);
    }

    return attack_array;
}

// @Desc: Compile time function to generate the lookup table for black pawn attacks
// @Return: The lookup table

[[nodiscard]] static consteval std::array<std::uint64_t, 64> generate_black_pawn_attacks()
{
    std::array<std::uint64_t, 64> attack_array;
    for (int i = 0; i < 64; ++i) {
        attack_array[i] = (Util::shift_left(1ULL << i) >> 8) | (Util::shift_right(1ULL << i) >> 8);
    }

    return attack_array;
}

// These will be generated at compile time
inline constexpr auto white_attacks = generate_white_pawn_attacks();
inline constexpr auto black_attacks = generate_black_pawn_attacks();
inline constexpr auto knight_table = generate_knight_lookup_table();

[[nodiscard]] constexpr std::uint64_t get_bishop_moves(const std::uint64_t bitboard);
[[nodiscard]] int run(const bool analysis_mode);

}

#endif
