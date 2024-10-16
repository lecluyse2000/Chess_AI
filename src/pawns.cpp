//Author: Caden LeCluyse

#include "pawns.h"

// @Desc: Default constructor for pawns that initializes pawns to their appropriate positions

Pawns::Pawns() noexcept : white_pawns(0x000000000000FF00), 
                          black_pawns(0x00FF000000000000)
{}
