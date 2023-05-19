#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/warehouse.hpp"
#include "employee.cpp"

void Warehouse::addEmployee(Employee employee){
    // adds the employee to the vector
    Employees.push_back(employee);
}