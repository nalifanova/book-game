/*
 * File: random.cpp
 * ----------------
 * This file implements the random.h interface.
 */
#include "headers/random.h"

#include <cstdlib> // rand
#include <ctime>
#include <iostream>

int random_integer(int low, int high)
{
    init_random_seed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

void set_random_seed(int seed)
{
    init_random_seed();
    srand(seed);
}

void init_random_seed()
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(int(time(NULL)));
        initialized = true;
    }
}
