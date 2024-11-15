#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include "Vehicle.h"
#include <string>

class Automobile : public Vehicle {
public:
    std::string getType() const override { return "Automobile"; }
};

#endif // AUTOMOBILE_H
