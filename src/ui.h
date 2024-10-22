//Author: Caden LeCluyse

#ifndef UI_H
#define UI_H

#include <cstdint>
#include <optional>
#include <utility>

using u64 = std::uint64_t;

namespace UI
{

[[nodiscard]] std::optional<bool> get_player_color();
[[nodiscard]] std::optional<std::pair<u64, u64> > get_player_move();

}

#endif
