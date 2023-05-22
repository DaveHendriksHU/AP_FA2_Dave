#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/shelf.hpp"

Shelf::Shelf()
{
    // Create 4 empty pallets
    for (int i = 0; i < 4; i++)
    {
        pallets[i] = Pallet();
    }
}

bool Shelf::swapPallet(int slot1, int slot2)
{

    // Checks if the first slot pallet has a higher item count than slot 2.
    if (pallets[slot1].getItemCount() > pallets[slot2].getItemCount())
    {
        // If true swap the 2 from place and return True
        std::swap(pallets[slot1], pallets[slot2]);
        return true;
    }
    else
    {
        // Return false if the above statment is not true
        return false;
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