#ifndef BOOK_GAME_GAME_H
#define BOOK_GAME_GAME_H

#include "creature.h"
#include "inventory.h"
#include "path.h"

class Game
{
public:
    Game();
    ~Game();

protected:
    void run();
    void init_objects();
    void run_command(std::string& input);
    bool is_number_available(int number);
    void remove_option(int number);
    void show_available_options();

    static std::string available_command_list();
    static void get_player_input(std::string& str, const std::string& prompt);
    static bool is_number(const std::string& s);

private:
    // possible options for a current step
    std::vector<int> m_options = {1};
    // possible paragraphs ids
    std::vector<int> m_paragraph_list = {};
    // history of steps or logs
    std::vector<int> m_history = {};

    //
    Player *m_player = nullptr;
    Inventory *m_inventory = nullptr;
    Path *m_path = nullptr;
};
#endif //BOOK_GAME_GAME_H
