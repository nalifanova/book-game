#include "headers/log.h"

#include <iostream>

#include "headers/colormod.h"

void log::msg(int message, const std::string& sep)
{
    log::msg(std::to_string(message), sep);
}

void log::msg(
    const std::string& message,
    const std::string& sep,
    Color::Modifier open,
    Color::Modifier close
    ) { std::cout << open << message << sep << close; }

void log::info(const std::string& message, const std::string& sep)
{
    log::msg(message, sep, Color::FgBlue);
}

void log::warning(const std::string& message, const std::string& sep)
{
    log::msg(message, sep, Color::FgYellow);
}

void log::error(const std::string& message, const std::string& sep)
{
    log::msg(message, sep, Color::FgRed);
}

void log::ok(const std::string& message, const std::string& sep)
{
    log::msg(message, sep, Color::FgGreen);
}

void log::debug(const std::string& message, const std::string& sep)
{
    log::msg(message, sep, Color::BgGreen, Color::BgDefault);
}

void log::debug(int message, const std::string& sep)
{
    log::debug("DEBUG: " + std::to_string(message), sep);
}
