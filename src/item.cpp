#include "headers/item.h"

#include <functional>
#include <utility>

Item::Item(std::string name, int id, int slots_amount,
           std::function<int(int, int)> sign)
{
    this->name = std::move(name);
    this->id = id;
    this->slots_amount = slots_amount;
//    std::function<int(int, int)> op = std::plus<int>();
//    int c = op(a, b);
    m_sign = std::move(sign);
}

Item::~Item() = default;

int Item::alternative_step(int paragraph_id)
{
    if (this->id <= 0) return 0;
    return m_sign(paragraph_id, this->id);
}
