#ifndef BOOK_GAME_ITEM_H
#define BOOK_GAME_ITEM_H

#include <functional>
#include <iostream>

class Item
{
public:
    Item(
        std::string name,
        int id,
        int slots_amount = 1,
         std::function<int(int, int)> sign = std::plus<int>()
    );

    ~Item();

    // Returns a value of a next possible step
    int alternative_step(int paragraph_id);

public:
    std::string name;
    int id;
    int slots_amount; // takes slots in a backpack

private:
    std::function<int(int, int)> m_sign;
};

#endif //BOOK_GAME_ITEM_H
