#include "QueueManager.h"

void QueueManager::addVehicleToQueue(Vehicle* vehicle) {
    queue.push(vehicle);
}

int QueueManager::getQueueLength() const {
    return queue.size();
}

bool QueueManager::isQueueFull() const {
    return queue.size() >= maxQueueLength;
}

void QueueManager::clearQueue() {
    while (!queue.empty()) {
        queue.pop();
    }
}
