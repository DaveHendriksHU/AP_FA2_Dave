#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "pallet.hpp"

class Shelf
{
private:
    /* data */
public:
    Shelf();
    bool swapPallet(int slot1, int slot2);
};