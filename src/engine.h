#ifndef ENGINE_H
#define ENGINE_H

#include "gamestate.h"

class Engine
{

    public:
        [[nodiscard]] int run();

    private:
        Gamestate gamestate;
};

#endif
