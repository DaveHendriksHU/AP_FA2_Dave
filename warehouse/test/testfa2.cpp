#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "include/pallet.hpp"
#include "include/employee.hpp"
#include "include/shelf.hpp"
#include "include/warehouse.hpp"

// Find all tests in test*.cpp in test/
// ############################################
//  Pallet Test Cases.
// ############################################
TEST_CASE("Get item Name")
{
    Pallet p1 = Pallet("Books", 40, 30);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);
    // std::string name = p1.getItemName();

    REQUIRE(p1.getItemName() == "Books");
    REQUIRE(p2.getItemName() == "Candys");
    REQUIRE(p3.getItemName() == "Bottels");
}

TEST_CASE("Get Remaining Space")
{
    Pallet p1 = Pallet("Books", 40, 30);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);

    REQUIRE(p1.getRemainingSpace() == 10);
    REQUIRE(p2.getRemainingSpace() == 13);
    REQUIRE(p3.getRemainingSpace() == 40);
}

TEST_CASE("Get Item Count")
{
    Pallet p1 = Pallet("Books", 40, 30);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);

    REQUIRE(p1.getItemCount() == 30);
    REQUIRE(p2.getItemCount() == 27);
    REQUIRE(p3.getItemCount() == 0);
}

TEST_CASE("Take one item stock from pallet")
{
    Pallet p1 = Pallet("Books", 40, 30);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);

    REQUIRE(p1.takeOne() == 1);
    REQUIRE(p2.takeOne() == 1);
    REQUIRE(p3.takeOne() == 0);
    REQUIRE(p1.getItemCount() == 29);
    REQUIRE(p2.getItemCount() == 26);
    REQUIRE(p3.getItemCount() == 0);
}

TEST_CASE("PutOne item extra on the pallet")
{
    Pallet p1 = Pallet("Books", 40, 40);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);

    REQUIRE(p1.putOne() == 0);
    REQUIRE(p2.putOne() == 1);
    REQUIRE(p3.putOne() == 1);
    REQUIRE(p1.getItemCount() == 40);
    REQUIRE(p2.getItemCount() == 28);
    REQUIRE(p3.getItemCount() == 1);
}

TEST_CASE("ReallocateEmptyPallet when pallet is empty ")
{
    Pallet p1 = Pallet("Books", 40, 40);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);

    REQUIRE(p1.relocateEmptyPallet("Bikes", 50) == 0);
    REQUIRE(p2.relocateEmptyPallet("Bikes", 50) == 0);
    REQUIRE(p3.relocateEmptyPallet("Bikes", 50) == 1);
    REQUIRE(p1.getItemName() == "Books");
    REQUIRE(p2.getItemName() == "Candys");
    REQUIRE(p3.getItemName() == "Bikes");
    REQUIRE(p1.getRemainingSpace() == 0);
    REQUIRE(p2.getRemainingSpace() == 13);
    REQUIRE(p3.getRemainingSpace() == 50);
}

TEST_CASE("Check the isEmpty Override from icontainer on the pallet")
{
    Pallet p1 = Pallet("Books", 40, 40);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);

    REQUIRE(p1.isEmpty() == 0);
    REQUIRE(p1.isEmpty() == 0);
    REQUIRE(p3.isEmpty() == 1);
}

TEST_CASE("Check the isFull override from icontainer on the pullet")
{
    Pallet p1 = Pallet("Books", 40, 40);
    Pallet p2 = Pallet("Candys", 40, 27);
    Pallet p3 = Pallet("Bottels", 40, 0);

    REQUIRE(p1.isFull() == 1);
    REQUIRE(p2.isFull() == 0);
    REQUIRE(p3.isFull() == 0);
}

// ##############################################
// Test Case's Employee
// ##############################################

TEST_CASE("Get the name of a employee")
{
    Employee e1 = Employee("Co", 1);
    Employee e2 = Employee("Henk", 1);
    Employee e3 = Employee("Marco", 0);

    REQUIRE(e1.getName() == "Co");
    REQUIRE(e2.getName() == "Henk");
    REQUIRE(e3.getName() == "Marco");
}

TEST_CASE("Getting forklift certified info from employee")
{
    Employee e1 = Employee("Co", 1);
    Employee e2 = Employee("Henk", 1);
    Employee e3 = Employee("Marco", 0);

    REQUIRE(e1.getForkliftCertified() == 1);
    REQUIRE(e2.getForkliftCertified() == 1);
    REQUIRE(e3.getForkliftCertified() == 0);
}

TEST_CASE("Setting forklift certified information for a employee")
{
    Employee e1 = Employee("Co", 1);
    Employee e2 = Employee("Henk", 1);
    Employee e3 = Employee("Marco", 0);

    e1.setForkliftCertificate(0);
    e2.setForkliftCertificate(0);
    e3.setForkliftCertificate(1);
    REQUIRE(e1.getForkliftCertified() == 0);
    REQUIRE(e2.getForkliftCertified() == 0);
    REQUIRE(e3.getForkliftCertified() == 1);
}

