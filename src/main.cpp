//Author: Caden LeCluyse

#include "game.h"
#include <iostream>
#include <string>

int main(const int argc, const char* const argv[])
{
    if (argc > 2) {
        std::cerr << "Too many arguments!\n\n";
        return 1;
    } else if (argc == 2) {
        const std::string input = argv[1];
        if (input != "--game" && input != "-g") {
            std::cerr << "Invalid flag!\n\n";
            return 1;
        }

        return Game::start_game_mode();
    }

    return 1;
}
