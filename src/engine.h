//Author: Caden LeCluyse

#ifndef ENGINE_H
#define ENGINE_H

#include "gamestate.h"

#include <cstdint>
#include <utility>
#include <vector>

using u64 = std::uint64_t;

namespace Engine
{

[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_white_bishop_moves(Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_black_bishop_moves(Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_white_rook_moves(Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_black_rook_moves(Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_white_queen_moves(Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<u64, u64> > get_black_queen_moves(Gamestate& gamestate) noexcept;

void castle_kingside_white(Gamestate& gamestate);
void castle_queenside_white(Gamestate& gamestate);
void castle_kingside_black(Gamestate& gamestate);
void castle_queenside_black(Gamestate& gamestate);

[[nodiscard]] bool game_is_over(const Gamestate& current_gamestate);
void make_random_move_white(Gamestate& current_gamestate);
void make_random_move_black(Gamestate& current_gamestate);

}

#endif
