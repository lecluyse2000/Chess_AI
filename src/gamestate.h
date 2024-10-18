//Author: Caden LeCluyse

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <bit>
#include <cstdint>
#include "table.h"
#include "util.h"

struct Gamestate
{
        // @Desc: Default constructor for gamestate that initializes each piece to their proper position, as well as castling.
        constexpr Gamestate() noexcept : 
            white_can_castle_kingside(false),
            white_can_castle_queenside(false),
            black_can_castle_kingside(false),
            black_can_castle_queenside(false),
            white_to_move(true),
            white_pawns(0x000000000000FF00ULL),
            white_rooks(0x0000000000000081ULL),
            white_knights(0x0000000000000042ULL),
            white_bishops(0x0000000000000024ULL),
            white_queen(0x0000000000000010ULL),
            white_king(0x0000000000000008ULL),
            black_pawns(0x00FF000000000000ULL),
            black_rooks(0x8100000000000000ULL),
            black_knights(0x4200000000000000ULL),
            black_bishops(0x2400000000000000ULL),
            black_queen(0x0800000000000000ULL),
            black_king(0x1000000000000000ULL)
        {}

        bool white_can_castle_kingside;
        bool white_can_castle_queenside;
        bool black_can_castle_kingside;
        bool black_can_castle_queenside;
        bool white_to_move;

        std::uint64_t white_pawns;
        std::uint64_t white_rooks;
        std::uint64_t white_knights;
        std::uint64_t white_bishops;
        std::uint64_t white_queen;
        std::uint64_t white_king;

        std::uint64_t black_pawns;
        std::uint64_t black_rooks;
        std::uint64_t black_knights;
        std::uint64_t black_bishops;
        std::uint64_t black_queen;
        std::uint64_t black_king;


        // @Return: A bitboard of all white pieces

        [[nodiscard]] inline constexpr std::uint64_t get_white_pieces()
        {
            return white_king |
                   white_queen |
                   white_rooks |
                   white_knights |
                   white_bishops |
                   white_pawns;
        }

        // @Return: A bitboard of all black pieces

        [[nodiscard]] inline constexpr std::uint64_t get_black_pieces()
        {
            return black_king |
                   black_queen |
                   black_rooks |
                   black_knights |
                   black_bishops |
                   black_pawns;
        }

        // @Return: A bitboard of all pieces

        [[nodiscard]] inline constexpr std::uint64_t get_all_pieces()
        {
            return get_white_pieces() | get_black_pieces();
        }

        [[nodiscard]] inline constexpr std::uint64_t get_white_pawn_moves()
        {
            std::uint64_t current_bitboard = white_pawns;
            std::uint64_t current_bit = Util::get_least_sig_bit(current_bitboard);
            std::uint64_t moves = 0;
            
            while (current_bitboard) {
                moves |= Table::white_pawn_attacks[current_bit] & get_black_pieces();
                moves |= (current_bit & Types::rank_2) ? (current_bit << 8 | current_bit << 16) & ~get_all_pieces()
                                                       : (current_bit << 8) & ~get_all_pieces();

                current_bitboard = Util::clear_least_sig_bit(current_bitboard);
                current_bit = Util::get_least_sig_bit(current_bitboard);
            }
            
            return moves;
        }

        [[nodiscard]] inline constexpr std::uint64_t get_black_pawn_moves()
        {
            std::uint64_t current_bitboard = black_pawns;
            std::uint64_t current_bit = Util::get_least_sig_bit(current_bitboard);
            std::uint64_t moves = 0;
            
            while (current_bitboard) {
                moves |= Table::black_pawn_attacks[current_bit] & get_white_pieces();
                moves |= (current_bit & Types::rank_7) ? (current_bit >> 8 | current_bit >> 16) & ~get_all_pieces()
                                                       : (current_bit >> 8) & ~get_all_pieces();

                current_bitboard = Util::clear_least_sig_bit(current_bitboard);
                current_bit = Util::get_least_sig_bit(current_bitboard);
            }
            
            return moves;
        }
};

#endif
