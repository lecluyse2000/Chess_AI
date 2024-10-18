//Author: Caden LeCluyse

#include "gamestate.h"

[[nodiscard]] 
std::vector<std::pair<std::uint64_t, std::uint64_t> > Gamestate::get_white_knight_moves() const noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = white_knights; 
    
    while (current_bitboard) {
        const auto current_knight = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_knight, Table::knight_table[current_knight] & ~get_white_pieces()));
        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}

[[nodiscard]]
std::vector<std::pair<std::uint64_t, std::uint64_t> > Gamestate::get_black_knight_moves() const noexcept
{
    std::vector<std::pair<std::uint64_t, std::uint64_t> > moves;
    std::uint64_t current_bitboard = black_knights; 
    
    while (current_bitboard) {
        const auto current_knight = Util::get_least_sig_bit(current_bitboard);
        moves.emplace_back(std::make_pair(current_knight, Table::knight_table[current_knight] & ~get_black_pieces()));
        current_bitboard = Util::clear_least_sig_bit(current_bitboard);
    }

    return moves;
}
