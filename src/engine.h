//Author: Caden LeCluyse

#ifndef ENGINE_H
#define ENGINE_H

#include "gamestate.h"

#include <cstdint>

using u64 = std::uint64_t;

namespace Engine
{

void castle_kingside_white(Gamestate& gamestate);
void castle_queenside_white(Gamestate& gamestate);
void castle_kingside_black(Gamestate& gamestate);
void castle_queenside_black(Gamestate& gamestate);
void make_white_pawn_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_white_knight_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_white_bishop_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_white_rook_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_white_queen_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_black_pawn_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_black_knight_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_black_bishop_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_black_rook_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;
void make_black_queen_move(Gamestate& gamestate, const u64 og_position, const u64 new_position) noexcept;

[[nodiscard]] bool game_is_over(const Gamestate& current_gamestate);
void make_random_move_white(Gamestate& current_gamestate);
void make_random_move_black(Gamestate& current_gamestate);

}

#endif
