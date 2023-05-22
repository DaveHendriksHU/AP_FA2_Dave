#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/pallet.hpp"

Pallet::Pallet()
{
}

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount)
{
    this->itemName = itemName;
    this->itemCapacity = itemCapacity;
    this->itemName = itemCount;
}

std::string Pallet::getItemName() const
{
    return itemName;
}
int Pallet::getItemCount() const
{
    return itemCount;
}
int Pallet::getRemainingSpace() const
{
    return itemCapacity - itemCount;
}
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
bool Pallet::putOne()
{
    // Simply add 1 to the total item count
    itemCount = itemCount + 1;
    return 1;
}
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