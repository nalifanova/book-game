#include "headers/actions.h"

#include "headers/creature.h"
#include "headers/globals.h"
#include "headers/random.h"

int roll_dice(const bool two_dice)
{
    const int d1 = random_integer(1, 6);
    if (!two_dice) return d1;

    const int d2 = random_integer(1, 6);
    const int total = d1 + d2;
    return total;
}

void create_attributes(int& dexterity, int& hp, int& charisma, int& luck)
{
    const int attribute_number = roll_dice();
    luck = roll_dice();
    switch (attribute_number) {
        case 2:
            dexterity = 8;
            hp = 22;
            charisma = 8;
            break;
        case 3:
            dexterity = 10;
            hp = 20;
            charisma = 6;
            break;
        case 4:
            dexterity = 12;
            hp = 16;
            charisma = 5;
            break;
        case 5:
            dexterity = 9;
            hp = 18;
            charisma = 8;
            break;
        case 6:
            dexterity = 11;
            hp = 20;
            charisma = 6;
            break;
        case 7:
            dexterity = 9;
            hp = 20;
            charisma = 7;
            break;
        case 8:
            dexterity = 10;
            hp = 16;
            charisma = 7;
            break;
        case 9:
            dexterity = 8;
            hp = 24;
            charisma = 7;
            break;
        case 10:
            dexterity = 9;
            hp = 22;
            charisma = 6;
            break;
        case 11:
            dexterity = 10;
            hp = 18;
            charisma = 7;
            break;
        case 12:
            dexterity = 11;
            hp = 20;
            charisma = 5;
            break;
        default:
            dexterity = 0;
            hp = 0;
            charisma = 0;
            break;
    }
}

void fight(Creature& enemy, Player& player)
{
    if (player.comment.is_active()) {
        log::warning("You start a fight with " + enemy.get_name());
        log::msg(std::string(row::k_underline_length, '-'));
    }

    while (enemy.is_alive() && player.is_alive()) {
        const int enemy_hit = enemy.hit(roll_dice());
        const int player_hit = player.hit(roll_dice());

        player.comment.text(
            "You hit " + std::to_string(player_hit) + ", " +
            enemy.get_name() + " hits " + std::to_string(enemy_hit) + ": ",
            ""
            );

        if (enemy_hit == player_hit) {
            player.comment.text("fight and block, all good");
        } else if (enemy_hit > player_hit) {
            player.receive_damage();
            player.comment.text(
                "your HP -2 (" +
                std::to_string(player.get_hp()) + ")"
                );
        } else {
            enemy.receive_damage();
            player.comment.text(
                "enemy's HP -2 (" +
                std::to_string(enemy.get_hp()) + ")"
                );
        }
    }
    if (player.comment.is_active()) {
        log::warning(
            "My HP after fight is " +
            std::to_string(player.get_hp())
            );
        log::msg(std::string(row::k_underline_length, '-'));
    }
}

void comments_on(Player& player, Inventory& inventory, Path& path)
{
    player.comment.turn_messages_on();
    inventory.comment.turn_messages_on();
    path.comment.turn_messages_on();
}

bool is_game_over(const Player& player)
{
    if (!player.is_alive()) {
        log::error("You are dead. Game over!");
        return true;
    }
    return false;
}
