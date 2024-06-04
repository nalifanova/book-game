#ifndef BOOK_GAME_CREATURE_H
#define BOOK_GAME_CREATURE_H

#include <iostream>

#include "comment.h"

constexpr int k_strength_loss = 2;
constexpr int k_food_value = 4;

class Creature
{
public:
    // No user-written constructor needed
    // in abstract base class.
    // Making base class destructor virtual guarantees
    // that the object of derived class is destructed properly
    virtual ~Creature() = default;
    // list of pure virtual functions that should be overridden in
    // derived classes
    // virtual void move(int to);

    std::string get_name();

    [[nodiscard]] int get_dexterity() const;

    [[nodiscard]] int get_hp() const;

    [[nodiscard]] bool is_alive() const;

    // Returns a hit value
    [[nodiscard]] int hit(int dice) const;

    // In a fight hit value is constant
    void receive_damage();

    void lose_hp(int hit_points);

    // HP cannot be more than initial
    void gain_hp(int hit_points);

protected:
    std::string m_name;
    int m_dexterity;
    int m_hp;
    int m_initial_hp;
};

class Human: public Creature
{
public:
    // constructor in derived class
    Human(std::string name, int dexterity, int hp);

    ~Human() override;
};

class Beast: public Creature
{
public:
    // constructor in derived class
    Beast(std::string name, int dexterity, int hp);

    ~Beast() override;
};

class Player: public Creature
{
public:
    Player(std::string name, int dexterity, int hp, int& charisma, int& luck);

    ~Player() override;

    Comment comment = Comment();

    [[nodiscard]] int get_charisma() const;

    [[nodiscard]] int get_luck() const;

    [[nodiscard]] int get_reaction() const;

    bool is_hungry();

    void eat(int amount = 1);

    bool is_lucky(int dice);

    bool is_charismatic(int dice);

    bool is_fast(int dice);

protected:
    void lose_charisma(int points = 1);

    void gain_charisma(int points = 1);

private:
    int m_charisma;
    int m_luck;
    int m_reaction = 5;
};

#endif //BOOK_GAME_CREATURE_H
