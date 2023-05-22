#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/warehouse.hpp"
#include "include/employee.hpp"

Warehouse::Warehouse()
{
}
void Warehouse::addEmployee(Employee employee)
{
    // adds the employee to the vector
    Employees.push_back(employee);
}
void Warehouse::addShelf(Shelf shelf)
{
    // adds a shelf to to the total amount of shelves
    shelves.push_back(shelf);
}
bool Warehouse::rearrangeShelf(Shelf& shelf)
{
    return 0;
}
bool Warehouse::pickItems(std::string itemName, int itemCount)
{
    return 0;
}