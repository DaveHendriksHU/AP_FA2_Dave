#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/pallet.hpp"

/**
 * @brief Construct a new Pallet:: Pallet object With standard values.
 * 
 */
Pallet::Pallet()
{
    this->itemName = "";
    this->itemCount = 0;
    this->itemCapacity = 50;
}

/**
 * @brief Construct a new Pallet:: Pallet object
 * 
 * @param itemName Item that can be found on the pallet
 * @param itemCapacity The max capacity of the pallet with the item on it.
 * @param itemCount The amount of the item on the pallet
 */
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount)
{
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemCount = itemCount;
}
/**
 * @brief Gets the item name that is on a pallet
 * 
 * @return std::string Returns the name of the item on the pallet.
 */
std::string Pallet::getItemName() const
{
    return itemName;
}
/**
 * @brief Get the amount of items on the pallet.
 * 
 * @return int returns the item count.
 */
int Pallet::getItemCount() const
{
    return itemCount;
}
/**
 * @brief Gets the amount of items that can still be fitted on the pallet
 * 
 * @return int Returns the remainingSpace amount.
 */
int Pallet::getRemainingSpace() const
{
    return itemCapacity - itemCount;
}

/**
 * @brief Gives a empty pallet a new item name and item Capacity
 * 
 * @param itemName The name the pallet shall now get
 * @param itemCapacity The new max amount of items that can fit on the pallet
 * @return true if the pallets has been relocated.
 * @return false if there are stil remaining items on the pallet from the diffrent item.
 */
bool Pallet::relocateEmptyPallet(std::string itemName, int itemCapacity)
{
    if (itemCount == 0)
    {
        this->itemName = itemName;
        this->itemCapacity = itemCapacity;

        return 1;
    }
    else
    {
        return 0;
    }
}
/**
 * @brief Takes one item of the pallet
 * 
 * @return true if it can take 1 of.
 * @return false if there are not items to take.
 */
bool Pallet::takeOne()
{
    // Checks if the itemCount is not already 0.
    if (itemCount > 0)
    {
        // If item is not already zero remove 1 from the total value and return 1
        itemCount = itemCount - 1;
        return 1;
    }
    else
    {
        // If the item value is already on 0 we can't take any from it.
        // Then we return 0.
        return 0;
    }
}
/**
 * @brief Puts 1 item on the pallet
 * 
 * @return true if we can put a item on the pallet.
 * @return false if the itemcount from the pallets had reached the item capacity. We can not put a extra one on it.
 */
bool Pallet::putOne()
{
    // Check if the itemcount is already add itemCapacity
    if (itemCount == itemCapacity)
    {
        return 0;
    }
    else
    {
        // Simply add 1 to the total item count
        itemCount = itemCount + 1;
        return 1;
    }
}
/**
 * @brief Checks if a pallet is empty
 * 
 * @return true if the item count of the pallet is 0
 * @return false if there are still items on the pallet
 */
bool Pallet::isEmpty()
{
    if (itemCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief Checks if the pallet is full
 * 
 * @return true if the pallet itemCount is the same as the pallet itemCapacity
 * @return false if the itemCount is not the same as itemCapacity.
 */
bool Pallet::isFull()
{
    if (itemCount == itemCapacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}