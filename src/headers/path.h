#ifndef BOOK_GAME_PATH_H
#define BOOK_GAME_PATH_H

#include <vector>

#include "comment.h"
#include "log.h"

enum StepType {
    a_default,
    a_condition,
    a_fight,
    an_item_adding,
    checking_luck,
    a_final = 9
};

struct Step
{
    std::string name;
    int id;
    StepType type = a_default;
};

class Path
{
public:
    Path();

    ~Path();

    Comment comment = Comment();

    void add_step(const Step& step);

    void show(const int& from_step_id = 0, const int& to_step_id = 0);

    int get_index(const int& step_id);

    void show_title(const std::string& title = "Path:") const;

    void break_line() const;

    static std::string get_type_name(StepType type);

    static StepType get_step_type_id(char& special_symbol, size_t length = 0);

protected:
    void check_from_to(int& from_index, int& to_index);

private:
    std::vector<int> m_step_ids = {};
    std::map<int, Step> m_steps = {};
};

#endif //BOOK_GAME_PATH_H
