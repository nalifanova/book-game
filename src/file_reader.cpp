#include "headers/file_reader.h"

#include <filesystem>
#include <fstream>
#include <sstream> // std::stringstream
#include <string>

#include "headers/globals.h"
#include "headers/log.h"

std::string create_file_path(const std::string& paragraph_number)
{
    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path paragraph_dir = cwd.parent_path() /
            "src" / "data" / "paragraphs" ;

    std::string filename = paragraph_dir.string() +
                           "/" + paragraph_number + ".txt";

    return filename;
}

void get_string_from_file(std::string& player_number, std::string& content)
{
    std::string file_path = create_file_path(player_number);
    std::ifstream file(file_path, std::ios_base::binary);

    if (file.fail()) {
        // throw std::runtime_error("Failed to open file");
        log::error("Looks like the file " + file_path +
                   " cannot be read/found.");
        file.clear();
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    content = buffer.str();
    file.close();
}

void read_content(std::string& content, std::vector<int>& options,
                  std::string& optional_item, char& special_symbol)
{
    int char_counter = 1;
    std::string str_number;
    bool break_line = false;
    bool has_needed_item = false;

    for(char& ch : content)
    {
        if (ch == '\n') char_counter = 1;
        else if (ch == '#' || ch == '%' || ch == '^') special_symbol = ch;
        else if (ch == '`') has_needed_item ^= true; // toggle value


        if (char_counter % row::kCliOutputLineWidth == 0) break_line = true;
        if (ch == ' ' && break_line) // break the line
        {
            std::cout << std::endl;
            break_line = false;
            char_counter = 0;
        }
        else
        {
            // block to retrieve numbers from the text
            if (isdigit(ch) || ch == '+' || ch == '-')
            {
                str_number.push_back(ch);
            }
            else
            {
                if (!str_number.empty())
                {
                    if (str_number[0] != '+' && str_number[0] != '-')
                    {
                        // skip +N or -N
                        options.push_back(stoi(str_number));
                    }
                    str_number = "";
                }
            } // end of block

            // block to retrieve an item that might help
            if (has_needed_item)
            {
                if (ch != '`') optional_item.push_back(ch);
            } // end of block
            std::cout << ch;
        }
        char_counter++;
    }
}


// Might be deprecated
std::string open_file(std::string& filename)
{
    std::ifstream file(filename);
    std::string content;

    if (!file.is_open())
    {
        log::error("Looks like the file " + filename +
                    " cannot be read/found.");
        file.close();
        return "";
    }

    while (std::getline(file, content))
    {
        content+= content;
    }
    file.close();

    return content;
}
