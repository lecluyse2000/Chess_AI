#include "movegen.h"

#include <cstdint>
#include <utility>
#include <vector>

#include "gamestate.h"
#include "util/table.h"

using u64 = std::uint64_t;

namespace Movegen
{

[[nodiscard]]  u64 
generate_white_bishop_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces) noexcept
{
    u64 position = og_position;
    u64 moves = 0;

    for (int i = 1; i < 9; ++i) {
        Util::shift_right(position);
        Util::shift_up(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position & black_pieces) {
            moves |= position;
            break;
        } 

        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_right(position);
        Util::shift_down(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position & black_pieces) {
            moves |= position;
            break;
        } 
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_left(position);
        Util::shift_up(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position & black_pieces) {
            moves |= position;
            break;
        } 
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_left(position);
        Util::shift_down(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position & black_pieces) {
            moves |= position;
            break;
        } 

        moves |= position;
    }

    return moves;
}

[[nodiscard]]  u64 
generate_black_bishop_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces) noexcept
{
    u64 position = og_position;
    u64 moves = 0;

    for (int i = 1; i < 9; ++i) {
        Util::shift_right(position);
        Util::shift_up(position);
        if (!position) break;

        if (position & white_pieces) {
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        }
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_right(position);
        Util::shift_down(position);
        if (!position) break;

        if (position & white_pieces) {
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        } 

        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_left(position);
        Util::shift_up(position);
        if (!position) break;

        if (position & white_pieces) { 
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        }
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_left(position);
        Util::shift_down(position);
        if (!position) break;

        if (position & white_pieces) { 
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        }

        moves |= position;
    }

    return moves;
}

// @Desc: Very clunky and inefficient to find bishops moves until I optimize
// @Return: A vector of key entry pairs, where the key is the position and the entry are the moves

[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_white_bishop_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_bishops;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_white_bishop_moves(current_position, 
                                                                      gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_black_bishop_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.black_bishops;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_black_bishop_moves(current_position, 
                                                                      gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]]  u64 
generate_white_rook_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces) noexcept
{
    u64 position = og_position;
    u64 moves = 0;

    for (int i = 1; i < 9; ++i) {
        Util::shift_right(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position & black_pieces) {
            moves |= position;
            break;
        } 

        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_up(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position & black_pieces) {
            moves |= position;
            break;
        } 
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_left(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position & black_pieces) {
            moves |= position;
            break;
        } 
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_down(position);
        if (!position) break;

        if (position & white_pieces) break;
        else if (position  & black_pieces) {
            moves |= position;
            break;
        } 

        moves |= position;
    }

    return moves;
}

[[nodiscard]]  u64 
generate_black_rook_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces) noexcept
{
    u64 position = og_position;
    u64 moves = 0;

    for (int i = 1; i < 9; ++i) {
        Util::shift_right(position);
        if (!position) break;

        if (position & white_pieces) {
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        }
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_up(position);
        if (!position) break;

        if (position & white_pieces) {
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        } 

        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_left(position);
        if (!position) break;

        if (position & white_pieces) { 
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        }
        
        moves |= position;
    }

    position = og_position;
    for (int i = 1; i < 9; ++i) {
        Util::shift_down(position);
        if (!position) break;

        if (position & white_pieces) { 
            moves |= position;
            break;
        }
        else if (position & black_pieces) {
            break;
        }

        moves |= position;
    }

    return moves;
}

// @Desc: Very clunky and inefficient to find bishops moves until I optimize
// @Return: A vector of key entry pairs, where the key is the position and the entry are the moves

[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_white_rook_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_rooks;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_white_rook_moves(current_position, 
                                                                    gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_black_rook_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.black_rooks;

    while (current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position, 
                                          generate_black_rook_moves(current_position, 
                                                                    gamestate.get_white_pieces(), gamestate.get_black_pieces())));

        Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] std::vector<std::pair<u64, u64> > get_white_queen_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_queen;

    while(current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position,
                                            generate_white_rook_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) | 
                                            generate_white_bishop_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces())));
        Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] std::vector<std::pair<u64, u64> > get_black_queen_moves(const Gamestate& gamestate) noexcept
{
    std::vector<std::pair<u64, u64> > moves;
    u64 current_bitboard = gamestate.white_queen;

    while(current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_position,
                                            generate_black_rook_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) | 
                                            generate_black_bishop_moves(current_position, gamestate.get_white_pieces(), gamestate.get_black_pieces())));
        Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] static u64 get_white_knight_moves(u64 current_bitboard) noexcept
{
    u64 moves = 0;

    while(current_bitboard) {
        const u64 current_position = Util::get_least_sig_bit(current_bitboard);
        moves |= Table::knight_table[current_position];
        Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]] u64 get_all_white_moves(const Gamestate& gamestate) noexcept
{
    const u64 pawn_moves = gamestate.get_white_pawn_moves();
    const u64 knight_moves = get_white_knight_moves(gamestate.white_knights);
    const auto bishop_moves = get_white_bishop_moves(gamestate);
    const auto rook_moves = get_white_rook_moves(gamestate);
    const auto queen_moves = get_white_queen_moves(gamestate);

    u64 retval = 0;

    retval |= Table::king_table[gamestate.white_king] & ~gamestate.get_all_pieces();
    retval |= pawn_moves | knight_moves;
    for (const auto& [pos, move] : bishop_moves) {
        retval |= move;
    }
    for (const auto& [pos, move] : rook_moves) {
        retval |= move;
    }
    for (const auto& [pos, move] : queen_moves) {
        retval |= move;
    }

    return retval;
}

}
