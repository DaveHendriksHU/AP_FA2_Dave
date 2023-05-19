#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "employee.hpp"


Employee::Employee(std::string name, bool forkliftCertificate){
    this->name = name;
    this->forkliftCertificate = forkliftCertificate;
}
std::string Employee::getName() const{
    return name;
}
bool Employee::getBusy() const{
    return busy;
}
void Employee::setBusy(bool busy){
    busy = busy;
}
bool Employee::getForkliftCertified() const{
    return forkliftCertificate;
}
void Employee::setForkliftCertificate(bool forkliftCertificate){
    forkliftCertificate = forkliftCertificate;
}