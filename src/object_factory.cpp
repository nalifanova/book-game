#include "headers/object_factory.h"

#include "headers/actions.h"
#include "headers/globals.h"
#include "headers/item.h"

std::map<std::string, Item> game_items = {
    {item::kFoodName,
     Item(item::kFoodName, 0)},
    {item::kGuidingThreadName,
     Item(item::kGuidingThreadName, 40)},
    {item::kFishBoneName,
     Item(item::kFishBoneName, 49,1,
          std::minus<int>())},
    {item::kHandkerchiefName,
     Item(item::kHandkerchiefName, 194)},
    {item::kSmallMirrorName,
     Item(item::kSmallMirrorName, 59)},

    {item::kBarbarianOutfitName,
     Item(item::kBarbarianOutfitName, 50, 2)},
    {item::kMonkOutfitName,
     Item(item::kMonkOutfitName, 92, 2)},
    {item::kKnightOutfitName,
     Item(item::kKnightOutfitName, 377, 2)},
    {item::kSailorsOutfitName,
     Item(item::kSailorsOutfitName, 77, 2,
          std::minus<int>())},

    {item::kDuchyCoinName,
     Item(item::kDuchyCoinName, 28)},
    {item::kDuchyCoinName,
     Item(item::kDuchyCoinName, 28)},
};

Player create_me(std::string& name)
{
    int dexterity, strength, luck, charisma;
    create_attributes(dexterity, strength, charisma, luck);
    return {name, dexterity, strength, charisma, luck};
};

Human create_sir_raul()
{
    return {mob::kSirRaul, 10, 12};
};

Human create_sir_mortimer()
{
    return {mob::kSirMortimer, 9, 12};
};

Human create_viscount_elk()
{
    return {mob::kViscountElk, 11, 8};
};

Beast create_rosht()
{
    return {mob::kRoscht, 10, 12};
};
