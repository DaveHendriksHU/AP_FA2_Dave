#include <iostream>
#include "src/include/warehouse.hpp"
#include "src/include/shelf.hpp"
#include "src/include/employee.hpp"
#include "src/include/shelf.hpp"

int main(void)
{
    std::string enter;

    std::cout << "Welkom to the Demo for the warehouse Fa2" << std::endl;
    std::cout << "We shall be making a warehouse first with the following values" << std::endl;
    std::cout << std::endl;

    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 10),
        Pallet("Bikes", 100, 80),
        Pallet("Bikes", 100, 2),
        Pallet("CellPhones", 100, 55)};
    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Candys", 100, 40),
        Pallet("Bikes", 100, 30),
        Pallet("Books", 100, 10)};

    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addEmployee(Employee("Bob", true));

    for (int i = 0; i < 2; i++)
    {
        // loop
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {
            // Test for every pallet if it meets the requirments
            // REQUIRE(warehouse.shelves[i].pallets[j].getItemCount() == 0);
            std::cout << "-->Pallet: " << j << " item: " << warehouse.shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }
    std::cout << "We will also add a employee to work in our warehous and he is certified How Nice !" << std::endl;
    std::cout << "Next up we shall rearange both shelves | Pres enter to continue" << std::endl;

    std::getline(std::cin, enter);
    std::cin.clear();

    std::cout << "Now you may not have seen it but we shall print them out so you can see | Pres enter to continue." << std::endl;
    warehouse.rearrangeShelf(warehouse.shelves[0]);
    warehouse.rearrangeShelf(warehouse.shelves[1]);
    std::getline(std::cin, enter);
    std::cin.clear();
    std::cout << std::endl;

    for (int i = 0; i < 2; i++)
    {
        // loop
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {

            std::cout << "-->Pallet: " << j << " item: " << warehouse.shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    std::cout << "Now lets say some one wants to buy 40 books." << std::endl;
    std::cout << "This would in our case be everyting" << std::endl;
    std::cout << "Now lets show if all the pallets with books have gone to zero | Pres enter to continue" << std::endl;

    std::getline(std::cin, enter);
    std::cin.clear();

    warehouse.pickItems("Books", 40);

    for (int i = 0; i < 2; i++)
    {
        // loop
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {

            std::cout << "-->Pallet: " << j << " item: " << warehouse.shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    std::cout << "Now lets say we want to add 1 item to every pallet we can also do that" << std::endl;
    std::cout << "Pres enter to continue" << std::endl;
    std::getline(std::cin, enter);
    std::cin.clear();

    for (int i = 0; i < 2; i++)
    {
        // loop
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {
            warehouse.shelves[i].pallets[j].putOne();
            std::cout << "-->Pallet: " << j << " item: " << warehouse.shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    std::cout << "Now we can also take them away again: Pres enter to continue" << std::endl;
    std::getline(std::cin, enter);
    std::cin.clear();

    for (int i = 0; i < 2; i++)
    {
        // loop
        std::cout << "Shelf " << i << std::endl;
        for (int j = 0; j < 4; j++)
        {
            warehouse.shelves[i].pallets[j].takeOne();
            std::cout << "-->Pallet: " << j << " item: " << warehouse.shelves[i].pallets[j].getItemName() << " Amount: " << warehouse.shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "This whas a small demo on what we can do with the functions written in this project" << std::endl;
    std::cout << std::endl;
}
