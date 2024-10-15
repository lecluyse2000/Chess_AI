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


namespace Engine
{

// @Param bitboard: A valid bitboard with at least one knight on it 
// @Return: A bitboard with all available knight moves

[[nodiscard]] static constexpr std::uint64_t get_kight_moves(const std::uint64_t bitboard)
{
    const std::uint64_t num_knights = std::popcount(bitboard);
    assert(num_knights == 1 || num_knights == 2);
    std::uint64_t move_board = 0;
    std::array<std::uint64_t, 2> knight_positions = {Util::get_least_sig_bit(bitboard), 0};

    if (num_knights == 2) {
        knight_positions[1] = Util::clear_least_sig_bit(bitboard);
    }

    for (const auto pos : knight_positions) {
        if (!pos) return move_board;

        for (const auto bit_shift : Types::knight_bit_shifts) {
            move_board |= (pos << bit_shift) | (pos >> bit_shift);
        }
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
