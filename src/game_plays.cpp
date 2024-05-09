#include "headers/game_plays.h"

#include "headers/game_steps.h"
#include "headers/object_factory.h"

// l_<function_name> - local functions
void l_welcome_message()
{
    log::ok("Welcome to " + msg::kTitle + " " + msg::kBookName);
    log::ok(std::string(row::kUnderlineLength + 10, '-'));
}

void l_print_attributes(int& dexterity, int& hp, int& charisma, int& luck)
{
    log::info(">> Dexterity [" + std::to_string(dexterity),
              "], ");
    log::info("Hit Points [" + std::to_string(hp), "], ");
    log::info("Charisma [" + std::to_string(charisma), "], ");
    log::info("Luck [" + std::to_string(luck), "] <<\n");
    log::info(std::string(row::kUnderlineLength + 10, '-'));
}

Player l_create_player(bool show_attributes = true)
{
    int dexterity, hp, luck, charisma;
    create_attributes(dexterity, hp, charisma, luck);
    if (show_attributes)
        l_print_attributes(dexterity, hp, charisma, luck);
    Player player = Player("Nata", dexterity, hp, charisma, luck);
    return player;
}

void l_path_from1_to42(Path& path, Inventory& inventory)
{
    path.add_step({"Maze gates", 1, a_condition});
    path.add_step(Step{"left", 486, a_condition});
    path.add_step(Step{"to magic", 114, a_condition});
    path.add_step(Step{"a word Belief", 77});
    path.add_step(Step{"magic works", 183, a_condition});
    path.add_step(Step{"to roses", 2, a_condition});
    path.add_step(Step{"pick up a white rose", 615});
    path.show_title();
    path.show(1, 615);
    path.show_title("surprise:");
    inventory.add_item(game_items.at(item::kGuidingThreadName));

    path.add_step(Step{"go down the alley", 446,
                       a_condition});
    path.add_step(Step{"eavesdropping on the conversation", 116,
                       a_condition});
    path.show(446, 116);
    path.add_step(Step{"pretending to be a gardener", 217});
    path.add_step(Step{"the guard leaves", 174});
    path.add_step(Step{"continue to walk along the alley", 42,
                       a_condition});
    path.show_title("\n->");
    path.show(217, 42);
    path.break_line();
}

void l_path_from42_to254(Path& path, Inventory& inventory)
{
    // "continue to walk along the alley"(42) и choose 310
    path.add_step(Step{"go to the palace", 310});
    path.add_step(Step{"open the door", 406});
    path.show_title("continue:");
    path.show(310, 406);
    // get items from the wardrobe (406)
    path.show_title("surprise:");
    inventory.add_item(game_items.at(item::kFishBoneName));
    inventory.add_item(game_items.at(item::kHandkerchiefName));

    path.add_step(Step{"inside the wardrobe", 352,
                       a_condition});
    path.add_step(Step{"looking at the costumes", 112,
                       a_condition});
    path.show_title("->");
    path.show(352, 112);
    // I don't take outfits but only a small mirror
    path.show_title("surprise:\n");
    inventory.add_item(game_items.at(item::kSmallMirrorName));

    path.add_step(Step{"open the door in the wall", 22});
    path.add_step(Step{"stand on the balcony", 254,
                       a_condition});
    path.show_title("->");
    path.show(22, 254);
    path.break_line();
}

void l_path_from254_to524(Path& path)
{
    // "stand on the balcony"(254) и choose 80
    path.add_step(Step{"stop on the stairs", 80});
    // if you have any outfit - 105
    // path.add_step(Step{"looking at what suit I can wear", 105});
    path.add_step(Step{"whispers stop", 524, a_condition});
    path.show_title("continue:");
    path.show(80, 524);
    path.break_line();
}

void l_path_from524_to219(Path& path)
{
    // "whispers stop"(524) I choose 314
    path.add_step(Step{"I bow my head", 246});
    path.add_step(Step{"fanfare sounds", 172, a_condition});
    path.add_step(Step{"I'm not Sir Hugo", 250});
    path.add_step(Step{"I am Sir Hugo", 531});
    path.add_step(Step{"tournament begins", 52});
    path.add_step(Step{"I'm starting the fight", 219,
                       checking_luck});
    path.show_title("continue:");
    path.show(246, 219);
    // check your Luck and start the fight with sir Raul
}

void l_path_from219_to375(Path& path, Player& player)
{
    path.add_step(Step{"fight with Sir Raul", 375,
                       a_fight});
    path.show(375);
    // check your Luck and fight with Raul
    fight_with_raul(player);
}

void l_path_from375_to177(Path& path, Player& player)
{
    path.add_step(Step{"player wins", 46});
    path.add_step(Step{"to the Duke's residence", 109,
                       a_condition});
    path.add_step(Step{"invitation to lunch", 357,
                       a_condition});

    path.show_title("continue:");
    path.show(46, 357);
    player.gain_hp(8);
    path.show_title("::");
    log::info("Player's HP is: " + std::to_string(player.get_hp()));

    path.add_step(Step{"talking with Duke Runtu", 280});
    path.add_step(Step{"strange proposal", 177,
                       a_condition});
    path.show_title("continue:");
    path.show(280, 177);
    path.break_line();
}

