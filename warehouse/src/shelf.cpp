#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/shelf.hpp"

Shelf::Shelf(){
    
}

bool Shelf::swapPallet(int slot1, int slot2){

    if (pallets[slot1].getItemCount() > pallets[slot2].getItemCount()){
        std::swap(pallets[slot1], pallets[slot2]);
        return 1;
    }else{
        return 0;
    }
}