//Author: Caden LeCluyse

#include "engine.h"

#include "gamestate.h"
#include "movegen.h"
#include "table.h"
#include "util/util.h"

#include <cassert>
#include <cstdint>

using u64 = std::uint64_t;

namespace Engine
{

void castle_kingside_white(Gamestate& gamestate)
{
    assert(gamestate.white_can_castle_kingside);
    assert(gamestate.white_rooks & (1ULL << 7));
    gamestate.white_king <<= 2;
    gamestate.white_rooks &= ~(1ULL << 7);
    gamestate.white_rooks |= (1ULL << 5);
    gamestate.white_can_castle_kingside = false;
    gamestate.white_can_castle_queenside = false;
    if (Movegen::generate_white_rook_moves(1ULL << 5, gamestate.get_white_pieces(), gamestate.get_black_pieces()) &
        gamestate.black_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void castle_queenside_white(Gamestate& gamestate)
{
    assert(gamestate.white_can_castle_queenside);
    assert(gamestate.white_rooks & 1ULL);
    gamestate.white_king >>= 2;
    gamestate.white_rooks &= ~1ULL;
    gamestate.white_rooks |= (1ULL << 3);
    gamestate.white_can_castle_kingside = false;
    gamestate.white_can_castle_queenside = false;
    if (Movegen::generate_white_rook_moves(1ULL << 3, gamestate.get_white_pieces(), gamestate.get_black_pieces()) &
        gamestate.black_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void castle_kingside_black(Gamestate& gamestate)
{
    assert(gamestate.black_can_castle_kingside);
    assert(gamestate.black_rooks & (1ULL << 63));
    gamestate.black_king <<= 2;
    gamestate.black_rooks &= ~(1ULL << 63);
    gamestate.black_rooks |= (1ULL << 61);
    gamestate.black_can_castle_kingside = false;
    gamestate.black_can_castle_queenside = false;
    if (Movegen::generate_white_rook_moves(1ULL << 61, gamestate.get_white_pieces(), gamestate.get_black_pieces()) &
        gamestate.white_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void castle_queenside_black(Gamestate& gamestate)
{
    assert(gamestate.black_can_castle_queenside);
    assert(gamestate.black_rooks & (1ULL << 56));
    gamestate.black_king >>= 2;
    gamestate.black_rooks &= ~(1ULL << 56);
    gamestate.black_rooks |= (1ULL << 59);
    gamestate.black_can_castle_kingside = false;
    gamestate.black_can_castle_queenside = false;
    if (Movegen::generate_white_rook_moves(1ULL << 59, gamestate.get_white_pieces(), gamestate.get_black_pieces()) &
        gamestate.white_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_white_pawn_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.white_pawns);
    gamestate.white_pawns &= ~og_position;
    gamestate.white_pawns |= new_position;
    if (Table::white_pawn_attacks[new_position] & gamestate.black_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_white_knight_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.white_knights);
    gamestate.white_knights &= ~og_position;
    gamestate.white_knights |= new_position;
    if (Table::knight_table[new_position] & gamestate.black_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_white_bishop_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.white_bishops);
    gamestate.white_bishops &= ~og_position;
    gamestate.white_bishops |= new_position;
    if (Movegen::generate_white_bishop_moves(new_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) &
        gamestate.black_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_white_rook_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.white_rooks);
    gamestate.white_rooks &= ~og_position;
    gamestate.white_rooks |= new_position;
    if (Movegen::generate_white_rook_moves(new_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) &
        gamestate.black_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_white_queen_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.white_queen);
    gamestate.white_queen &= ~og_position;
    gamestate.white_queen |= new_position;
    if ((Movegen::generate_white_rook_moves(new_position, gamestate.get_white_pieces(), gamestate.get_black_pieces()) |
         Movegen::generate_white_bishop_moves(new_position, gamestate.get_white_pieces(), gamestate.get_black_pieces())) &
         gamestate.black_king) {

        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_black_pawn_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.black_pawns);
    gamestate.black_pawns &= ~og_position;
    gamestate.black_pawns |= new_position;
    if (Table::black_pawn_attacks[new_position] & gamestate.white_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_black_knight_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.black_knights);
    gamestate.black_knights &= ~og_position;
    gamestate.black_knights |= new_position;
    if (Table::knight_table[new_position] & gamestate.white_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_black_bishop_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.black_bishops);
    gamestate.black_bishops &= ~og_position;
    gamestate.black_bishops |= new_position;
    if (Movegen::generate_black_bishop_moves(new_position, gamestate.get_black_pieces(), gamestate.get_black_pieces()) &
        gamestate.white_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

void make_black_rook_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.black_rooks);
    gamestate.black_rooks &= ~og_position;
    gamestate.black_rooks |= new_position;
    if (Movegen::generate_black_rook_moves(new_position, gamestate.get_black_pieces(), gamestate.get_black_pieces()) &
        gamestate.white_king) {
        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;    
    }
}

void make_black_queen_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    assert(gamestate.black_queen);
    gamestate.black_queen &= ~og_position;
    gamestate.black_queen |= new_position;
    if ((Movegen::generate_black_rook_moves(new_position, gamestate.get_black_pieces(), gamestate.get_black_pieces()) |
         Movegen::generate_black_bishop_moves(new_position, gamestate.get_black_pieces(), gamestate.get_black_pieces())) &
         gamestate.white_king) {

        gamestate.is_check = true;
    } else {
        gamestate.is_check = false;
    }
}

[[nodiscard]] bool game_is_over(Gamestate& current_gamestate)
{
    if (current_gamestate.white_to_move) {

    } else {

    }
}

} // namespace Engine
