#ifndef BOOK_GAME_ACTIONS_H
#define BOOK_GAME_ACTIONS_H

#include "creature.h"
#include "globals.h"
#include "inventory.h"
#include "path.h"

/**
 * Get values for input parameters
 * by rolled dice value
 */
void create_attributes(int& dexterity, int& hp, int& charisma, int& luck);
/**
 * Returns the sum of rolled two dices
 * Or the dice of one if twoDice == false
 * @param two_dice bool
 * @return int
 */
int roll_dice(bool two_dice = true);

// Fight between Human/Beast and Player
void fight(Creature& enemy, Player& player);

void comments_on(Player& player, Inventory& inventory, Path& path);

bool is_game_over(Player& player);

#endif //BOOK_GAME_ACTIONS_H
