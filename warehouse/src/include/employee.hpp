#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>

class Employee
{
private:
    std::string name;


public:
    bool busy;
    bool forkliftCertificate;
    Employee();
    Employee(std::string name, bool forkliftCertificate);
    std::string getName();
    bool getBusy();
    void setBusy(bool busy);
    bool getForkliftCertified();
    void setForkliftCertificate(bool forkliftCertificate);
};
