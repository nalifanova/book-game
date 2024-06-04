#include "headers/object_factory.h"

#include "headers/actions.h"
#include "headers/globals.h"
#include "headers/item.h"

std::map<std::string, Item> game_items = {
    {item::k_food_name,
     Item(item::k_food_name, 0)},
    {item::k_guiding_thread_name,
     Item(item::k_guiding_thread_name, 40)},
    {item::k_fish_bone_name,
     Item(
         item::k_fish_bone_name,
         49,
         1,
         std::minus<int>())},
    {item::k_handkerchief_name,
     Item(item::k_handkerchief_name, 194)},
    {item::k_small_mirror_name,
     Item(item::k_small_mirror_name, 59)},

    {item::k_barbarian_outfit_name,
     Item(item::k_barbarian_outfit_name, 50, 2)},
    {item::k_monk_outfit_name,
     Item(item::k_monk_outfit_name, 92, 2)},
    {item::k_knight_outfit_name,
     Item(item::k_knight_outfit_name, 377, 2)},
    {item::k_sailors_outfit_name,
     Item(
         item::k_sailors_outfit_name,
         77,
         2,
         std::minus<int>())},

    {item::k_duchy_coin_name,
     Item(item::k_duchy_coin_name, 28)},
    {item::k_duchy_coin_name,
     Item(item::k_duchy_coin_name, 28)},
};

Player create_me(std::string& name)
{
    int dexterity, strength, luck, charisma;
    create_attributes(dexterity, strength, charisma, luck);
    return {name, dexterity, strength, charisma, luck};
};

Human create_sir_raul() { return {mob::k_sir_raul, 10, 12}; };

Human create_sir_mortimer() { return {mob::k_sir_mortimer, 9, 12}; };

Human create_viscount_elk() { return {mob::k_viscount_elk, 11, 8}; };

Beast create_rosht() { return {mob::k_roscht, 10, 12}; };
