#ifndef TABLE_H
#define TABLE_H

#include <array>
#include "util.h"

namespace Table
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

[[nodiscard]] static consteval std::array<std::uint64_t, 64> generate_king_moves()
{
    std::array<std::uint64_t, 64> king_moves;
    for (int i = 0; i < 64; ++i) {
        king_moves[i] = (Util::shift_left(1ULL << i) >> 8) | (Util::shift_right(1ULL << i) >> 8);
        king_moves[i] |= (Util::shift_left(1ULL << i) << 8) | (Util::shift_right(1ULL << i) << 8);
        king_moves[i] |= Util::shift_left(1ULL << i) | Util::shift_right(1ULL << i);
        king_moves[i] |= Util::shift_up(1ULL << i) | Util::shift_up(1ULL << i);
    }

    return king_moves;
}

// These will be generated at compile time
inline constexpr auto knight_table = generate_knight_lookup_table();
inline constexpr auto white_pawn_attacks = generate_white_pawn_attacks();
inline constexpr auto black_pawn_attacks = generate_black_pawn_attacks();
inline constexpr auto king_table = generate_king_moves();

} // namespace Table

#endif
