#include <iostream>
#include <limits>
#include "TrafficLightSystem.h"  // Header for the traffic light system
#include "Automobile.h"         // Header for Automobile class
#include "EmergencyVehicle.h"   // Header for EmergencyVehicle class

int main()
{
    // Display program header
    std::cout << "CSC 300 Project Week#4 Deliverable\n";
    std::cout << "Team: Yellow Means Go\n";
    std::cout << "Adaptive Traffic Light\n\n";

    // Initialize the TrafficLightSystem with a maximum queue length of 10
    TrafficLightSystem tls(10);

    // Main loop to process user input and manage traffic system
    while (true)
    {
        char choice; // User choice for the type of action
        std::cout << "\nEnter 'v' for vehicle, 'p' for pedestrian, 'e' for error (or 'q' to quit): ";

        // Validate user input for main menu
        do
        {
            std::cin >> choice;
            choice = toupper(choice); // Convert input to uppercase for uniformity
            if (choice != 'Q' && choice != 'V' && choice != 'P' && choice != 'E')
            {
                std::cout << "Invalid Entry. Please Try Again.";
                std::cin.clear(); // Clear invalid input
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore excess input
            }
        } while (choice != 'Q' && choice != 'V' && choice != 'P' && choice != 'E');

        // Exit the program if the user chooses 'q'
        if (choice == 'Q')
        {
            std::cout << "Exiting program. Goodbye!\n";
            return 0;
        }

        // Trigger an error if the user chooses 'e'
        if (choice == 'E')
        {
            std::cout << "Triggering an error in the system.\n";
            tls.triggerError(); // Call method to simulate an error
            continue; // Skip remaining code in this iteration
        }

        // Handle vehicle input if the user chooses 'v'
        if (choice == 'V')
        {
            char vehicleType; // User choice for type of vehicle
            std::cout << "Enter 'a' for automobile or 'e' for emergency vehicle: ";

            // Validate user input for vehicle type
            do
            {
                std::cin >> vehicleType;
                vehicleType = toupper(vehicleType); // Convert to uppercase
                if (vehicleType != 'E' && vehicleType != 'A')
                {
                    std::cout << "Invalid Entry. Please Try Again.";
                    std::cin.clear(); // Clear invalid input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore excess input
                }
            } while (vehicleType != 'E' && vehicleType != 'A');

            // Create the appropriate vehicle object based on user input
            Vehicle* vehicle;
            if (vehicleType == 'E')
            {
                vehicle = new EmergencyVehicle(); // Create an emergency vehicle
            }
            else if (vehicleType == 'A')
            {
                vehicle = new Automobile(); // Create an automobile
            }

            std::cout << "\nSelect road (1-4): ";
            int road; // User-selected road number

            // Validate user input for road number
            do
            {
                std::cin >> road;

                if (std::cin.fail() || road < 1 || road > 4)
                {
                    std::cout << "Invalid Entry. Please Try Again.";
                    std::cin.clear(); // Clear invalid input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore excess input
                }
            } while (std::cin.fail() || road < 1 || road > 4);

            // Handle the vehicle arrival at the specified road
            tls.handleVehicle(vehicle, road);
            delete vehicle; // Free dynamically allocated memory
        }

            // Handle pedestrian input if the user chooses 'p'
        else if (choice == 'P')
        {
            std::cout << "Pedestrian crossing button pressed. Allowing pedestrian to cross.\n";
        }
    }

    return 0;
}
