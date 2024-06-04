/*
 * Tests in headers (for now)
 */
#ifndef BOOK_GAME_MAIN_TEST_H
#define BOOK_GAME_MAIN_TEST_H
//------- standard libs
#include <iostream>
#include <cassert>

// ----- custom libs
#include "headers/log.h"
#include "headers/comment.h"
#include "headers/creature.h"
#include "headers/inventory.h"
#include "headers/actions.h"
#include "headers/path.h"
#include "headers/item.h"

// Macros e.g.: IS_TRUE(fn_name(10));
#define IS_TRUE(x) {\
if (!(x)) std::cout << __FUNCTION__ << " failed on line " <<\
__LINE__ << std::endl;\
}
// Macros should be implemented in one line, but! there's a trick with `\`
#define test_line {\
std::cout << "\033[1;31m- " << __FUNCTION__ << " [" <<\
__LINE__ << "] -\033[0m" << std::endl;\
};

inline void test_comments_text()
{
    test_line;
    Comment comment = Comment();
    comment.turn_messages_on();
    for (size_t i = 0; i < 2; i++) {
        comment.message("luck", i);
        comment.message("charisma", i);
        comment.message("reaction", i);
    }

    for (const auto& [fst, snd]: comment_messages) {
        log::info(fst + std::string(" ").append(snd));
    }
}

inline void test_logs()
{
    test_line;
    std::string msg = "Test world!";
    log::msg(1'000'123);
    log::msg(msg);
    log::info(msg);
    log::warning(msg);
    log::error(msg);
    log::ok(msg);
    log::debug(msg);
}

inline void test_human()
{
    test_line;
    int dexterity = 16;
    int strength = 8;
    std::string name = "Sir Peter";

    Human human = Human(name, dexterity, strength);
    assert(human.get_name() == name);
    assert(human.get_dexterity() == dexterity);
    assert(human.get_hp() == strength);
    human.receive_damage();
    assert(human.get_hp() == strength - 2);
    assert(human.is_alive());

    assert(human.hit(10) == 10 + dexterity);
    human.lose_hp(6);
    assert(!human.is_alive());
    assert(human.get_hp() == 0);
}

inline void test_beast()
{
    test_line;
    int dexterity = 10;
    int strength = 4;
    std::string name = "Wild mob";

    Beast beast = Beast(name, dexterity, strength);
    assert(beast.get_name() == name);
    assert(beast.get_dexterity() == dexterity);
    assert(beast.get_hp() == strength);
    beast.receive_damage();
    assert(beast.get_hp() == strength - 2);
    assert(beast.is_alive());

    assert(beast.hit(10) == 10 + dexterity);
    beast.lose_hp(2);
    assert(!beast.is_alive());
    assert(beast.get_hp() == 0);
}

inline void test_player()
{
    test_line;
    int dexterity = 10;
    int strength  = 10;
    int charisma  = 5;
    int luck      = 7;
    std::string name = "Player Name";

    Player player = Player(
        name, dexterity, strength, charisma, luck
    );
    assert(player.get_name() == name);
    assert(player.get_dexterity() == dexterity);
    assert(player.get_hp() == strength);
    player.receive_damage();
    assert(player.get_hp() == strength - 2);
    assert(player.is_alive());

    assert(player.hit(10) == 10 + dexterity);
    player.lose_hp(8);
    assert(!player.is_alive());
    assert(player.get_hp() == 0);
}

inline void test_player_characteristics()
{
    test_line;
    int dexterity = 10;
    int strength  = 10;
    int charisma  = 5;
    int luck      = 7;
    int reaction  = 5;
    std::string name = "Player Name";

    Player player = Player(
        name, dexterity, strength, charisma, luck
    );
    //player.comment.turnMessagesOn();

    assert(player.is_lucky(luck));
    assert(player.get_luck() == luck - 1);

    assert(!player.is_lucky(luck));
    assert(player.get_luck() == luck - 2);

    assert(!player.is_charismatic(charisma + 1));
    assert(player.get_charisma() == charisma - 1);

    assert(player.is_charismatic(charisma - 1));
    assert(player.get_charisma() == charisma);

    assert(player.is_fast(reaction));
    assert(player.get_reaction() == reaction + 1);

    assert(!player.is_fast(reaction + 3));
    assert(player.get_reaction() == reaction);
}

inline void test_inventory()
{
    test_line;
    Item fishBone = Item("Fish Bone", 1);
    Item monkOutfit = Item("MonkOutfit", 2);
    Item pen = Item("White Pen", 3);
    Item magicWand = Item("Magic Wand", 4);

    Inventory inventory = Inventory();
//    inventory.comment.turnMessagesOn();
    assert(inventory.get_free_slots_amount() == 4);
    inventory.add_item(fishBone);
    inventory.add_item(monkOutfit);
    assert(inventory.get_free_slots_amount() == 2);
    inventory.add_item(pen);
    inventory.add_item(pen);
    assert(inventory.get_free_slots_amount() == 0);
    inventory.add_item(magicWand);

    inventory.remove_item("Magic Wand");
    inventory.remove_item("White Pen");

    assert(inventory.get_free_slots_amount() == 1);
    inventory.add_item(magicWand);

    assert(inventory.get_food_amount() == 3);
    inventory.remove_food();
    assert(inventory.get_food_amount() == 2);
    assert(inventory.get_free_slots_amount() == 1);

    Item heavyArmor = Item("Heavy armor", 5, 3);
    inventory.add_item(heavyArmor);
    assert(inventory.get_free_slots_amount() == 1);
}

inline void test_fight()
{
    test_line;
    Human sirRalf = Human("Sir Ralf", 12, 8);
    int charisma = 7;
    int luck = 7;
    Player player = Player(
        "Peter", 12, 12, charisma, luck
    );
//    player.comment.turnMessagesOn();
    fight(sirRalf, player);
}

inline void test_path()
{
    test_line;
    Path path = Path();

    path.add_step({"Maze Gates", 1, e_condition});
    path.add_step(Step{"left", 486, e_condition});
    path.add_step(Step{"to magic", 114, e_condition});
    path.add_step(Step{"Belief word", 77});
    path.add_step(Step{"magic works", 183, e_condition});
    path.add_step(Step{"go to roses", 2, e_condition});
    path.add_step(Step{"pick up white rose", 615});

    path.comment.turn_messages_on();
    path.show();
    log::msg("End of Path");

    assert(0 == path.get_index(1));
    assert(1 == path.get_index(486));
    assert(6 == path.get_index(615));
    log::msg("From 114 to 2");
    path.show(114, 2);
    path.break_line();
}

inline void test_path_separator()
{
    test_line;
    Path path = Path();

    for (int i = 0; i < 20; i++)
        path.add_step(
            {"step" + std::to_string(i + 1), i + 20}
        );
    path.comment.turn_messages_on();

    path.show(22, 32);
    path.break_line();
    path.show(32, 38);
    path.break_line();
}

inline void test_items()
{
    test_line;
    Item ring = Item(
        "Cool ring", 12, 1, std::plus<int>()
    );
    Item helmet = Item(
        "Steel helmet", 22, 1, std::minus<int>()
    );
    assert(14 == ring.alternative_step(2));
    assert(20 == helmet.alternative_step(42));
}

inline void run_tests()
{
//    test_comments_text();
//    test_logs();
    test_human();
    test_beast();
    test_player();
    test_player_characteristics();
    test_inventory();

    test_fight();
    test_path();
    test_path_separator();
    test_items();
}

#endif // BOOK_GAME_MAIN_TEST_H