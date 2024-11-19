#ifndef TRAFFICLIGHTSYSTEM_H
#define TRAFFICLIGHTSYSTEM_H

#include "QueueManager.h"  // Manages vehicle queues for each road
#include "Vehicle.h"       // Base class for vehicle types
#include "EventFlag.h"     // Tracks emergency events
#include "TrafficLight.h"  // Represents individual traffic lights
#include "ErrorHandler.h"  // Handles system errors
#include <vector>          // For managing multiple queues with std::vector

// Class representing the traffic light system, responsible for managing traffic flow
class TrafficLightSystem {
private:
    std::vector<QueueManager> queues; // Queues for vehicles waiting at each road
    EventFlag eventFlag;              // Tracks emergency events
    ErrorHandler errorHandler;        // Handles system errors
    TrafficLight north;               // Traffic light for the North road
    TrafficLight south;               // Traffic light for the South road
    TrafficLight west;                // Traffic light for the West road
    TrafficLight east;                // Traffic light for the East road

    int queueLength; // Maximum length of a queue before action is taken

public:
    // Constructor: Initializes the traffic light system with a maximum queue length
    TrafficLightSystem(int maxQueueLength);

    // Handles a vehicle arriving at a specified road
    // - vehicle: A pointer to the Vehicle object
    // - road: The road number (1-4) where the vehicle is arriving
    void handleVehicle(Vehicle* vehicle, int road);

    // Handles actions when a queue becomes full for a specified road
    // - road: The road number (1-4) where the queue is full
    void handleFullQueue(int road);

    // Sets all traffic lights to red, typically for emergencies
    void setAllSignalsRed();

    // Changes the traffic light signals for a specific road pair
    // - pair: Specifies which pair of roads to update (1 for North-South, 2 for West-East)
    void changeSignalPair(int pair);

    // Public method to trigger an error in the system
    void triggerError();
};

#endif // TRAFFICLIGHTSYSTEM_H
