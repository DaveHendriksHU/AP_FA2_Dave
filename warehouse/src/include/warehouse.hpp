#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"

class warehouse
{
private:
    /* data */
public:
    std::vector<Employee> Employees;

    warehouse();
    void addEmployee(Employee employee);
};
