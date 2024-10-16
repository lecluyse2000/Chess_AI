//Author: Caden LeCluyse

#include "engine.h"

#include <array>
#include <bit>
#include <cassert>
#include <cstdint>
#include "gamestate.h"
#include <optional>
#include "ui.h"
#include "util.h"
#include <iostream>


namespace Engine
{

// @Param bitboard: A valid bitboard with at least one knight on it 
// @Return: A bitboard with all available knight moves

[[nodiscard]] static constexpr std::uint64_t get_kight_moves(const std::uint64_t bitboard)
{
    const std::uint64_t num_knights = std::popcount(bitboard);
    assert(num_knights == 1 || num_knights == 2);
    std::uint64_t move_board = 0;
    const std::array<const std::uint64_t, 2> knight_positions = {Util::get_least_sig_bit(bitboard),
                                                                (num_knights == 2) ? Util::clear_least_sig_bit(bitboard) : 0};

    for (const auto pos : knight_positions) {
        if (!pos) return move_board;

        // I hope with inlining and optimizations all this will be properly optimized
        move_board |= (Util::shift_left(pos) | Util::shift_right(pos)) << 16;
        move_board |= (Util::shift_left(pos) | Util::shift_right(pos)) >> 16;
        move_board |= (Util::shift_left(Util::shift_left(pos)) | Util::shift_right(Util::shift_right(pos))) << 8;
        move_board |= (Util::shift_left(Util::shift_left(pos)) | Util::shift_right(Util::shift_right(pos))) >> 8;
    }

    return move_board;
}

static inline void game_mode()
{
    Gamestate current_gamestate;
    const std::optional<const bool> player_is_white = UI::get_player_color();
    if (!player_is_white) [[unlikely]] return;
}

[[nodiscard]] int run(const bool analysis_mode)
{
    if (!analysis_mode) {
        game_mode();
    } 

    return 0;
}

} // namespace Engine
