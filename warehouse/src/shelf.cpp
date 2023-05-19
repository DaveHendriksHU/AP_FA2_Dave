#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "shelf.hpp"

bool Shelf::swapPallet(int slot1, int slot2){

    if (Pallets[slot1].getItemCount() > Pallets[slot2].getItemCount()){
        std::swap(Pallets[slot1], Pallets[slot2]);
        return 1;
    }else{
        return 0;
    }
}