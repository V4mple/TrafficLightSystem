#include "QueueManager.h"

// Adds a vehicle to the queue
void QueueManager::addVehicleToQueue(Vehicle* vehicle) {
    queue.push(vehicle); // Push the vehicle to the back of the queue
}

// Returns the current length of the queue
int QueueManager::getQueueLength() const {
    return queue.size(); // Return the number of vehicles in the queue
}

// Checks if the queue has reached its maximum allowed length
bool QueueManager::isQueueFull() const {
    return queue.size() >= maxQueueLength; // Compare queue size to the max length
}

// Clears all vehicles from the queue
void QueueManager::clearQueue() {
    while (!queue.empty()) {
        queue.pop(); // Remove vehicles from the front until the queue is empty
    }
}
