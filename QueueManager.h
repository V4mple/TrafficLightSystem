#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include <queue>
#include <iostream>
#include "Vehicle.h"

class QueueManager {
private:
    std::queue<Vehicle*> queue;
    const int maxQueueLength = 10;
public:
    void addVehicleToQueue(Vehicle* vehicle);
    void clearQueue();
    bool isQueueFull() const;
    int getQueueLength() const;
    int getRemainingSpots() const;
};

#endif // QUEUE_MANAGER_H
