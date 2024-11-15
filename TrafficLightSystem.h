#ifndef TRAFFIC_LIGHT_SYSTEM_H
#define TRAFFIC_LIGHT_SYSTEM_H

#include "QueueManager.h"
#include "Vehicle.h"
#include "EmergencyVehicle.h"
#include "Automobile.h"
#include "EventFlag.h"

class TrafficLightSystem {
private:
    QueueManager queues[4];
    EventFlag eventFlag;
public:
    void handleVehicle(Vehicle* vehicle, int road);
    void handlePedestrian();
    void run();
};

#endif // TRAFFIC_LIGHT_SYSTEM_H
