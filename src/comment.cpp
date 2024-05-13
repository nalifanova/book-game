#include "headers/comment.h"

#include <iostream>

std::map<std::string, std::string> comment_messages = {
    {"luck0", "You are NOT lucky!"},
    {"luck1", "You are lucky!"},
    {"charisma0", "Your charisma is not enough this time."},
    {"charisma1", "You are so charming!"},
    {"reaction0", "Your reaction was too slow."},
    {"reaction1", "Your reaction helped you."},

    {"inventory0", "You have no space in your backpack. Remove "
                   "something first."},
    {"inventory-0", "is not in your backpack. You don't have it."},
    {"inventory-1", "was removed from your backpack."},
    {"inventory+1", "was successfully added to your backpack."}

};

// public methods
Comment::Comment() = default;

Comment::~Comment() = default;

void Comment::turn_messages_off()
{
    m_show_messages = false;
}

void Comment::turn_messages_on()
{
    m_show_messages = true;
}

bool Comment::is_active() const
{
    return m_show_messages;
}

void Comment::text(const std::string& message, const std::string& sep) const
{
    if (!m_show_messages) return;
    log::msg(message, sep);
}

void Comment::warning(const std::string& message, const std::string& sep) const
{
    if (!m_show_messages) return;
    log::error(message, sep);
}


void Comment::message(const std::string& message, bool type) const
{
    if (!m_show_messages) return;

    std::string key = m_get_key(message, type);
    if (m_has_comment_message(key))
    {
        log::msg(comment_messages[key]);
    }
}

void Comment::message(
    const std::string& message,
    bool type,
    const std::string& item_name
) const
{
    if (!m_show_messages) return;

    std::string key = m_get_key(message, type);
    if (m_has_comment_message(key))
    {
        log::msg(item_name + " " + comment_messages[key]);
    }
}

// private methods
std::string Comment::m_get_key(const std::string& message, bool type)
{
    return message + std::to_string(type);
}

bool Comment::m_has_comment_message(const std::string& key)
{
    // == - not found, != found
    return comment_messages.find(key) != comment_messages.end();
}
