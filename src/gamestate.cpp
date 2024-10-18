//Author: Caden LeCluyse

#include "gamestate.h"
#include "util.h"

#include <cstdint>
#include <utility>
#include <vector>

[[nodiscard]] static std::uint64_t 
generate_white_bishop_moves(const std::uint64_t og_position, const std::uint64_t white_pieces, const std::uint64_t black_pieces)
{
    std::uint64_t position = og_position;
    std::uint64_t moves = 0;

    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        if (!shift_right) break;
        const auto diagonal_right = Util::shift_up(shift_right);

        if (diagonal_right & white_pieces) break;
        else if (diagonal_right & black_pieces) {
            moves |= diagonal_right;
            break;
        } 

        moves |= diagonal_right;
        position = diagonal_right;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        if (!shift_right) break;
        const auto diagonal_right = Util::shift_down(shift_right);

        if (diagonal_right & white_pieces) break;
        else if (diagonal_right & black_pieces) {
            moves |= diagonal_right;
            break;
        } 
        
        moves |= diagonal_right;
        position = diagonal_right;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_left = Util::shift_left(position);
        if (!shift_left) break;
        const auto diagonal_left = Util::shift_up(shift_left);

        if (diagonal_left & white_pieces) break;
        else if (diagonal_left & black_pieces) {
            moves |= diagonal_left;
            break;
        } 
        
        moves |= diagonal_left;
        position = diagonal_left;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_left = Util::shift_left(position);
        if (!shift_left) break;
        const auto diagonal_left = Util::shift_down(shift_left);

        if (diagonal_left & white_pieces) break;
        else if (diagonal_left & black_pieces) {
            moves |= diagonal_left;
            break;
        } 

        moves |= diagonal_left;
        position = diagonal_left;
    }

    return moves & ~og_position;
}

[[nodiscard]] static std::uint64_t 
generate_black_bishop_moves(const std::uint64_t og_position, const std::uint64_t white_pieces, const std::uint64_t black_pieces)
{
    std::uint64_t position = og_position;
    std::uint64_t moves = 0;

    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        if (!shift_right) break;
        const auto diagonal_right = Util::shift_up(shift_right);

        if (diagonal_right & white_pieces) {
            moves |= diagonal_right;
            break;
        }
        else if (diagonal_right & black_pieces) {
            break;
        }
        
        moves |= diagonal_right;
        position = diagonal_right;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        if (!shift_right) break;
        const auto diagonal_right = Util::shift_down(shift_right);

        if (diagonal_right & white_pieces) {
            moves |= diagonal_right;
            break;
        }
        else if (diagonal_right & black_pieces) {
            break;
        } 

        moves |= diagonal_right;
        position = diagonal_right;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_left = Util::shift_left(position);
        if (!shift_left) break;
        const auto diagonal_left = Util::shift_up(shift_left);

        if (diagonal_left & white_pieces) { 
            moves |= diagonal_left;
            break;
        }
        else if (diagonal_left & black_pieces) {
            break;
        }
        
        moves |= diagonal_left;
        position = diagonal_left;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_left = Util::shift_left(position);
        if (!shift_left) break;
        const auto diagonal_left = Util::shift_down(shift_left);

        if (diagonal_left & white_pieces) { 
            moves |= diagonal_left;
            break;
        }
        else if (diagonal_left & black_pieces) {
            break;
        }

        moves |= diagonal_left;
        position = diagonal_left;
    }

    return moves & ~og_position;
}

// @Desc: Very clunky and inefficient to find bishops moves until I optimize
// @Return: A vector of key entry pairs, where the key is the position and the entry are the moves

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > Gamestate::get_white_bishop_moves() const noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = white_bishops;

    while (current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_white_bishop_moves(current_position, get_white_pieces(), get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > Gamestate::get_black_bishop_moves() const noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = black_bishops;

    while (current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_black_bishop_moves(current_position, get_white_pieces(), get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}
