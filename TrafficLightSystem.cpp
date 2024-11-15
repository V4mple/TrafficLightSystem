#include "TrafficLightSystem.h"
#include <iostream>

void TrafficLightSystem::handleVehicle(Vehicle* vehicle, int road) {
    // Adjust road number to match internal array indexing (1-4)
    int adjustedRoad = road - 1;

    if (vehicle->getType() == "Emergency Vehicle") {
        std::cout << "Emergency vehicle detected! Turning all lights red.\n";
        eventFlag.setEmergencyDetected(true);
    } else {
        std::cout << "Adding " << vehicle->getType() << " to road " << road << ".\n";
        queues[adjustedRoad].addVehicleToQueue(vehicle);

        // Check if the queue is full
        if (queues[adjustedRoad].isQueueFull()) {
            std::cout << "Queue is full on road " << road << "! Turning the light green to clear traffic.\n";
            queues[adjustedRoad].clearQueue();
        }
    }
}
