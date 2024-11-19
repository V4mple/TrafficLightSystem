#ifndef EMERGENCY_VEHICLE_H
#define EMERGENCY_VEHICLE_H

#include "Vehicle.h" // Base class for all vehicle types
#include <string>

// Class representing an emergency vehicle, inheriting from the Vehicle base class
class EmergencyVehicle : public Vehicle {
public:
    // Returns the type of this vehicle as a string
    std::string getType() const override { return "Emergency Vehicle"; }
};

#endif // EMERGENCY_VEHICLE_H
