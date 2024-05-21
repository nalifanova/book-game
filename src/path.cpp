#include "headers/path.h"

#include <algorithm> // std::find

#include "headers/comment.h"

Path::Path() = default;
Path::~Path() = default;

void Path::add_step(const Step& step)
{
    m_step_ids.push_back(step.id);
    m_steps[step.id] = step;
}

int Path::get_index(const int& step_id)
{
    auto it = std::find(
        m_step_ids.begin(), m_step_ids.end(), step_id
    );
    if (it != m_step_ids.end())
    {
        return (int) std::distance(m_step_ids.begin(), it);
    }
    return 0;
}

void Path::show_title(const std::string& title) const
{
    comment.warning(title, " ");
}

void Path::break_line() const
{
    comment.warning("...", "\n");
}

void Path::show(const int& from_step_id, const int& to_step_id)
{
    int from = get_index(from_step_id);
    int to = get_index(to_step_id);
    check_from_to(from, to);

    Step step;
    int counter = 1;

    for (size_t i = from; i < to; i++)
    {
        step = m_steps.at(m_step_ids[i]);
        comment.text(
            step.name + "(" + std::to_string(step.id) + ")" +
            get_type_name(step.type),
            (
                (step.type == StepType::a_final)
                ? "!\n"
                : ((counter) % 5 == 0 ? "->\n" : "->")
            )
        );
        counter++;
    }
}

StepType Path::get_step_type_id(char& special_symbol, size_t length)
{
    if (special_symbol == '#') return a_fight;
    if (special_symbol == '%') return checking_luck;
    if (special_symbol == '^') return an_item_adding;

    if (length == 1) return a_default;
    else if (length > 1) return a_condition;
    else return a_final;
}

// protected methods
std::string Path::get_type_name(StepType type)
{
    switch (type)
    {
        case a_condition:
            return "[?]";
        case a_fight:
            return "[#]";
        case checking_luck:
            return "[%]";
        case an_item_adding:
            return "[^]";
        case a_final:
            return "[Game over]";
        default:
            return "[.]";
    }
}

void Path::check_from_to(int& from_index, int& to_index)
{
    size_t pathLength = m_step_ids.size();
    to_index = (to_index > 0 && to_index < pathLength)
        ? to_index + 1 : (int) pathLength;
    from_index = (from_index >= 0 && from_index < pathLength) ? from_index : 0;
}
