#ifndef TRAFFICLIGHTSYSTEM_H
#define TRAFFICLIGHTSYSTEM_H

#include "QueueManager.h"
#include "Vehicle.h"
#include "EventFlag.h"
#include <vector>

class TrafficLightSystem {
private:
    std::vector<QueueManager> queues;
    EventFlag eventFlag;

public:
    TrafficLightSystem(int maxQueueLength = 10);
    void handleVehicle(Vehicle* vehicle, int road);
};

#endif // TRAFFICLIGHTSYSTEM_H
