#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include <queue> // STL (Standard Template Library) for queue
#include "Vehicle.h" // Base class for all vehicle types

// Class to manage a queue of vehicles at a traffic light
class QueueManager {
private:
    std::queue<Vehicle*> queue; // Queue to hold pointers to Vehicle objects
    int maxQueueLength;         // Maximum number of vehicles allowed in the queue

public:
    // Constructor to initialize the maximum queue length
    QueueManager(int maxQueueLength) : maxQueueLength(maxQueueLength) {}

    // Adds a vehicle to the queue
    void addVehicleToQueue(Vehicle* vehicle);

    // Returns the current length of the queue
    int getQueueLength() const;

    // Checks if the queue has reached its maximum length
    bool isQueueFull() const;

    // Clears all vehicles from the queue
    void clearQueue();
};

#endif // QUEUEMANAGER_H
