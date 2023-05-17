#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>

class Pallet
{
private:
    std::string itemName;

public:
    int itemCount;
    int itemCapacity;
    Pallet();
    Pallet(std::string name, int itemCapacity, int itemCount);
    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();
    bool relocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
};
