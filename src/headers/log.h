#ifndef BOOK_GAME_LOG_H
#define BOOK_GAME_LOG_H

#include <iostream>

#include "colormod.h"

namespace log
{
    void msg(int message, const std::string& sep = "\n");

    void msg(
        const std::string& message,
        const std::string& sep = "\n",
        Color::Modifier open = Color::FgDefault,
        Color::Modifier close = Color::FgDefault
    );
    void info(const std::string& message, const std::string& sep = "\n");

    void warning(const std::string& message, const std::string& sep = "\n");

    void error(const std::string& message, const std::string& sep = "\n");

    void ok(const std::string& message, const std::string& sep = "\n");

    void debug(const std::string& message, const std::string& sep = "\n");

    void debug(int message, const std::string& sep = "\n");
}

#endif //BOOK_GAME_LOG_H
