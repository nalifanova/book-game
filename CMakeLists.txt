cmake_minimum_required(VERSION 3.28)
project(book_game)

set(BOOK_GAME_VERSION_MAJOR 0)
set(BOOK_GAME_VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
    set(CPP_VERSION -std=gnu++${CMAKE_CXX_STANDARD})
elseif (APPLE)
    set(CPP_VERSION -std=c++${CMAKE_CXX_STANDARD})
else ()
    set(CPP_VERSION -std=c++${CMAKE_CXX_STANDARD})
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-reorder ${CPP_VERSION}")

add_executable(book_game
        src/main.cpp
        src/main_test.h
        src/headers/colormod.h
        src/headers/log.h
        src/headers/creature.h
        src/headers/comment.h
        src/log.cpp
        src/creature.cpp
        src/comment.cpp
        src/headers/inventory.h
        src/inventory.cpp
        src/headers/actions.h
        src/actions.cpp
        src/random.cpp
        src/headers/random.h
        src/headers/object_factory.h
        src/object_factory.cpp
        src/headers/path.h
        src/path.cpp
        src/game_steps.cpp
        src/headers/game_steps.h
        src/headers/item.h
        src/item.cpp
        src/headers/game_plays.h
        src/game_plays.cpp
        src/headers/file_reader.h
        src/file_reader.cpp
        src/headers/game.h
        src/game.cpp
)
