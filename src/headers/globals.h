#ifndef BOOK_GAME_GLOBALS_H
#define BOOK_GAME_GLOBALS_H

#include <iostream>

// Note: should be used for GUI window
namespace globals
{
    constexpr int k_screen_width = 640;
    constexpr int k_screen_height = 480;
}

namespace row
{
    constexpr int k_underline_length = 50;
    constexpr int k_cli_output_line_width = 121;
}

namespace msg
{
    const std::string k_title = "Book Game:";
    const std::string k_book_name = "Maze of Concealed Death";
}

namespace mob
{
    const std::string k_sir_raul = "Sir Raul";
    const std::string k_sir_mortimer = "Sir Mortimer";
    const std::string k_viscount_elk = "Viscount Elk";
    const std::string k_roscht = "Rosht";
}

namespace item
{
    // Note: names in Russian because they're taken from paragraphs
    const std::string k_food_name = "Food"; // (0)
    const std::string k_guiding_thread_name = "Guiding Thread"; // (+40)
    const std::string k_fish_bone_name = "Fish Bone"; // (-49)
    const std::string k_handkerchief_name = "White Handkerchief"; // (+194)
    const std::string k_small_mirror_name = "Mirror"; // (+59)
    const std::string k_barbarian_outfit_name = "The skins and fur cap of a "
        "barbarian"; // (+50)
    const std::string k_monk_outfit_name = "A monk's robe"; // (+92)
    const std::string k_knight_outfit_name = "Knight's attire"; // (+377)
    const std::string k_merchant_outfit_name = "A merchant's outfit"; // (-48)
    const std::string k_sailors_outfit_name = "A sailor's attire"; // (-77)
    const std::string k_duchy_coin_name = "Duchy coin"; // (+28)"
    // "Helmet (+26)" in backpack or "Helmet(+12)" on head
    const std::string k_knights_helmet_name = "Knight's helmet";
}
#endif //BOOK_GAME_GLOBALS_H
