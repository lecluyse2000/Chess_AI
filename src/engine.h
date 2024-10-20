//Author: Caden LeCluyse

#ifndef ENGINE_H
#define ENGINE_H

#include "gamestate.h"

#include <cstdint>
#include <utility>
#include <vector>

namespace Engine
{

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_white_bishop_moves(const Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_black_bishop_moves(const Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_white_rook_moves(const Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_black_rook_moves(const Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_white_queen_moves(const Gamestate& gamestate) noexcept;
[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > get_black_queen_moves(const Gamestate& gamestate) noexcept;

void castle_kingside_white(Gamestate& gamestate);
void castle_queenside_white(Gamestate& gamestate);
void castle_kingside_black(Gamestate& gamestate);
void castle_queenside_black(Gamestate& gamestate);

[[nodiscard]] bool game_is_over(const Gamestate& current_gamestate);
void make_random_move_white(Gamestate& current_gamestate);
void make_random_move_black(Gamestate& current_gamestate);

}

#endif
