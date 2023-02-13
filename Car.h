#pragma once

#include "Vehicle.h"

struct Car : Vehicle
{
    Car(const std::string& s);

    //Special member Functions.  See instruction 9) and note in main()
    ~Car() override = default;
    Car(const Car&) = default;
    Car& operator=(const Car&) = default;

    void closeWindows();

    void tryToEvade() override;
};
