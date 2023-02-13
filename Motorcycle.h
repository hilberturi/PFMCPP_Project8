#pragma once

#include "Vehicle.h"
#include <limits>

struct Motorcycle : Vehicle
{
    Motorcycle(const std::string& n);

    //Special member Functions.  See instruction 9) and note in main()
    ~Motorcycle() override = default;
    Motorcycle(const Motorcycle&) = default;
    Motorcycle& operator=(const Motorcycle&) = default;

    void lanesplitAndRace( int topSpeed = std::numeric_limits<int>::max() );
    
    void tryToEvade() override;

    void setSpeed(int s) override;
};
