#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include <queue>
#include "Vehicle.h"

class QueueManager {
private:
    std::queue<Vehicle*> queue;
    int maxQueueLength;

public:
    QueueManager(int maxQueueLength) : maxQueueLength(maxQueueLength) {}

    void addVehicleToQueue(Vehicle* vehicle);
    int getQueueLength() const;
    bool isQueueFull() const;
    void clearQueue();
};

#endif // QUEUEMANAGER_H
