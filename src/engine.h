//Author: Caden LeCluyse

#ifndef ENGINE_H
#define ENGINE_H

#include <cstdint>

namespace Engine
{

[[nodiscard]] constexpr std::uint64_t get_bishop_moves(const std::uint64_t bitboard);
[[nodiscard]] int run(const bool analysis_mode);

}

#endif
