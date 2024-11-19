#include "TrafficLight.h"

// Default constructor: initializes the traffic light color to "Red"
TrafficLight::TrafficLight()
{
    color = "Red";
}

// Constructor: initializes the traffic light color to "Red" and sets its direction
TrafficLight::TrafficLight(std::string direction)
{
    color = "Red";
    this->direction = direction;
}

// Returns the current signal color of the traffic light
std::string TrafficLight::getSignalColor()
{
    return color;
}

// Changes the traffic light to "Green" and displays the action
void TrafficLight::changeToGreen()
{
    std::cout << "Changing " + direction + " signal to Green . . .\n";
    color = "Green";
    std::cout << direction + " Signal is now " + color + "!\n";
}

// Changes the traffic light to "Yellow" and displays the action with a countdown
void TrafficLight::changeToYellow()
{
    std::cout << "Changing " + direction + " signal to Yellow . . .\n";
    countdown(3); // Countdown before changing the signal
    color = "Yellow";
    std::cout << direction + " Signal is now " + color + "!\n";
}

// Changes the traffic light to "Red" and displays the action with a countdown
void TrafficLight::changeToRed()
{
    std::cout << "Changing " + direction + " signal to Red . . .\n";
    countdown(3); // Countdown before changing the signal
    color = "Red";
    std::cout << direction + " Signal is now " + color + "!\n";
}

// Simulates a countdown for the specified number of seconds
void TrafficLight::countdown(int seconds)
{
    for (int i = seconds; i > 0; i--)
    {
        std::cout << i << "\n"; // Print each second
    }
}

// Changes the traffic light signal to the specified target color
// Handles errors and emergency events during the process
void TrafficLight::changeSignal(std::string colorTarget, ErrorHandler errorHandle, EventFlag& event)
{
    bool error = errorHandle.getErrorStatus();

    // Handle blinking red light during an error
    if (error && color != "Blinking Red")
    {
        color = "Blinking Red";
        std::cout << "Error detected. Signals are blinking red!\n";
        return;
    }

    // Keep the light blinking red if an error persists
    if (error && color == "Blinking Red")
    {
        std::cout << "New error detected! Signals remain blinking red!\n";
        return;
    }

    // Change back to solid red when the error is resolved
    if (!error && color == "Blinking Red")
    {
        color = "Red";
        std::cout << "No error detected anymore. Signals are now solid red.\n";
        return;
    }

    // Handle emergency event: ensure lights are red after the event clears
    if (!error && event.isEmergencyDetected())
    {
        event.setEmergencyDetected(false);
        changeSignal("Red", errorHandle, event); // Recursively set the signal to red
        return;
    }

    // If the light is already the target color, no action is needed
    if (color == colorTarget)
    {
        std::cout << direction << " Signal is already the desired color. No change is needed.\n";
        return;
    }

        // Change to red via yellow if the target color is red
    else if (colorTarget == "Red")
    {
        changeToYellow();
        changeToRed();
        return;
    }

        // Directly change to green if the target color is green
    else if (colorTarget == "Green")
    {
        changeToGreen();
        return;
    }
}
