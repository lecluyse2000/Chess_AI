//Author: Caden LeCluyse

#ifndef ENGINE_H
#define ENGINE_H

#include <array>
#include <cstdint>

namespace Engine
{
    inline constexpr std::array<std::uint64_t, 4> knight_bit_shifts = {6, 15, 17, 10};
    [[nodiscard]] int run(const bool analysis_mode);
}

#endif
