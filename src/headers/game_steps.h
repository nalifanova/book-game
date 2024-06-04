#ifndef BOOK_GAME_GAME_STEPS_H
#define BOOK_GAME_GAME_STEPS_H

#include "actions.h"
#include "creature.h"

void fight_with_raul(Player& player);

void fight_with_mortimer(Player& player);

void fight_with_viscount_elk(Player& player);

void fight_with_rosht(Player& player);

void confession_to_monk(Player& player, int question_number);

void check_health(Player& player, Inventory& inventory);

void add_coin(Player& player, Inventory& inventory);

void add_helmet(Player& player, Inventory& inventory, bool to_inventory = true);

#endif //BOOK_GAME_GAME_STEPS_H
