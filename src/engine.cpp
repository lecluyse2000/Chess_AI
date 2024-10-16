//Author: Caden LeCluyse

#include "engine.h"

#include <cassert>
#include "gamestate.h"
#include <optional>
#include "ui.h"


namespace Engine
{

static inline void game_mode()
{
    const std::optional<const bool> player_is_white = UI::get_player_color();
    if (!player_is_white) [[unlikely]] return;
}

[[nodiscard]] int run(const bool analysis_mode)
{
    constexpr Gamestate current_gamestate;
    if (!analysis_mode) {
        game_mode();
    } 

    return 0;
}

} // namespace Engine
