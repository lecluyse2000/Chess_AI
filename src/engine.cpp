//Author: Caden LeCluyse

#include "engine.h"

#include "gamestate.h"
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
}

void castle_queenside_white(Gamestate& gamestate)
{
    assert(gamestate.white_can_castle_queenside);
    assert(gamestate.white_rooks & 1ULL);
    gamestate.white_king >>= 2;
    gamestate.white_rooks &= ~1ULL;
    gamestate.white_rooks |= (1ULL >> 3);
}

void castle_kingside_black(Gamestate& gamestate)
{
    assert(gamestate.black_can_castle_kingside);
    assert(gamestate.black_rooks & (1ULL << 63));
    gamestate.black_king <<= 2;
    gamestate.black_rooks &= ~(1ULL << 63);
    gamestate.black_rooks |= (1ULL << 61);
}

void castle_queenside_black(Gamestate& gamestate)
{
    assert(gamestate.black_can_castle_queenside);
    assert(gamestate.black_rooks & (1ULL << 56));
    gamestate.black_king >>= 2;
    gamestate.black_rooks &= ~(1ULL << 56);
    gamestate.black_rooks |= (1ULL << 59);
}

void make_white_pawn_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.white_pawns &= ~og_position;
    gamestate.white_pawns |= new_position;
}

void make_white_knight_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.white_knights &= ~og_position;
    gamestate.white_knights |= new_position;
}

void make_white_bishop_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.white_bishops &= ~og_position;
    gamestate.white_bishops |= new_position;
}

void make_white_rook_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.white_rooks &= ~og_position;
    gamestate.white_rooks |= new_position;
}

void make_white_queen_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.white_queen &= ~og_position;
    gamestate.white_queen |= new_position;
}

void make_black_pawn_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.black_pawns &= ~og_position;
    gamestate.black_pawns |= new_position;
}

void make_black_knight_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.black_knights &= ~og_position;
    gamestate.black_knights |= new_position;
}

void make_black_bishop_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.black_bishops &= ~og_position;
    gamestate.black_bishops |= new_position;
}

void make_black_rook_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.black_rooks &= ~og_position;
    gamestate.black_rooks |= new_position;
}

void make_black_queen_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept
{
    gamestate.black_queen &= ~og_position;
    gamestate.black_queen |= new_position;
}

[[nodiscard]] bool game_is_over(Gamestate& current_gamestate)
{
    if (current_gamestate.white_to_move) {

    } else {

    }
}

} // namespace Engine
