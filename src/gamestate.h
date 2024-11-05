//Author: Caden LeCluyse

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdint>
#include "util/table.h"
#include "util/types.h"
#include "util/util.h"

using u64 = std::uint64_t;

struct Gamestate
{
        // @Desc: Default constructor for gamestate that initializes each piece to their proper position, as well as castling.
        constexpr Gamestate() noexcept : 
            white_can_castle_kingside(true),
            white_can_castle_queenside(true),
            black_can_castle_kingside(true),
            black_can_castle_queenside(true),
            white_to_move(true),
            is_check(false),
            en_passant(false),
            white_pawns(Types::Start::white_pawns_start),
            white_rooks(Types::Start::white_rooks_start), 
            white_knights(Types::Start::white_knights_start),
            white_bishops(Types::Start::white_bishops_start),
            white_queen(Types::Start::white_queen_start),
            white_king(Types::Start::white_king_start),
            black_pawns(Types::Start::black_pawns_start),
            black_rooks(Types::Start::black_rooks_start),
            black_knights(Types::Start::black_knights_start),
            black_bishops(Types::Start::black_bishops_start),
            black_queen(Types::Start::black_queen_start),
            black_king(Types::Start::black_king_start)
        {}

        bool white_can_castle_kingside;
        bool white_can_castle_queenside;
        bool black_can_castle_kingside;
        bool black_can_castle_queenside;
        bool white_to_move;
        bool is_check;
        bool en_passant;

        u64 white_pawns;
        u64 white_rooks;
        u64 white_knights;
        u64 white_bishops;
        u64 white_queen;
        u64 white_king;

        u64 black_pawns;
        u64 black_rooks;
        u64 black_knights;
        u64 black_bishops;
        u64 black_queen;
        u64 black_king;

        // @Return: A bitboard of all white pieces

        [[nodiscard]] inline constexpr u64 get_white_pieces() const noexcept
        {
            return white_king |
                   white_queen |
                   white_rooks |
                   white_knights |
                   white_bishops |
                   white_pawns;
        }

        // @Return: A bitboard of all black pieces

        [[nodiscard]] inline constexpr u64 get_black_pieces() const noexcept
        {
            return black_king |
                   black_queen |
                   black_rooks |
                   black_knights |
                   black_bishops |
                   black_pawns;
        }

        // @Return: A bitboard of all pieces

        [[nodiscard]] inline constexpr u64 get_all_pieces() const noexcept
        {
            return get_white_pieces() | get_black_pieces();
        }

        // @Return: A bitboard of all white pawn moves 

        [[nodiscard]] inline constexpr u64 get_white_pawn_moves() const noexcept
        {
            u64 current_bitboard = white_pawns;
            u64 moves = 0;
            
            while (current_bitboard) {
                const u64 current_bit = Util::get_least_sig_bit(current_bitboard);
                moves |= Table::white_pawn_attacks[current_bit] & get_black_pieces();
                moves |= (current_bit & Types::rank_2) ? (current_bit << 8 | current_bit << 16) & ~get_all_pieces()
                                                       : (current_bit << 8) & ~get_all_pieces();

                current_bitboard = Util::clear_least_sig_bit(current_bitboard);
            }
            
            return moves;
        }

        // @Return: A bitboard of all black pawn moves 
    
        [[nodiscard]] inline constexpr u64 get_black_pawn_moves() const noexcept
        {
            u64 current_bitboard = black_pawns;
            u64 moves = 0;
            
            while (current_bitboard) {
                const u64 current_bit = Util::get_least_sig_bit(current_bitboard);
                moves |= Table::black_pawn_attacks[current_bit] & get_white_pieces();
                moves |= (current_bit & Types::rank_7) ? (current_bit >> 8 | current_bit >> 16) & ~get_all_pieces()
                                                       : (current_bit >> 8) & ~get_all_pieces();

                current_bitboard = Util::clear_least_sig_bit(current_bitboard);
            }
            
            return moves;
        }
};

#endif