void l_path_from309_to6(Path& path, Player& player)
{
    path.show_title("continue:");
    path.add_step(Step{"kill a stranger", 309});
    path.add_step(Step{"fight with Mortimer", 6, a_fight});
    path.show(309, 6);
    path.break_line();
    fight_with_mortimer(player);
}

void l_path_from6_to529(Path &path, Inventory& inventory, Player& player)
{
    path.add_step(Step{"player wins", 534});
    path.show_title("continue:");
    path.show(534, 534);

    path.show_title("surprise:");
    add_coin(player, inventory); // gift from Duke

    path.add_step(Step{"down into the corridor", 8,
                       a_condition});
    path.add_step(Step{"go down the corridor", 121,
                       a_condition});
    path.add_step(Step{"left", 381, a_condition});
    path.add_step(Step{"in the sanctuary", 247,
                       a_condition});
    path.add_step(Step{"take a helmet and fight begins", 529,
                       a_fight});
    path.show_title("->");
    path.show(8, 529);
    path.break_line();
        // Wanna helmet? (529)
    fight_with_viscount_elk(player);
}

void l_path_from529_to(Path &path, Inventory& inventory, Player& player) {
    path.add_step(Step{"player wins", 483});
    path.show_title("continue:");
    path.show(483, 483);

    path.show_title("surprise:");
    add_helmet(player, inventory); // put on a head

    // TODO: to be continued ...
}

// TODO: in process ...
void game_play_one()
{
    l_welcome_message();
    // 1. Get ready
    Inventory inventory = Inventory(); // 3 food in backpack
    Player player = l_create_player();
    Path path = Path();
    comments_on(player, inventory, path);
    // 2. Start the Game
    l_path_from1_to42(path, inventory);
    l_path_from42_to254(path, inventory);
    l_path_from254_to524(path);
    l_path_from524_to219(path);
    l_path_from219_to375(path, player); // fight Raul
    if (is_game_over(player)) return;

    l_path_from375_to177(path, player);

    check_health(player, inventory); // prepare before the fight
    l_path_from309_to6(path, player); // fight with Mortimer
    if (is_game_over(player)) return;
    check_health(player, inventory);

    l_path_from6_to529(path, inventory, player);
    if (is_game_over(player)) return;
    check_health(player, inventory);

    l_path_from529_to(path, inventory, player);

//    // path to left (611)
//    fight_with_rosht(player);
//    if (is_game_over(player)) return;
//    check_health(player, inventory);
////    /* USE kGuidingThreadName (+40)" (556) */
//    inventory.get_item(item::kGuidingThreadName);
//
//    // confession to a monk (261) 1 Question: Did you kill anyone on your way?
//    confession_to_monk(me, 1); //  -6 HP
//    if (is_game_over(player)) return;
//    check_health(me, inventory);
//
//    if (player.get_hp() > 10) {
//        // confession to a monk (261) 2 Question: Whom do you serve — Good (349) or Evil (426)?
//        confession_to_monk(player, 2); //  Good (349) -4 HP
//        if (is_game_over(player)) return;
//        check_health(player, inventory);
//    } else {
//        bool passed;
//        // confession to a monk (261) 2 Question: Whom do you serve — Good (349) or Evil (426)?
//        check_charisma(player, passed); // Evil (426)
//        if (!passed) {
//            log::error("You are dead. Game over!");
//        }
//    }
}

void game_play_death3()
{
    l_welcome_message();
    // 1. Get ready
    Inventory inventory = Inventory(); // 3 food in backpack
    Player me = l_create_player(false);
    Path path = Path();
    path.comment.turn_messages_on();
    // 2. Start the Game
    l_path_from1_to42(path, inventory);
    l_path_from42_to254(path, inventory);
    l_path_from254_to524(path);

    // "whispers stop"(524) choose 314
    path.add_step(Step{"get down on a knee", 314});
    path.add_step(Step{"there is silence", 43, a_final});
    path.show(314, 43);
    log::error("Dying from archers' arrows (again).");
}

void game_play_death2()
{
    l_welcome_message();
    // 1. Get ready
    Inventory inventory = Inventory(); // 3 food in backpack
    Player me = l_create_player(false);
    Path path = Path();
    path.comment.turn_messages_on();
    // 2. Start the Game
    l_path_from1_to42(path, inventory);
    l_path_from42_to254(path, inventory);

    // "stand on the balcony"(254) choose 43
    path.add_step(Step{"go down the stairs", 43, a_final});
    path.show(43);
    log::error("Dying from archers' arrows.");
}

void game_play_death1() {
    l_welcome_message();
    // 1. Get ready
    Inventory inventory = Inventory(); // 3 food in backpack
    Player me = l_create_player(false);
    Path path = Path();
    path.comment.turn_messages_on();
    // 2. Start the Game
    l_path_from1_to42(path, inventory);

    //"continue to walk along the alley"(42) choose 209
    path.add_step(Step{"heading towards the village", 209});
    path.add_step(Step{"go down to the river", 510,
                       a_final});
    path.show(209);
    log::error("Dying from a crossbow arrow.");
}
