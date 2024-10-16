//Author: Caden LeCluyse

#ifndef PAWNS_H
#define PAWNS_H

#include <array>
#include <cstdint>
#include <util/util.h>

class Pawns
{
    public:
        
        // @Desc: Default constructor for pawns that initializes pawns to their appropriate positions
        constexpr Pawns() noexcept : white_pawns(0x000000000000FF00ULL), 
                                     black_pawns(0x00FF000000000000ULL)
        {}

        std::uint64_t white_pawns;
        std::uint64_t black_pawns;

    private:

};

#endif

