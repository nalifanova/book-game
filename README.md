# Book Game "Maze of Concealed Death"

<div align="center">
  
[![RPG](https://img.shields.io/badge/Book-Game-yellow.svg?logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZlcnNpb249IjEiIHdpZHRoPSI2MDAiIGhlaWdodD0iNjAwIj48cGF0aCBkPSJNMTI5IDExMWMtNTUgNC05MyA2Ni05MyA3OEwwIDM5OGMtMiA3MCAzNiA5MiA2OSA5MWgxYzc5IDAgODctNTcgMTMwLTEyOGgyMDFjNDMgNzEgNTAgMTI4IDEyOSAxMjhoMWMzMyAxIDcxLTIxIDY5LTkxbC0zNi0yMDljMC0xMi00MC03OC05OC03OGgtMTBjLTYzIDAtOTIgMzUtOTIgNDJIMjM2YzAtNy0yOS00Mi05Mi00MmgtMTV6IiBmaWxsPSIjZmZmIi8+PC9zdmc+)]()
[![C++ - Version](https://img.shields.io/badge/C++-17-blue.svg?style=flat&logo=c%2B%2B)](https://en.cppreference.com/w/cpp/compiler_support/20)
![GitHub last commit](https://img.shields.io/github/last-commit/nalifanova/book-game?display_timestamp=author&style=flat&logo=github)


</div>

## Idea
When I started learning C++, my guide was a book "Programming 
Abstractions in C++ by Eric S. Roberts Stanford University Spring Quarter 2012".
It took me a month to proceed and get acquainted with very basics. In a month,
on April 14, to make the learning process more enjoyable, I decided to create a 
game based on a book that was popular in the 90s. 

The book represents a kind of RPG game with limited skills, characteristics, 
combat, etc., but it is still enjoyable to play. The book is in Russian, but it
has been translated to English with great help of ChatGPT 3.5.

### Book itself
You can familiarize yourself with the book by following the link
["Лабиринт затаившейся смерти"](https://avidreaders.ru/read-book/labirint-zataivsheysya-smerti-kniga-igra.html).
Just keep in mind that the book is in Russian.
When I was a child, I loved to read/play books by Dmitry Braslavsky, like:
- Black Castle Dungeons
- Captain Shelton's Mystery
- Maze of Concealed Death
- etc.

## Description
Game Description: Simply run the `main.cpp` file and enjoy the experience.

P.S.: More paragraphs will be added in due time (it's not going to be 
very soon though).

## How-to 

### Play the game

The intro for the game can be found here - [Game Intro](GAMEINTRO.md).

If you are interested in [Game Rules](GAMERULES) and want to find out how to 
play the book game, go for it. Just keep in mind that these rules are for the 
pure book game (text of which you can find in [paragraphs](data/paragraphs) 
folder). 
The project automated a huge part of the rules, thus you can just skip them.


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
  [Google rule](https://google.github.io/styleguide/cppguide.html#Constant_Names)
  use `const int kDaysInAWeek = 7`. It's important for me to clearly indicate 
  that it is a constant.
