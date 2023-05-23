#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/shelf.hpp"

/**
 * @brief Construct a new Shelf:: Shelf object with empty pallets
 * 
 */
Shelf::Shelf()
{
    // Create 4 empty pallets
    for (int i = 0; i < 4; i++)
    {
        pallets[i] = Pallet();
    }
}

/**
 * @brief Swaps 2 pallets if the first has a higher item count than the other one.
 * 
 * @param slot1 pallet number 1
 * @param slot2 pallet numeber 2
 * @return true if swapping the 2 pallets is done.
 * @return false  if we can't swap the 2 pallets.
 */
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
/**
 * @brief Checks if the shelf is full of empty pallets
 * 
 * @return true if the shelf is indeed empty
 * @return false if the shelf still has a pallet with the item on it.
 */
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


/**
 * @brief Will check if all the pallets have adleast some items on it.
 * 
 * @return true if all pallets have adleast one item.
 * @return false if there is a pallet with zero items on it.
 */
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