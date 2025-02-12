//Author: Caden LeCluyse

#include "game.h"
#include <iostream>
#include <string_view>

int main(const int argc, const char* const argv[])
{
    if (argc > 2) {
        std::cerr << "Too many arguments!\n\n";
        return 1;
    } else if (argc == 2) {
        const std::string_view input = argv[1];
        if (input == "--game" || input == "-g") {
            return Game::start_game_mode();
        } else if (input == "--version" || input == "-v") {
            std::cout << "Chess Engine v" << CURRENT_VERSION << std::endl;
            return 0;
        }
        std::cerr << "Invalid flag!\n\n";
        return 1;

    }

    return 0;
}
