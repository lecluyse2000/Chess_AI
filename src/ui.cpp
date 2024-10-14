#include "ui.h"

#include <cstdint>
#include <iostream>
#include <optional>
#include <string>
#include "util/types.h"

namespace UI
{

[[nodiscard]] std::optional<bool> get_player_color()
{
    std::string player_color;

    while (player_color != "W" && player_color != "w" &&
           player_color != "B" && player_color != "b") {

        if (player_color == "") {
            std::cout << "Would you like to be white or black? (W/B): ";
        } else {
            std::cout << "Invalid input! Try again. (W/B): ";
        }

        if (!std::getline(std::cin, player_color)) [[unlikely]] {
            std::cerr << "An error has occurred!\n\n"; 
            return std::nullopt;
        }
    }

    return player_color == "W" || player_color == "w";
}

[[nodiscard]] static std::optional<bool> verify_exit(const std::string_view input_expression)
{
    std::string exit_flag = "a";

    while (exit_flag != "Y" && exit_flag != "y" && !exit_flag.empty()
        && exit_flag != "N" && exit_flag != "n") {
        
        if (exit_flag == "a") {
            std::cout << "You entered " << input_expression << ", is this correct? (Y/n): ";
        } else {
            std::cout << "Try again! (Y/n): ";
        }

        if (!std::getline(std::cin, exit_flag)) [[unlikely]] {
            std::cout << "Error getting input! Aborting...\n" << std::endl;
            return std::nullopt;
        }
    }

    return exit_flag == "Y" || exit_flag == "y" || exit_flag.empty();
}

[[nodiscard]]
static constexpr std::optional<std::pair<Types::Piece, std::uint64_t> > parse_input(const std::string_view input_expression)
{
    if (input_expression.length() > 12) {
        std::cerr << "The input is too long!\n\n";
        return std::nullopt;
    }
    for (const auto character : input_expression) {
        if (std::isspace(character)) {
            continue;
        }
    }
}

[[nodiscard]] std::optional<std::pair<Types::Piece, std::uint64_t> > get_player_move(const auto& current_moves)
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

        const auto parse_result = parse_input(input_expression);
        if (!parse_result) {
            return std::nullopt;
        }
    }
}

}
