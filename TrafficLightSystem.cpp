#include "TrafficLightSystem.h"
#include <iostream>

// Constructor: Initializes the traffic light system with a max queue length
TrafficLightSystem::TrafficLightSystem(int maxQueueLength)
        : north("North"), south("South"), west("West"), east("East")
{
    queueLength = maxQueueLength;

    // Initialize queue managers for each road
    for (int i = 0; i < 4; ++i)
    {
        queues.push_back(QueueManager(maxQueueLength));
    }
}

// Handles a vehicle arriving at a specified road
void TrafficLightSystem::handleVehicle(Vehicle* vehicle, int road)
{
    int adjustedRoad = road - 1; // Adjust road index for array

    if (vehicle->getType() == "Emergency Vehicle")
    {
        std::cout << "\nEmergency vehicle detected! Turning all lights red." << std::endl;
        eventFlag.setEmergencyDetected(true);
        setAllSignalsRed(); // Respond to emergency by setting all signals to red
        return;
    }

    // Logic for handling normal vehicles
    std::cout << "\nAdding " << vehicle->getType() << " to road " << road << "." << std::endl;
    queues[adjustedRoad].addVehicleToQueue(vehicle);

    if (queues[adjustedRoad].isQueueFull())
    {
        std::cout << "Queue is full on road " << road << "! Turning the lights green to clear traffic." << std::endl;
        // Additional logic for handling full queues...
    }
}

// Sets all traffic lights to red, typically for emergencies
void TrafficLightSystem::setAllSignalsRed()
{
    std::cout << "Setting all signals to red...\n";
    north.changeSignal("Red", errorHandler, eventFlag);
    south.changeSignal("Red", errorHandler, eventFlag);
    west.changeSignal("Red", errorHandler, eventFlag);
    east.changeSignal("Red", errorHandler, eventFlag);
}

// Public method to trigger an error in the system
void TrafficLightSystem::triggerError()
{
    std::cout << "Error triggered in the system!\n";
    errorHandler.errorDetected(); // Trigger the error state in the error handler
    setAllSignalsRed();          // Respond by setting all signals to red
}
