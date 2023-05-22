#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/shelf.hpp"

Shelf::Shelf()
{
    for (int i = 0; i < 4; i++)
    {
        pallets[i] = Pallet();
    }
    
}

bool Shelf::swapPallet(int slot1, int slot2)
{

    if (pallets[slot1].getItemCount() > pallets[slot2].getItemCount())
    {
        std::swap(pallets[slot1], pallets[slot2]);
        return 1;
    }
    else
    {
        return 0;
    }
}
bool Shelf::isEmpty()
{
    if (pallets.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Shelf::isFull()
{
    if (pallets.size() == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
};