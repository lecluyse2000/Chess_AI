#include "ui.h"

#include <cstdint>
#include <iostream>
#include <optional>
#include <string>

namespace UI
{

[[nodiscard]] std::optional<bool> get_player_color()
{
    std::string player_color;

    while (true) {
        std::cout << "Would you like to be white or black? (W/B): ";

        if (!std::getline(std::cin, player_color)) [[unlikely]] {
            std::cerr << "An error has occurred!\n\n"; 
            return std::nullopt;
        }

        if (player_color != "W" && player_color != "w" &&
            player_color != "B" && player_color != "b") {
            std::cout << "Invalid input! Try again.\n";
        } else {
            return player_color == "W" || player_color == "w";
        }
    }

}

[[nodiscard]] static std::optional<bool> verify_exit(const std::string_view input_expression)
{
    std::string exit_flag = "a";

    while (exit_flag != "Y" && exit_flag != "y" && !exit_flag.empty()
        && exit_flag != "N" && exit_flag != "N") {
        
        if (exit_flag == "a") {
            std::cout << "You entered" << input_expression << ", is this correct? (Y/n): ";
        } else {
            std::cout << "Try again! (Y/n): ";
        }

        if (!std::getline(std::cin, exit_flag)) {
            std::cout << "Error getting input! Aborting...\n" << std::endl;
            return std::nullopt;
        }
    }

    return exit_flag == "Y" || exit_flag == "y" || exit_flag.empty();
}

[[nodiscard]]
static std::optional<std::pair<std::uint64_t, std::uint64_t> > parse_input(const std::string_view input_expression)
{
    for (const auto& character : input_expression) {
        if (std::isspace(character)) {
            continue;
        }
    }
}

[[nodiscard]] std::optional<std::pair<std::uint64_t, std::uint64_t> > get_player_move()
{
    std::string input_expression;

    while (true) {
        std::cout << "Please enter your move in chess notation: ";

        if (!std::getline(std::cin, input_expression)) {
            std::cout << "Error getting input! Aborting...\n" << std::endl;
            return std::nullopt;
        }

        const auto exit_flag = verify_exit(input_expression);
        if (!exit_flag) {
            return std::nullopt;
        }

        if(*exit_flag) {
            return input_expression; 
        }

        }
    }
}

}
