#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "Vehicle.h" // Base class for all vehicle types
#include <string>

// Class representing an automobile, inheriting from the Vehicle base class
class Automobile : public Vehicle {
public:
    // Returns the type of this vehicle as a string
    std::string getType() const override { return "Automobile"; }
};

#endif // AUTOMOBILE_H
