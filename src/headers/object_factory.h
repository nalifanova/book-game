#ifndef BOOK_GAME_OBJECT_FACTORY_H
#define BOOK_GAME_OBJECT_FACTORY_H

#include "creature.h"
#include "item.h"

extern std::map<std::string, Item> game_items;

Player create_me(std::string& name);

Human create_sir_raul();

Human create_sir_mortimer();

Human create_viscount_elk();

Beast create_rosht();

#endif //BOOK_GAME_OBJECT_FACTORY_H
