#ifndef BOOK_GAME_COMMENT_H
#define BOOK_GAME_COMMENT_H

#include <iostream>
#include <map>

#include "log.h"

extern std::map<std::string, std::string> comment_messages;

class Comment
{
public:
    Comment();

    ~Comment();

    void turn_messages_on();

    void turn_messages_off();

    /*
     * Usage Comment::text("Hello there", " ");
     * Output: "Hello there "
     * Usage Comment::warning("Hello there", " ");
     */
    void text(const std::string& message, const std::string& sep = "\n") const;

    void warning(
        const std::string& message,
        const std::string& sep = "\n"
        ) const;

    /*
     * Usage Comment::message("lucky", false);
     * Output: "You are NOT lucky!"
     */
    void message(const std::string& message, bool type) const;

    void message(
        const std::string& message,
        bool type,
        const std::string& item_name
        ) const;

    [[nodiscard]] bool is_active() const;

private:
    bool m_show_messages = false;
    static std::string m_get_key(const std::string& message, bool type);
    static bool m_has_comment_message(const std::string& key);
};

#endif //BOOK_GAME_COMMENT_H
