#include "Highway.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

#include <algorithm>
#include <cassert>

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    do not call `setSpeed`.  Pick a different function.
    */

    if (Car* car = dynamic_cast<Car*>(v); car != nullptr)
    {
        car->closeWindows();
    }
    else if (Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(v); motorcycle != nullptr)
    {
        motorcycle->lanesplitAndRace(130);
    }
    else if (SemiTruck* semiTruck = dynamic_cast<SemiTruck*>(v); semiTruck != nullptr)
    {
        semiTruck->headlightFlasher();
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that tries to evade the cops. 
    do not call `setSpeed`.  Pick a different function.
    trucks pull over, but cars and bikes try to evade!!
    */

    if (Car* car = dynamic_cast<Car*>(v); car != nullptr)
    {
        car->tryToEvade();
    }
    else if (Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(v); motorcycle != nullptr)
    {
        motorcycle->tryToEvade();
    }
    else if (SemiTruck* semiTruck = dynamic_cast<SemiTruck*>(v); semiTruck != nullptr)
    {
        semiTruck->pullOver();
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
