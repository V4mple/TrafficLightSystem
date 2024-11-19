#ifndef VEHICLE_H
#define VEHICLE_H

#include <string> // For std::string usage

// Abstract base class representing a generic vehicle
class Vehicle {
public:
    // Pure virtual function to get the type of the vehicle
    virtual std::string getType() const = 0;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Vehicle() {}
};

#endif // VEHICLE_H
