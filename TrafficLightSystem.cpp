#include "TrafficLightSystem.h"
#include <iostream>

TrafficLightSystem::TrafficLightSystem(int maxQueueLength) {
    for (int i = 0; i < 4; ++i) {
        queues.push_back(QueueManager(maxQueueLength));
    }
}

void TrafficLightSystem::handleVehicle(Vehicle* vehicle, int road) {
    int adjustedRoad = road - 1;

    if (vehicle->getType() == "Emergency Vehicle") {
        std::cout << "\nEmergency vehicle detected! Turning all lights red." << std::endl;
        eventFlag.setEmergencyDetected(true);
        return;
    }

    std::cout << "\nAdding " << vehicle->getType() << " to road " << road << "." << std::endl;
    queues[adjustedRoad].addVehicleToQueue(vehicle);

    int currentQueueLength = queues[adjustedRoad].getQueueLength();

    std::cout << "Automobile added to the queue." << std::endl;
    std::cout << "Total cars on this road: " << currentQueueLength << std::endl;
    std::cout << "Remaining cars needed to turn the light green: " << (10 - currentQueueLength) << std::endl;

    if (queues[adjustedRoad].isQueueFull()) {
        std::cout << "\nQueue is full on road " << road << "! Turning the light green to clear traffic." << std::endl;
        queues[adjustedRoad].clearQueue();
    }
}
