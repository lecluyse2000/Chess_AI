//Author: Caden LeCluyse

#include "gamestate.h"
#include <cstdint>

// @Return: A bitboard of all white pieces

[[nodiscard]] inline constexpr std::uint64_t Gamestate::get_white_pieces()
{
    return white_king |
           white_queen |
           white_rooks |
           white_knights |
           white_bishops |
           pawns.white_pawns;
}

// @Return: A bitboard of all black pieces

[[nodiscard]] inline constexpr std::uint64_t Gamestate::get_black_pieces()
{
    return black_king |
           black_queen |
           black_rooks |
           black_knights |
           black_bishops |
           pawns.black_pawns;
}

// @Return: A bitboard of all pieces

[[nodiscard]] inline constexpr std::uint64_t Gamestate::get_all_pieces()
{
    return get_white_pieces() | get_black_pieces();
}
