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
    // Loops over all the pallets
    for (const auto& pallet : pallets)
    {
        // Checks if the pallet has a item count higher than 0.
        if (pallet.getItemCount() != 0)
        {
            // if one is found higher than 0, Return False.
            return false; 
        }
    }
    // Returns True if all the pallets have a itemcount of 0
    return true; 
}
}
bool Shelf::isFull()
{
    // Loops over all the pallets
    for (const auto& pallet : pallets)
    {
        // Checks if one of the pallet still has remaining space.
        if (pallet.getRemainingSpace() != 0)
        {
            // One Pallet is not filled yet.
            return false; 
        }
    }
    // all Pallets are full.
    return true; 
};