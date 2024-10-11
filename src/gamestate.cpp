#include "gamestate.h"

Gamestate::Gamestate() : 
        white_can_castle_kingside(false),
        white_can_castle_queenside(false),
        black_can_castle_kingside(false),
        black_can_castle_queenside(false),
        white_to_move(true),
        white_rooks(0x0000000000000081),
        white_knights(0x0000000000000042),
        white_bishops(0x0000000000000024),
        white_queen(0x0000000000000010),
        white_king(0x0000000000000008),
        black_rooks(0x8100000000000000),
        black_knights(0x4200000000000000),
        black_bishops(0x2400000000000000),
        black_queen(0x0800000000000000),
        black_king(0x1000000000000000)
{}
