#include <iostream>
#include "src/include/warehouse.hpp"
#include "src/include/shelf.hpp"



int main(void){
    
    std::cout << "Hello world" << std::endl;

    Warehouse warehouse = Warehouse();

    Shelf emptyShelf = Shelf();

    // for (int i = 0; i < 4; i++)
    // {
    //     std::cout << emptyShelf.pallets[i].getRemainingSpace() << std::endl;
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
