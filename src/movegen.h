#ifndef MOVEGEN_H
#define MOVEGEN_H

#include <cstdint>
#include <utility>
#include <vector>

#include "gamestate.h"

using u64 = std::uint64_t;

namespace Movegen
{

[[nodiscard]] u64
generate_white_bishop_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces);
[[nodiscard]]  u64 
generate_black_bishop_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces);
[[nodiscard]]  u64 
generate_white_rook_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces);
[[nodiscard]]  u64 
generate_black_rook_moves(const u64 og_position, const u64 white_pieces, const u64 black_pieces);

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

}

#endif
