#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "include/pallet.hpp"
#include "include/employee.hpp"

// Find all tests in test*.cpp in test/

TEST_CASE("test"){
    REQUIRE(0==0);
}
//############################################
// Pallet Test Cases.
//############################################
TEST_CASE("Get item Name"){
    Pallet p1 = Pallet("Books",40,30);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);
    // std::string name = p1.getItemName();

    REQUIRE(p1.getItemName() == "Books");
    REQUIRE(p2.getItemName() == "Candys");
    REQUIRE(p3.getItemName() == "Bottels");
}

TEST_CASE("Get Remaining Space"){
    Pallet p1 = Pallet("Books",40,30);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);

    REQUIRE(p1.getRemainingSpace() == 10);
    REQUIRE(p2.getRemainingSpace() == 13);
    REQUIRE(p3.getRemainingSpace() == 40);
}

TEST_CASE("Get Item Count"){
    Pallet p1 = Pallet("Books",40,30);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);

    REQUIRE(p1.getItemCount() == 30);
    REQUIRE(p2.getItemCount() == 27);
    REQUIRE(p3.getItemCount() == 0);
}

TEST_CASE("Take one item stock from pallet"){
    Pallet p1 = Pallet("Books",40,30);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);

    REQUIRE(p1.takeOne() == 1);
    REQUIRE(p2.takeOne() == 1);
    REQUIRE(p3.takeOne() == 0);
    REQUIRE(p1.getItemCount() == 29);
    REQUIRE(p2.getItemCount() == 26);
    REQUIRE(p3.getItemCount() == 0);
}

TEST_CASE("PutOne item extra on the pallet"){
    Pallet p1 = Pallet("Books",40,40);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);

    REQUIRE(p1.putOne() == 0);
    REQUIRE(p2.putOne() == 1);
    REQUIRE(p3.putOne() == 1);
    REQUIRE(p1.getItemCount() == 40);
    REQUIRE(p2.getItemCount() == 28);
    REQUIRE(p3.getItemCount() == 1);
}

TEST_CASE("ReallocateEmptyPallet when pallet is empty "){
    Pallet p1 = Pallet("Books",40,40);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);

    REQUIRE(p1.relocateEmptyPallet("Bikes" ,50) == 0);
    REQUIRE(p2.relocateEmptyPallet("Bikes" ,50) == 0);
    REQUIRE(p3.relocateEmptyPallet("Bikes" ,50) == 1);
    REQUIRE(p1.getItemName() == "Books");
    REQUIRE(p2.getItemName() == "Candys");
    REQUIRE(p3.getItemName() == "Bikes");
    REQUIRE(p1.getRemainingSpace() == 0);
    REQUIRE(p2.getRemainingSpace() == 13);
    REQUIRE(p3.getRemainingSpace() == 50);
    
}

TEST_CASE("Check the isEmpty Override from icontainer on the pallet"){
    Pallet p1 = Pallet("Books",40,40);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);


    REQUIRE(p1.isEmpty() == 0);
    REQUIRE(p1.isEmpty() == 0);
    REQUIRE(p3.isEmpty() == 1);
}

TEST_CASE("Check the isFull override from icontainer on the pullet"){
    Pallet p1 = Pallet("Books",40,40);
    Pallet p2 = Pallet("Candys",40,27);
    Pallet p3 = Pallet("Bottels",40,0);

    REQUIRE(p1.isFull() == 1);
    REQUIRE(p2.isFull() == 0);
    REQUIRE(p3.isFull() == 0);
}


//##############################################
//Test Case's Employee
//##############################################

Test_CASE("Get the name of a employee"){
    Employee()
}