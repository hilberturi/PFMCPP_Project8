#include "SemiTruck.h"
#include <iostream>

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

SemiTruck::~SemiTruck() = default;

void SemiTruck::pullOver()
{
    std::cout << name << ": pull over!" << std::endl;
}

void SemiTruck::headlightFlasher()
{
    std::cout << name << ": headlight flasher!" << std::endl;
    
}


