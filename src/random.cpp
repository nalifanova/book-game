/*
 * File: random.cpp
 * ----------------
 * This file implements the random.h interface.
 */
#include "headers/random.h"

#include <cstdlib> // rand
#include <ctime>
#include <iostream>

int random_integer(const int low, const int high)
{
    init_random_seed();
    double d = rand() / (static_cast<double>(RAND_MAX) + 1);
    double s = d * (static_cast<double>(high) - low + 1);
    return static_cast<int>(floor(low + s));
}

void set_random_seed(const int seed)
{
    init_random_seed();
    srand(seed);
}

void init_random_seed()
{
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<int>(time(nullptr)));
        initialized = true;
    }
}
