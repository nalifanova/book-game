/**Game steps **/
#include "headers/game_steps.h"

#include <iostream>

#include "headers/globals.h"
#include "headers/object_factory.h"

void fight_with_raul(Player& player)
{
    Human enemy = create_sir_raul();
    int score = roll_dice(false); // step (219)
    switch (score) {
        case 1:
        case 2:
        case 3:
        case 5: // (447) - not lucky
            player.lose_hp(4);
            player.comment.warning(
                "Sir Raul's spear hits you! Your HP is falling [-4]."
                );
            break;
        default: // (118) - 4, 6: lucky
            player.comment.text("Sir Raul's spear misses the target.");
            enemy.lose_hp(4);
            break;
    }
    player.comment.text(std::string(row::k_underline_length, '-'));
    fight(enemy, player);
}

void fight_with_mortimer(Player& player)
{
    Human enemy = create_sir_mortimer();
    fight(enemy, player);
}

void fight_with_viscount_elk(Player& player)
{
    Human enemy = create_viscount_elk();
    fight(enemy, player);
}

void fight_with_rosht(Player& player)
{
    Beast enemy = create_rosht();
    fight(enemy, player);
};

void confession_to_monk(Player& player, int question_number)
{
    if (question_number == 1) {
        player.lose_hp(6);
        player.comment.text("Confession takes strength -6 HP.");
    } else if (question_number == 2) {
        player.lose_hp(4);
        player.comment.text("Confession takes strength -4 HP.");
    }
}

void check_health(Player& player, Inventory& inventory)
{
    if (inventory.get_food_amount() == 0) {
        if (player.comment.is_active()) {
            log::warning(
                "HP is " + std::to_string(player.get_hp())
                + " and there is no food left.");
            log::ok(std::string(row::k_underline_length, '-'));
        }
        return;
    }

    while (player.is_hungry()) {
        if (player.comment.is_active()) log::info("Hungry? yes");

        if (inventory.get_food_amount() > 0) {
            player.eat(1);
            inventory.remove_food();
        } else { break; }
    }
    if (player.comment.is_active()) {
        log::info(
            "HP is " + std::to_string(player.get_hp())
            + " and food left is " + std::to_string(
                inventory.get_food_amount()));
        log::ok(std::string(row::k_underline_length, '-'));
    }
}

void add_coin(Player& player, Inventory& inventory)
{
    if (inventory.get_free_slots_amount() == 0) {
        player.eat(1);
        inventory.remove_food();
    }
    inventory.add_item(game_items.at(item::k_duchy_coin_name));
}

void add_helmet(Player& player, Inventory& inventory, bool to_inventory)
{
    if (to_inventory) {
        if (inventory.get_free_slots_amount() == 0) {
            player.eat(1);
            inventory.remove_food();
        }
        // "Helmet (+26)"
        inventory.add_item(Item(item::k_knights_helmet_name, 26));
    }
    //    else
    //    {
    // "Helmet(+12)"
    //        inventory.replace_head_cover(Item(item::kOldHelmetName, 12));
    //    }
}
