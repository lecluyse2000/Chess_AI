//Author: Caden LeCluyse

#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

using u64 = std::uint64_t;

namespace Types
{

//constexpr bit masks for bit manipulation

inline constexpr u64 rank_1 = 0x00000000000000FFULL;
inline constexpr u64 rank_2 = 0x000000000000FF00ULL;
inline constexpr u64 rank_3 = 0x0000000000FF0000ULL;
inline constexpr u64 rank_4 = 0x00000000FF000000ULL;
inline constexpr u64 rank_5 = 0x000000FF00000000ULL;
inline constexpr u64 rank_6 = 0x0000FF0000000000ULL;
inline constexpr u64 rank_7 = 0x00FF000000000000ULL;
inline constexpr u64 rank_8 = 0xFF00000000000000ULL;
inline constexpr u64 file_a = 0x0101010101010101ULL;
inline constexpr u64 file_b = 0x0202020202020202ULL;
inline constexpr u64 file_c = 0x0404040404040404ULL;
inline constexpr u64 file_d = 0x0808080808080808ULL;
inline constexpr u64 file_e = 0x1010101010101010ULL;
inline constexpr u64 file_f = 0x2020202020202020ULL;
inline constexpr u64 file_g = 0x4040404040404040ULL;
inline constexpr u64 file_h = 0x8080808080808080ULL;
inline constexpr u64 main_diagonal = 0x8040201008040201ULL;
inline constexpr u64 light_squares = 0x55AA55AA55AA55AAULL;
inline constexpr u64 dark_squares = 0xAA55AA55AA55AA55ULL;

namespace Start
{

inline constexpr u64 white_pawns_start = 0x000000000000FF00ULL;
inline constexpr u64 white_rooks_start = 0x0000000000000081ULL;
inline constexpr u64 white_knights_start = 0x0000000000000042ULL;
inline constexpr u64 white_bishops_start = 0x0000000000000024ULL;
inline constexpr u64 white_queen_start = 0x0000000000000010ULL;
inline constexpr u64 white_king_start = 0x0000000000000008ULL;
inline constexpr u64 black_pawns_start = 0x00FF000000000000ULL;
inline constexpr u64 black_rooks_start = 0x8100000000000000ULL;
inline constexpr u64 black_knights_start = 0x4200000000000000ULL;
inline constexpr u64 black_bishops_start = 0x2400000000000000ULL;
inline constexpr u64 black_queen_start = 0x0800000000000000ULL;
inline constexpr u64 black_king_start = 0x1000000000000000ULL;

}

enum class Piece : int
{

    BL_ROOK, BL_KNIGHT, BL_BISHOP, BL_QUEEN, BL_KING,
    WH_ROOK, WH_KNIGHT, WH_BISHOP, WH_QUEEN, WH_KING

};

enum class Square : int
{
    A1_SQ, B1_SQ, C1_SQ, D1_SQ, E1_SQ, F1_SQ, G1_SQ, H1_SQ,
    A2_SQ, B2_SQ, C2_SQ, D2_SQ, E2_SQ, F2_SQ, G2_SQ, H2_SQ,
    A3_SQ, B3_SQ, C3_SQ, D3_SQ, E3_SQ, F3_SQ, G3_SQ, H3_SQ,
    A4_SQ, B4_SQ, C4_SQ, D4_SQ, E4_SQ, F4_SQ, G4_SQ, H4_SQ,
    A5_SQ, B5_SQ, C5_SQ, D5_SQ, E5_SQ, F5_SQ, G5_SQ, H5_SQ,
    A6_SQ, B6_SQ, C6_SQ, D6_SQ, E6_SQ, F6_SQ, G6_SQ, H6_SQ,
    A7_SQ, B7_SQ, C7_SQ, D7_SQ, E7_SQ, F7_SQ, G7_SQ, H7_SQ,
    A8_SQ, B8_SQ, C8_SQ, D8_SQ, E8_SQ, F8_SQ, G8_SQ, H8_SQ,

    NUM_SQ = 64
};

} // namespace Types

#endif
