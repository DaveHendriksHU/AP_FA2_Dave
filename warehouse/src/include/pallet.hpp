#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Icontainer.hpp"

class Pallet : public Icontainer 
{
private:
    std::string itemName;

public:
    // std::string itemName;
    int itemCount;
    int itemCapacity;
    Pallet();
    Pallet(std::string itemName, int itemCapacity, int itemCount);
    std::string getItemName() const;
    int getItemCount() const;
    int getRemainingSpace() const;
    bool relocateEmptyPallet(std::string itemName, int itemCapacity);
    bool takeOne();
    bool putOne();
    bool isEmpty() override;
    bool isFull() override;
};
