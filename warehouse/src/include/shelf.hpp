#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <array>
#include "pallet.hpp"

class Shelf: public Icontainer
{
public:
    Shelf();
    bool swapPallet(int slot1, int slot2);
    std::array<Pallet, 4> pallets;
    bool isEmpty() override;
    bool isFull() override;
};