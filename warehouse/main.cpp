#include <iostream>
#include "src/include/warehouse.hpp"
#include "src/include/shelf.hpp"
#include "src/include/employee.hpp"
#include "src/include/shelf.hpp"


int main(void){
    
    std::cout << "Hello world" << std::endl;

    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Books", 100, 40),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 10)};
    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Books", 100, 40),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 10)};


    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);

    warehouse.pickItems("Books", 200);

    for (int i = 1; i < 3; i++){
        // loop
        std::cout << "Shelf" << i << std::endl;
        for (int j = 1; j < 5; j++)
        {
            // Test for every pallet if it meets the requirments
            // REQUIRE(warehouse.shelves[i].pallets[j].getItemCount() == 0); 
            std::cout << "Pallet = " << j << "Amount in pallet = " << warehouse.shelves[i].pallets[j].getItemCount() << std::endl;
        }
    }

    // Warehouse warehouse = Warehouse();

    // Shelf emptyShelf = Shelf();

    // Warehouse warehouse = Warehouse();
    // Shelf shelf1 = Shelf();
    // shelf1.pallets = {
    //     Pallet("Books", 100, 20), 
    //     Pallet("Candys", 100, 40), 
    //     Pallet("Books", 100, 30), 
    //     Pallet("Bikes", 100, 10)
    // };
    // warehouse.addShelf(shelf1);
    // warehouse.pickItems("Books",50);

    // for (int i = 0; i < 4; i++)
    // {
    //     std::cout << warehouse.shelves[0].pallets[i].getItemCount() << std::endl;
    // }

    // Shelf filledShelf = Shelf();
    // filledShelf.pallets = {
    //     Pallet("Books", 100, 15), 
    //     Pallet("Boxes", 100, 20), 
    //     Pallet("Books", 100, 5), 
    //     Pallet("Boxes", 100, 30)
    // };

    
    // for (int i = 0; i < 4; i++)
    // {
    //     std::cout << filledShelf.pallets[i].getItemName() << std::endl;
    // }

}
