#ifndef EMERGENCY_VEHICLE_H
#define EMERGENCY_VEHICLE_H

#include "Vehicle.h"
#include <string>

class EmergencyVehicle : public Vehicle {
public:
    std::string getType() const override { return "Emergency Vehicle"; }
};

#endif // EMERGENCY_VEHICLE_H
