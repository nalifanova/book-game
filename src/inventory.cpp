#include "headers/inventory.h"

#include "headers/globals.h"

Inventory::Inventory()
{
    for (int i = 0; i < 3; i++) {
        m_backpack.emplace_back(item::k_food_name, 0);
    }
}

Inventory::~Inventory() = default;

Item* Inventory::get_item(const std::string& item_name)
{
    for (auto& item: m_backpack) { if (item.name == item_name) return &item; }
    return nullptr;
}

void Inventory::remove_item(const std::string& item_name)
{
    for (int i = 0; i < m_backpack.size(); i++) {
        if (m_backpack.at(i).name == item_name) {
            m_backpack.erase(m_backpack.begin() + i);
            comment.message("inventory-", true, item_name);
            return;
        }
    }
    comment.message("inventory-", false, item_name);
}

void Inventory::add_item(const Item& item)
{
    if (get_free_slots_amount() < item.slots_amount) {
        comment.message("inventory", false);
        return;
    }
    m_backpack.push_back(item);
    comment.message("inventory+", true, item.name);
}

int Inventory::get_free_slots_amount()
{
    int slots_amount = 0;
    for (const Item& item: m_backpack) { slots_amount += item.slots_amount; }
    return m_backpack_size - slots_amount;
}

void Inventory::show_backpack_items()
{
    for (auto& i: m_backpack) { comment.text(i.name, ", "); }
    comment.text(
        "out of " + std::to_string(m_backpack_size) + " slots."
        );
}

void Inventory::remove_food() { remove_item(item::k_food_name); }

int Inventory::get_food_amount()
{
    int total_food = 0;
    for (const Item& item: m_backpack) {
        if (item.name == item::k_food_name) total_food += 1;
    }
    return total_food;
}
