#include "headers/game.h"

#include <iostream>
#include <map>

#include "headers/actions.h"
#include "headers/creature.h"
#include "headers/file_reader.h"
#include "headers/globals.h"
#include "headers/log.h"
#include "headers/object_factory.h"
#include "headers/path.h"

namespace cli
{
enum Command { backpack = 1, weapon, food, health, path, quit };
}

std::map<std::string, int> commands = {
    {"backpack", cli::backpack},
    {"weapon", cli::weapon},
    {"food", cli::food},
    {"health", cli::health},
    {"path", cli::path},
    {"quit", cli::quit}
};

Game::Game()
{
    init_objects();
    this->run();
}

Game::~Game() = default;

bool Game::is_number_available(int number)
{
    return (
        std::find(m_options.begin(), m_options.end(), number)
        != m_options.end()
    );
}

void Game::remove_option(int number)
{
    m_options.erase(
        std::remove(m_options.begin(), m_options.end(), number),
        m_options.end()
        );
}

void Game::show_available_options() const
{
    if (m_options.empty()) {
        log::warning("\nNo available options, enter `path`");
        return;
    }
    log::warning("\nAvailable options:", " ");
    for (const auto el: m_options)
        std::cout << '[' << el << "] ";
    std::cout << std::endl;
}

std::string Game::available_command_list()
{
    std::string list;
    for (const auto& [fst, snd]: commands) { list += "[" + fst + "]"; }
    return list;
}

void Game::get_player_input(std::string& str, const std::string& prompt)
{
    log::info(prompt, " ");
    getline(std::cin, str);
}

bool Game::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Game::init_objects()
{
    std::string player_name;
    get_player_input(player_name, "Enter your name Player:");
    log::ok(
        "Welcome to " + msg::k_book_name + ", " + player_name +
        "!\nYou have: a sword, a backpack and food for three days. "
        "Enter 1 to continue."
        );
    // player = new Player("Nat", 12, 12, 12, 12); // DEBUG
    m_player = new Player(create_me(player_name));
    m_inventory = new Inventory();
    m_path = new Path();
    comments_on(*m_player, *m_inventory, *m_path);
    //    inventory->add_item(game_items.at(item::kGuidingThreadName));
}

void Game::run()
{
    std::string input;
    std::string content; // paragraph Content
    // if you have the right item, you might have an extra option
    std::string optional_item;
    char special_symbol;

    while (input != "quit") {
        get_player_input(
            input,
            "Enter number or " + available_command_list() + ":"
            );
        if (!is_number(input)) {
            run_command(input);
            continue;
        }

        if (!is_number_available(stoi(input))) {
            log::error("There is no option [" + input + "]. ");
            show_available_options();
            continue;
        } else {
            m_options.clear(); // each paragraph gives own options
        }
        get_string_from_file(input, content);
        read_content(
            content,
            m_options,
            optional_item,
            special_symbol);

        Item* item = m_inventory->get_item(optional_item);
        if (item) m_options.push_back(item->id + stoi(input));

        m_path->add_step(
        {
            "step",
            stoi(input),
            Path::get_step_type_id(
                special_symbol,
                m_options.size()
                )
        });
        special_symbol = ' '; // nullify special symbol
        show_available_options();
    }
}

void Game::run_command(const std::string& input) const
{
    switch (commands[input]) {
        case cli::backpack:
            m_inventory->show_backpack_items();
            break;
        case cli::weapon:
            log::msg(m_player->get_name() + " has a sword.");
            break;
        case cli::food:
            log::msg(
                m_player->get_name() + "'s amount of food is " +
                std::to_string(m_inventory->get_food_amount()) + "."
                );
            break;
        case cli::health:
            log::msg(
                m_player->get_name() + "'s health (HP) is " +
                std::to_string(m_player->get_hp()) + "."
                );
            break;
        case cli::quit:
            log::warning(
                "You exit the game, " + m_player->get_name() +
                ". Bye-bye!"
                );
            break;
        case cli::path:
            m_path->show();
            std::cout << std::endl;
            break;
        default:
            log::error("Not a number nor a valid command.");
            break;
    }
}
