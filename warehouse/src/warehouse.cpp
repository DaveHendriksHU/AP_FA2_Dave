#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/warehouse.hpp"
#include "include/employee.hpp"

/**
 * @brief Construct a new Warehouse:: Warehouse object
 * 
 */
Warehouse::Warehouse()
{
}

/**
 * @brief 
 * 
 * @param employee The employee that needs to be added
 */
void Warehouse::addEmployee(Employee employee)
{
    // adds the employee to the vector
    Employees.push_back(employee);
}
/**
 * @brief The function AddShelf will add a shelf to the warehouse
 * 
 * @param shelf The shelf that need to be added 
 */
void Warehouse::addShelf(Shelf shelf)
{
    // adds a shelf to to the total amount of shelves
    shelves.push_back(shelf);
}
/**
 * @brief The funtion rearangeShelf() Will sort the pallets from lowest to highest itemcount.
 * 
 * @param shelf Gives a pointer to a specific shelf in the warehouse.
 * @return true will be returned if all the pallets are correctly sorted.
 * @return false Will returned if the employee is busy or not certified.
 */
bool Warehouse::rearrangeShelf(Shelf &shelf)
{
    // Chat Gpt helped out on this function :)
    //  Checks if the employee is certified and not busy.
    if (Employees[0].getForkliftCertified() == 1 && Employees[0].getBusy() == 0)
    {

        // We assigne the True to swapped var to enter the while loop.
        bool swapped = true;

        while (swapped == true)
        {
            // The first thing we do is assume no swaps will be made and change swapped to False.
            swapped = false;

            // Now we wil make a for loop and keep swapping every pallet next to the other. And checking the return,
            // From the swapPallet function.
            for (int i = 0; i < 3; ++i)
            {
                // If the function actually swaps pallets
                if (shelf.swapPallet(i, i + 1) == true)
                {
                    // Set swapped back to true if the above statment is true.
                    swapped = true;
                }
            }
        }
        // return True
        return true;
    }
    // return False
    return false;
}

/**
 * @brief The Function PickItems will pick items out of pallets that match the itemName.
 * 
 * @param itemName Name from the items that needs to be picked.
 * @param itemCount Amount that needs to be picked from the item.
 * @return true Wil be returned if there where enough items found to be picked.
 * @return false Wil be returned if There are not enough items or the item does not exist
 */
bool Warehouse::pickItems(std::string itemName, int itemCount)
{
    int amountOfItemsInStorage = 0;
    for (Shelf& shelf : shelves)
    {
        for (const Pallet& pallet : shelf.pallets)
        {
            // Check if the pallet has the desired item name
            if (pallet.getItemName() == itemName)
            {
                // Add the item count to the total
                amountOfItemsInStorage += pallet.getItemCount();
            }
        }
    }
    // Check if the requested itemCount is valid and there are enough items in storage
    if (itemCount <= 0 || amountOfItemsInStorage < itemCount)
    {
        return false;
    }

    // loop over each shelf
    for (Shelf& shelf : shelves)
    {
        // Loop over each pallet
        for (Pallet& pallet : shelf.pallets)
        {
            // Check if the pallet has the item name in it.
            if (pallet.getItemName() == itemName)
            {
                // Here we take items from the pallet until one of the two reaches Zero.
                // This means that either we have collected enough items from the pallet, Or there are no items left on the pallet.
                while (itemCount > 0 && pallet.getItemCount() > 0)
                {
                    // Here we update the itemCount from the pallet. this wil return true.
                    if (pallet.takeOne() == true)
                    {
                        // Here We lower the count of the itemCount given as a parameter in the function.
                        itemCount--;
                    }
                }
            }
            
            // Check if we have taken enough items
            if (itemCount == 0)
            {
                return true;
            }
        }
    }
}