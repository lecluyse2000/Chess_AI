#include "movegen.h"

#include <cstdint>
#include <utility>
#include <vector>

#include "gamestate.h"

using u64 = std::uint64_t;

namespace Movegen
{

[[nodiscard]]  u64 
generate_white_bishop_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces)
{
    u64 position = og_position;
    u64 moves = 0;

    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        const auto diagonal_right = Util::shift_up(shift_right);
        if (!diagonal_right) break;

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
        const auto diagonal_right = Util::shift_down(shift_right);
        if (!diagonal_right) break;

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
        const auto diagonal_left = Util::shift_up(shift_left);
        if (!diagonal_left) break;

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
        const auto diagonal_left = Util::shift_down(shift_left);
        if (!diagonal_left) break;

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

[[nodiscard]]  u64 
generate_black_bishop_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces)
{
    u64 position = og_position;
    u64 moves = 0;

    for (int i = 1; i < 9; ++i) {
        const auto shift_right = Util::shift_right(position);
        const auto diagonal_right = Util::shift_up(shift_right);
        if (!diagonal_right) break;

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
        const auto diagonal_right = Util::shift_down(shift_right);
        if (!diagonal_right) break;

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
        const auto diagonal_left = Util::shift_up(shift_left);
        if (!diagonal_left) break;

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
        const auto diagonal_left = Util::shift_down(shift_left);
        if (!diagonal_left) break;

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
std::vector<std::pair<u64, u64> > get_white_bishop_moves(Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_bishops;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        const u64 current_moves = generate_white_bishop_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces());
        moves.emplace_back(std::make_pair(current_position, current_moves));
        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_black_bishop_moves(Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.black_bishops;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_black_bishop_moves(current_position, 
                                                                      gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]]  u64 
generate_white_rook_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces)
{
    u64 position = og_position;
    u64 moves = 0;

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

[[nodiscard]]  u64 
generate_black_rook_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces)
{
    u64 position = og_position;
    u64 moves = 0;

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
std::vector<std::pair<u64, u64> > get_white_rook_moves(Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_rooks;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_white_rook_moves(current_position, 
                                                                    gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_black_rook_moves(Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.black_rooks;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_black_rook_moves(current_position, 
                                                                    gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] std::vector<std::pair<u64, u64> > get_white_queen_moves(Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_queen;

    while(current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position,
                                            generate_white_rook_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) | 
                                            generate_white_bishop_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces())));
        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] std::vector<std::pair<u64, u64> > get_black_queen_moves(Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_queen;

    while(current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position,
                                            generate_black_rook_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) | 
                                            generate_black_bishop_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces())));
        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

}
