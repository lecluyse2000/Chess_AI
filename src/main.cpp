#include "engine.h"
#include <iostream>
#include <string>

int main(int argc, char* const argv[])
{
    if (argc > 2) {
        std::cerr << "Too many arguments!\n\n";
        return 1;
    } else if (argc == 2) {
        const std::string input = argv[1];
        if (input != "--analysis" && input != "-a") {
            std::cerr << "Invalid flag!\n\n";
            return 1;
        }

        return Engine::run(true);
    }

    return Engine::run(false);
}
