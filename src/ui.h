#ifndef UI_H
#define UI_H

#include <cstdint>
#include <optional>
#include <utility>

namespace UI
{


[[nodiscard]] std::optional<bool> get_player_color();
[[nodiscard]] std::optional<std::pair<std::uint64_t, std::uint64_t> > get_player_move();

}

#endif
