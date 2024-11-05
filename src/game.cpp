#include "game.h"

#include <cstdint>

#include "engine.h"
#include "gamestate.h"
#include "movegen.h"
#include "ui.h"

using u64 = std::uint64_t;

namespace Game
{

static void make_ai_move_white()
{

}

static void make_ai_move_black()
{

}

static void white_move(Gamestate& current_gamestate, const bool player_is_white)
{
    if (!player_is_white) {
        make_ai_move_white();
        current_gamestate.white_to_move = false;
        return;
    }
    current_gamestate.white_to_move = false;
}

static void black_move(Gamestate& current_gamestate, const bool player_is_white)
{
    if (player_is_white) {
        make_ai_move_black();
        current_gamestate.white_to_move = true;
        return;
    }
    current_gamestate.white_to_move = true;
}

[[nodiscard]] static int game_loop(const bool player_is_white)
{
    Gamestate current_gamestate;

    while (!Engine::game_is_over(current_gamestate)) {
        if (current_gamestate.white_to_move) {
            white_move(current_gamestate, player_is_white);
        } else {
            black_move(current_gamestate, player_is_white);
        }
    }

    return 0;
}

int start_game_mode()
{
    const std::optional<bool> player_is_white = UI::get_player_color();
    if (!player_is_white) return 1;
    return game_loop(*player_is_white);
}

}
