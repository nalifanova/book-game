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
        m_step_ids.begin(),
        m_step_ids.end(),
        step_id
        );
    if (it != m_step_ids.end()) {
        return static_cast<int>(std::distance(
            m_step_ids.begin(),
            it)
        );
    }
    return 0;
}

void Path::show_title(const std::string& title) const
{
    comment.warning(title, " ");
}

void Path::break_line() const { comment.warning("...", "\n"); }

void Path::show(const int& from_step_id, const int& to_step_id)
{
    int from = get_index(from_step_id);
    int to = get_index(to_step_id);
    check_from_to(from, to);

    Step step;
    int counter = 1;

    for (size_t i = from; i < to; i++) {
        step = m_steps.at(m_step_ids[i]);
        comment.text(
            step.name + "(" + std::to_string(step.id) + ")" +
            get_type_name(step.type),
            (
                (step.type == StepType::e_final) ?
                    "!\n" :
                    ((counter) % 5 == 0 ? "->\n" : "->")
            )
            );
        counter++;
    }
}

StepType Path::get_step_type_id(char& special_symbol, size_t length)
{
    if (special_symbol == '#') return e_fight;
    if (special_symbol == '%') return e_checking_luck;
    if (special_symbol == '^') return e_item_adding;

    if (length == 1) return e_default;
    else if (length > 1) return e_condition;
    else return e_final;
}

// protected methods
std::string Path::get_type_name(StepType type)
{
    switch (type) {
        case e_condition:
            return "[?]";
        case e_fight:
            return "[#]";
        case e_checking_luck:
            return "[%]";
        case e_item_adding:
            return "[^]";
        case e_final:
            return "[Game over]";
        default:
            return "[.]";
    }
}

void Path::check_from_to(int& from_index, int& to_index)
{
    size_t pathLength = m_step_ids.size();
    to_index = (to_index > 0 && to_index < pathLength) ?
                   to_index + 1 :
                   static_cast<int>(pathLength);
    from_index = (from_index >= 0 && from_index < pathLength) ? from_index : 0;
}
