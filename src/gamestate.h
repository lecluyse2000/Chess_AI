#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdint>
#include "pawns.h"

class Gamestate
{
    public:
        Gamestate();
        bool white_can_castle_kingside;
        bool white_can_castle_queenside;
        bool black_can_castle_kingside;
        bool black_can_castle_queenside;
        bool white_to_move;

        std::uint64_t white_rooks;
        std::uint64_t white_knights;
        std::uint64_t white_bishops;
        std::uint64_t white_queen;
        std::uint64_t white_king;
        Pawns white_pawns;

        std::uint64_t black_rooks;
        std::uint64_t black_knights;
        std::uint64_t black_bishops;
        std::uint64_t black_queen;
        std::uint64_t black_king;
        Pawns black_pawns;
        
    private:
};

#endif
