# book-game

## Idea
I started learning C++ on April 14, 2024. To make the learning process more 
enjoyable, I decided to create a game based on a book that was popular in the 
90s. The book represents a kind of RPG game with limited skills, characteristics, 
combat, etc., but it is still enjoyable to play. The book is in Russian, but I 
might translate it to English once I start learning how to use translation for 
projects in C++.

## Description
Game Description: Simply run the `main.cpp` file and enjoy the experience.

P.S.: I'll provide additional information about the book used and its author.
Furthermore, more paragraphs will be added in due time (it's not going to be 
very soon though).

## How-to

## Dev Notes
I'm using CLion as my IDE, and I endeavor to adhere to its provided guidelines, 
which aid with the code style and project structure. Thus, the code style and 
related aspects might not strictly adhere to established standards, if any 
exist (😅).
Nonetheless, I consult authoritative pillars such as the
([C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html)) 
and
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html) 
to ensure that the code remains readable and consistent.


### Guide style
* Each row of text in your code should be at most 80 characters long.
* Use a .cpp suffix for code files and .h for interface files 
  [NL.27](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html#Rl-file-suffix)
* [Names and order of includes](https://google.github.io/styleguide/cppguide.html#Names_and_Order_of_Includes)
  Related header, C system headers, C++ standard library headers, other headers
* The names of all types — classes, structs, type aliases, enums, and type
  template parameters start with a capital letter and have a capital letter
  for each new word, with no underscores: MyExcitingClass, MyExcitingEnum.
* The names of variables (including function parameters) and data members are
  snake_case. E.g.: a_struct_data_member, a_class_data_member, a_variable
* Functions and methods should also use snake_case.
* Note! While I prefer using all uppercase for constants, both guides recommend 
  using it for macros. Therefore, I'll adhere to the 
  (Google rule)[https://google.github.io/styleguide/cppguide.html#Constant_Names]
  use `const int kDaysInAWeek = 7`. It's important for me to clearly indicate 
  that it is a constant.
