/*
 * cout << "\033[1;31mbold red text\033[0m\n";

 *          foreground background
    black        30         40
    red          31         41
    green        32         42
    yellow       33         43
    blue         34         44
    magenta      35         45
    cyan         36         46
    white        37         47


 * Example of usage
 *
    Color::Modifier red(Color::FgRed);
    Color::Modifier def(Color::FgDefault);
    cout << "This ->" << red << "word" << def << "<- is red." << endl;

 * Created by Joel Sjögren
 * https://stackoverflow.com/a/17469726
 *
 * Color formatting
 * https://misc.flogisoft.com/bash/tip_colors_and_formatting
 */

#ifndef BOOK_GAME_COLORMOD_H
#define BOOK_GAME_COLORMOD_H

#include <ostream>

namespace Color {
    enum Code {
        FgRed      = 31,
        FgGreen    = 32,
        FgYellow   = 33,
        FgBlue     = 34,
        FgDefault  = 39,
        BgRed      = 41,
        BgGreen    = 42,
        BgYellow   = 43,
        BgBlue     = 44,
        BgDefault  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}

        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod)
        {
            return os << "\033[" << mod.code << "m";
        }
    };
}

#endif //BOOK_GAME_COLORMOD_H

