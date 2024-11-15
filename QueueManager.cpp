#include "QueueManager.h"
#include <iostream>

void QueueManager::addVehicleToQueue(Vehicle* vehicle) {
    queue.push(vehicle);
    std::cout << vehicle->getType() << " added to the queue.\n";

    // Get the current queue length
    int currentCount = getQueueLength();
    int remainingSpots = getRemainingSpots();

    // Display the current count and remaining spots needed to turn the light green
    std::cout << "Total cars on this road: " << currentCount << "\n";
    if (remainingSpots > 0) {
        std::cout << "Remaining cars needed to turn the light green: " << remainingSpots << "\n";
    } else {
        std::cout << "Queue is full! Turning the light green.\n";
    }
}

void QueueManager::clearQueue() {
    while (!queue.empty()) {
        queue.pop();
    }
    std::cout << "Queue cleared, light turned green.\n";
}

bool QueueManager::isQueueFull() const {
    return queue.size() >= maxQueueLength;
}

int QueueManager::getQueueLength() const {
    return queue.size();
}

int QueueManager::getRemainingSpots() const {
    return maxQueueLength - queue.size();
}
