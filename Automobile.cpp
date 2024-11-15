#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
public:
    virtual std::string getType() const = 0;
    virtual ~Vehicle() {}
};

#endif // VEHICLE_H
