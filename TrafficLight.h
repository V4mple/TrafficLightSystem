#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "ErrorHandler.h" // Handles system errors
#include "EventFlag.h"    // Manages emergency events
#include <string>

// Class representing a traffic light with signal control functionality
class TrafficLight
{
private:
    std::string color;      // Current color of the traffic light
    std::string direction;  // Direction this traffic light controls

public:
    // Default constructor: initializes the traffic light color to "Red"
    TrafficLight();

    // Constructor: initializes the traffic light color to "Red" and sets the direction
    TrafficLight(std::string direction);

    // Returns the current signal color of the traffic light
    std::string getSignalColor();

    // Changes the traffic light to "Green"
    void changeToGreen();

    // Changes the traffic light to "Yellow" with a countdown
    void changeToYellow();

    // Changes the traffic light to "Red" with a countdown
    void changeToRed();

    // Simulates a countdown for the specified number of seconds
    void countdown(int seconds);

    // Changes the signal to a target color while handling errors and emergency events
    void changeSignal(std::string colorTarget, ErrorHandler errorHandle, EventFlag& event);
};

#endif // TRAFFICLIGHT_H
