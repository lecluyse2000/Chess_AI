//Author: Caden LeCluyse

#include "engine.h"

#include "gamestate.h"
#include "util.h"

#include <cassert>
#include <cstdint>
#include <utility>
#include <vector>

namespace Engine
{

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

    return moves;
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

    return moves;
}

// @Desc: Very clunky and inefficient to find bishops moves until I optimize
// @Return: A vector of key entry pairs, where the key is the position and the entry are the moves

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_white_bishop_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = gamestate.white_bishops;

    while (current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_white_bishop_moves(current_position, 
                                          gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_black_bishop_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = gamestate.black_bishops;

    while (current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_black_bishop_moves(current_position, 
                                                                      gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] static std::uint64_t 
generate_white_rook_moves(const std::uint64_t og_position, const std::uint64_t white_pieces, const std::uint64_t black_pieces)
{
    std::uint64_t position = og_position;
    std::uint64_t moves = 0;

    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        if (!shift_right) break;

        if (shift_right & white_pieces) break;
        else if (shift_right & black_pieces) {
            moves |= shift_right;
            break;
        } 

        moves |= shift_right;
        position = shift_right;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_up = Util::shift_up(position);
        if (!shift_up) break;

        if (shift_up & white_pieces) break;
        else if (shift_up & black_pieces) {
            moves |= shift_up;
            break;
        } 
        
        moves |= shift_up;
        position = shift_up;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_left = Util::shift_left(position);
        if (!shift_left) break;

        if (shift_left & white_pieces) break;
        else if (shift_left & black_pieces) {
            moves |= shift_left;
            break;
        } 
        
        moves |= shift_left;
        position = shift_left;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_down = Util::shift_down(position);
        if (!shift_down) break;

        if (shift_down & white_pieces) break;
        else if (shift_down & black_pieces) {
            moves |= shift_down;
            break;
        } 

        moves |= shift_down;
        position = shift_down;
    }

    return moves;
}

[[nodiscard]] static std::uint64_t 
generate_black_rook_moves(const std::uint64_t og_position, const std::uint64_t white_pieces, const std::uint64_t black_pieces)
{
    std::uint64_t position = og_position;
    std::uint64_t moves = 0;

    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        if (!shift_right) break;

        if (shift_right & white_pieces) {
            moves |= shift_right;
            break;
        }
        else if (shift_right & black_pieces) {
            break;
        }
        
        moves |= shift_right;
        position = shift_right;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_up = Util::shift_up(position);
        if (!shift_up) break;

        if (shift_up & white_pieces) {
            moves |= shift_up;
            break;
        }
        else if (shift_up & black_pieces) {
            break;
        } 

        moves |= shift_up;
        position = shift_up;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_left = Util::shift_left(position);
        if (!shift_left) break;

        if (shift_left & white_pieces) { 
            moves |= shift_left;
            break;
        }
        else if (shift_left & black_pieces) {
            break;
        }
        
        moves |= shift_left;
        position = shift_left;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        const auto shift_down = Util::shift_down(position);
        if (!shift_down) break;

        if (shift_down & white_pieces) { 
            moves |= shift_down;
            break;
        }
        else if (shift_down & black_pieces) {
            break;
        }

        moves |= shift_down;
        position = shift_down;
    }

    return moves;
}

// @Desc: Very clunky and inefficient to find bishops moves until I optimize
// @Return: A vector of key entry pairs, where the key is the position and the entry are the moves

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_white_rook_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = gamestate.white_rooks;

    while (current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_white_rook_moves(current_position, 
                                                                    gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_black_rook_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = gamestate.black_rooks;

    while (current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_black_rook_moves(current_position, 
                                                                    gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] std::vector<std::pair<std::uint64_t, std::uint64_t> > get_white_queen_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = gamestate.white_queen;

    while(current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position,
                                            generate_white_rook_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) | 
                                            generate_white_bishop_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces())));
        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] std::vector<std::pair<std::uint64_t, std::uint64_t> > get_black_queen_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = gamestate.white_queen;

    while(current_bitboard) {
        const std::uint64_t current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position,
                                            generate_black_rook_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) | 
                                            generate_black_bishop_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces())));
        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

void castle_kingside_white(Gamestate& gamestate)
{
    assert(gamestate.white_can_castle_kingside);
    assert(gamestate.white_rooks & (1ULL << 7));
    gamestate.white_king = gamestate.white_king << 2;
    gamestate.white_rooks &= ~(1ULL << 7);
    gamestate.white_rooks |= (1ULL << 5);
}

void castle_queenside_white(Gamestate& gamestate)
{
    assert(gamestate.white_can_castle_queenside);
    assert(gamestate.white_rooks & 1ULL);
    gamestate.white_king = gamestate.white_king >> 2;
    gamestate.white_rooks &= ~1ULL;
    gamestate.white_rooks |= (1ULL >> 3);
}

void castle_kingside_black(Gamestate& gamestate)
{
    assert(gamestate.black_can_castle_kingside);
    assert(gamestate.black_rooks & (1ULL << 63));
    gamestate.black_king = gamestate.black_king << 2;
    gamestate.black_rooks &= ~(1ULL << 63);
    gamestate.black_rooks |= (1ULL << 61);
}

void castle_queenside_black(Gamestate& gamestate)
{
    assert(gamestate.black_can_castle_queenside);
    assert(gamestate.black_rooks & (1ULL << 56));
    gamestate.black_king = gamestate.black_king >> 2;
    gamestate.black_rooks &= ~(1ULL << 56);
    gamestate.black_rooks |= (1ULL << 59);
}

[[nodiscard]] bool game_is_over(const Gamestate& current_gamestate)
{

}

void make_random_move_white(Gamestate& current_gamestate)
{

}

void make_random_move_black(Gamestate& current_gamestate)
{

}

} // namespace Engine
