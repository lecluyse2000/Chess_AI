//Author: Caden LeCluyse

#include "ui.h"

#include <cstdint>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include "util/types.h"

using u64 = std::uint64_t;

namespace UI
{

// @Desc: When playing in game mode, gets the current color for the player
// @Return: An optional bool indicating if getting the input was successful, as well as the player color.

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
            std::cerr << "An error has occurred while getting player color!\n\n"; 
            return std::nullopt;
        }
    }

    return player_color == "W" || player_color == "w";
}

[[nodiscard]] static std::optional<const bool> verify_input(const std::string_view input_expression)
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

[[nodiscard]] static
constexpr std::optional<std::pair<Types::Piece, u64> > parse_input(const std::string_view input_expression)
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

[[nodiscard]] std::optional<std::pair<Types::Piece, u64> > get_player_move(const auto& current_moves)
{
    std::string input_expression;

    while (true) {
        std::cout << "Please enter your move in chess notation: ";

        if (!std::getline(std::cin, input_expression)) {
            std::cout << "Error getting input! Aborting...\n" << std::endl;
            return std::nullopt;
        }

        const auto exit_flag = verify_input(input_expression);
        if (!exit_flag) [[unlikely]] return std::nullopt;
        if (!*exit_flag) continue;

        const auto parse_result = parse_input(input_expression);
        if (!parse_result) return std::nullopt;
    }
}

} // namespace UI
