#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"

class Warehouse
{
private:
    std::vector<Employee> Employees;
public:
    std::vector<Shelf> shelves;

    Warehouse();
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickItems(std::string itemName, int itemCount);
};
