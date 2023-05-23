#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "include/employee.hpp"

/**
 * @brief Construct a new Employee:: Employee object
 *
 */
Employee::Employee()
{
}

/**
 * @brief Construct a new Employee:: Employee object
 * 
 * @param name Name of employee that needs to be set.
 * @param forkliftCertificate If employee is certified yes or no
 */
Employee::Employee(std::string name, bool forkliftCertificate)
{
    this->name = name;
    this->forkliftCertificate = forkliftCertificate;
    this->busy = 0;
}
/**
 * @brief Gets the name from a employee
 * 
 * @return std::string A string that contains the employee's name.
 */
std::string Employee::getName()
{
    return name;
}
/**
 * @brief Gets the busy status.
 * 
 * @return true if the employee is busy
 * @return false if the employee is not busy
 */
bool Employee::getBusy()
{
    return busy;
}
/**
 * @brief Set if a employee is busy or not.
 * 
 * @param busy True or False is given and sets the busy status for a employee
 */
void Employee::setBusy(bool busy)
{
    this->busy = busy;
}
/**
 * @brief Get certification information from a employee
 * 
 * @return true If employee is certified.
 * @return false if employee is not certified.
 */
bool Employee::getForkliftCertified()
{
    return forkliftCertificate;
}
/**
 * @brief Sets the status of certification of a employee.
 * 
 * @param forkliftcertificate The new True or False if a employee is certified or not.
 */
void Employee::setForkliftCertificate(bool forkliftcertificate)
{
    this->forkliftCertificate = forkliftcertificate;
}