TEST_CASE("Get Busy and set busy for Employee")
{
    Employee e1 = Employee("Co", 1);
    Employee e2 = Employee("Henk", 1);
    Employee e3 = Employee("Marco", 0);

    REQUIRE(e1.getBusy() == 0);
    REQUIRE(e2.getBusy() == 0);
    REQUIRE(e3.getBusy() == 0);
    e1.setBusy(1);
    e2.setBusy(0);
    e3.setBusy(1);
    REQUIRE(e1.getBusy() == 1);
    REQUIRE(e2.getBusy() == 0);
    REQUIRE(e3.getBusy() == 1);
}

// ###################################
// Shelf Test Cases.
// ###################################
TEST_CASE("Make Empty pallets in shelf")
{
    Shelf emptyShelf = Shelf();

    // Loops over every  pallet in the shelf
    for (int i = 0; i < 4; i++)
    {
        // Test for every pallet if it meets the requirments
        REQUIRE(emptyShelf.pallets[i].getItemName() == "");
        REQUIRE(emptyShelf.pallets[i].getItemCount() == 0);
        REQUIRE(emptyShelf.pallets[i].getRemainingSpace() == 50);
    }
}

TEST_CASE("Test the isEmpty function on Shelves.")
{
    Shelf emptyShelf = Shelf();
    Shelf filledShelf = Shelf();
    filledShelf.pallets = {
        Pallet("Books", 100, 15),
        Pallet("Boxes", 100, 20),
        Pallet("Books", 100, 5),
        Pallet("Boxes", 100, 30)};

    REQUIRE(emptyShelf.isEmpty() == 1);
    REQUIRE(filledShelf.isEmpty() == 0);
}

TEST_CASE()
{
    Shelf emptyShelf = Shelf();
    Shelf filledShelf = Shelf();
    filledShelf.pallets = {
        Pallet("Books", 100, 15),
        Pallet("Boxes", 100, 20),
        Pallet("Books", 100, 5),
        Pallet("Boxes", 100, 30)};
    Shelf FullShelf = Shelf();
    FullShelf.pallets = {
        Pallet("Books", 100, 100),
        Pallet("Boxes", 100, 100),
        Pallet("Books", 100, 100),
        Pallet("Boxes", 100, 100)};

    REQUIRE(emptyShelf.isFull() == 0);
    REQUIRE(filledShelf.isFull() == 0);
    REQUIRE(FullShelf.isFull() == 1);
}

TEST_CASE("Testing of swapping the pallets")
{
    Shelf filledShelf = Shelf();
    filledShelf.pallets = {
        Pallet("Books", 100, 15),
        Pallet("Boxes", 100, 20),
        Pallet("Candys", 100, 5),
        Pallet("Bikes", 100, 30)};
    // Try to swap item 0 and 1 should fail And try 1 and 2 should succeed.
    REQUIRE(filledShelf.swapPallet(0, 1) == 0);
    REQUIRE(filledShelf.swapPallet(1, 2) == 1);

    // Check if the places have been switched
    REQUIRE(filledShelf.pallets[1].getItemName() == "Candys");
    REQUIRE(filledShelf.pallets[2].getItemName() == "Boxes");
}

// #########################
//  Test Cases Ware house
// #########################

TEST_CASE("Test Pick items Takes full amount")
{
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Candys", 100, 40),
        Pallet("Books", 100, 30),
        Pallet("Bikes", 100, 10)};
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.pickItems("Books", 50) == true);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
}
TEST_CASE("Test Pick items Takes a small amount but need 2 pallets")
{
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Candys", 100, 40),
        Pallet("Books", 100, 30),
        Pallet("Bikes", 100, 10)};
    warehouse.addShelf(shelf1);
    REQUIRE(warehouse.pickItems("Books", 25) == true);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 25);
}

TEST_CASE("4 Pallets Take all items")
{
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20),
        Pallet("Books", 100, 40),
        Pallet("Books", 100, 30),
        Pallet("Books", 100, 10)};
    warehouse.addShelf(shelf1);

    REQUIRE(warehouse.pickItems("Books", 100) == true);
    REQUIRE(warehouse.shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.shelves[0].pallets[3].getItemCount() == 0);
}

TEST_CASE("Take all items from more than just one shelf")
{
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
    REQUIRE(warehouse.pickItems("Books", 200) == true);
    // Loops trough all the Shelves in the warehouse
    for (int i = 0; i < 2; i++)
    {
        // loop trouh all the pallets in the shelf
        for (int j = 0; j < 4; j++)
        {
            // Test for every pallet if it meets the requirments
            REQUIRE(warehouse.shelves[i].pallets[j].getItemCount() == 0);
        }
    }
}


TEST_CASE("Try and take more then in storage")
{
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
    // Try and take more then in storage
    REQUIRE(warehouse.pickItems("Books", 201) == false);
}

TEST_CASE("Try and take a item that is not in a shelf")
{
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
    // Try and take more then in storage
    REQUIRE(warehouse.pickItems("Bike", 34) == false);
}