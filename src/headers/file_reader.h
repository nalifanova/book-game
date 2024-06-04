#ifndef BOOK_GAME_FILE_READER_H
#define BOOK_GAME_FILE_READER_H

#include <iostream>
#include <vector>

#include "inventory.h"

std::string create_file_path(const std::string& paragraph_number);

void get_string_from_file(std::string& player_number, std::string& content);

void read_content(
    std::string& content,
    std::vector<int>& options,
    std::string& optional_item,
    char& special_symbol
    );

// might be deprecated
std::string open_file(std::string& filename);

#endif //BOOK_GAME_FILE_READER_H
