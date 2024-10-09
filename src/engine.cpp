#include "engine.h"

#include <optional>
#include "ui.h"

namespace Engine
{

static void normal_mode()
{
    Gamestate current_gamestate;
    const std::optional<bool> player_is_white = UI::get_player_color();
    if (!player_is_white) [[unlikely]] {
        return;
    }
}

[[nodiscard]] int run(const bool analysis_mode)
{

    if (!analysis_mode) {
        normal_mode();
    } 

    return 0;
}

}
