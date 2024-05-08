#include "headers/creature.h"

#include <utility>

// public methods
std::string Creature::get_name()
{
    return m_name;
}

int Creature::get_dexterity() const
{
    return m_dexterity;
}

int Creature::get_hp() const
{
    return m_hp;
}

bool Creature::is_alive() const
{
    return m_hp > 0;
}

int Creature::hit(int dice) const
{
    return m_dexterity + dice;
}

void Creature::receive_damage()
{
    lose_hp(kStrengthLoss);
}

void Creature::lose_hp(int hit_points)
{
    if (m_hp > 0)
    {
        m_hp -= hit_points;
    }
}

void Creature::gain_hp(int hit_points)
{
    m_hp += hit_points;
    if (m_hp > m_initial_hp)
    {
        m_hp = m_initial_hp;
    }
}

// ------------------------
Human::Human(std::string name, int dexterity, int hp)
{
    m_name = std::move(name);
    m_dexterity = dexterity;
    m_hp = hp;
    m_initial_hp = hp;
}
Human::~Human()= default;

// ------------------------
Beast::Beast(std::string name, int dexterity, int hp)
{
    m_name = std::move(name);
    m_dexterity = dexterity;
    m_hp = hp;
    m_initial_hp = hp;
}
Beast::~Beast()= default;

// ------------------------
Player::Player(std::string name, int dexterity, int hp, int& charisma,
               int& luck)
{
    m_name = std::move(name);
    m_dexterity = dexterity;
    m_hp = hp;
    m_initial_hp = hp;
    m_charisma = charisma;
    m_luck = luck;
}
Player::~Player()= default;

// public methods
int Player::get_charisma() const
{
    return m_charisma;
}

int Player::get_luck() const
{
    return m_luck;
}

int Player::get_reaction() const
{
    return m_reaction;
}

bool Player::is_hungry()
{
    return ((m_initial_hp - m_hp) >= kFoodValue);
}

void Player::eat(int amount)
{
    gain_hp(kFoodValue * amount);
}

bool Player::is_lucky(int dice)
{
    bool lucky = m_luck >= dice;
    comment.message("luck", lucky);
    m_luck -= 1;
    return lucky;
}

bool Player::is_charismatic(int dice)
{
    bool charismatic = m_charisma >= dice;
    (charismatic) ? gain_charisma() : lose_charisma();
    comment.message("charisma", charismatic);
    return charismatic;
}

bool Player::is_fast(int dice)
{
    bool reactive = m_reaction >= dice;
    m_reaction = (reactive) ? m_reaction += 1 : m_reaction -= 1;
    comment.message("reaction", reactive);
    return reactive;
}

// protected methods
void Player::lose_charisma(int points)
{
    m_charisma -= points;
}

void Player::gain_charisma(int points)
{
    m_charisma += points;
}
