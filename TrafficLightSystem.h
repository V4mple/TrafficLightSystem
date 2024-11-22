#ifndef TRAFFICLIGHTSYSTEM_H
#define TRAFFICLIGHTSYSTEM_H

#include "QueueManager.h"
#include "Vehicle.h"
#include "EventFlag.h"
#include "TrafficLight.h"
#include "ErrorHandler.h"
#include <vector>

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
    TrafficLightSystem(int maxQueueLength);

    // Handles a vehicle arriving at a specified road
    void handleVehicle(Vehicle* vehicle, int road);

    // Handles actions when a queue becomes full for a specified road
    void handleFullQueue(int road);

    // Sets all traffic lights to red, typically for emergencies
    void setAllSignalsRed();

    // Changes the traffic light signals for a specific road pair (e.g., North-South or West-East)
    void changeSignalPair(int pair);

    // Displays the current state of all traffic lights
    void displayTrafficLightStates() const;

    // Displays the current length of all queues
    void displayQueueLengths() const;

    // Handles pedestrian crossing at a specified crosswalk
    void handlePedestrian(char crosswalk);

    // Public method to trigger an error in the system
    void triggerError();
};

#endif // TRAFFICLIGHTSYSTEM_H
