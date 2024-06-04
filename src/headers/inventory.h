#ifndef BOOK_GAME_INVENTORY_H
#define BOOK_GAME_INVENTORY_H

#include <vector>

#include "comment.h"
#include "item.h"

class Inventory
{
public:
    Inventory();

    ~Inventory();

    Comment comment = Comment();

    void remove_item(const std::string& item_name);

    Item* get_item(const std::string& item_name);

    void add_item(const Item& item);

    int get_free_slots_amount();

    void show_backpack_items();

    void remove_food();

    int get_food_amount();
    //    void replace_head_cover(const Item& item);

private:
    std::vector<Item> m_backpack = {};
    std::string m_weapon = "sword";
    //    Item m_head;
    const int m_backpack_size = 7;
};

#endif //BOOK_GAME_INVENTORY_H
