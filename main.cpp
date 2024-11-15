#include <iostream>
#include <limits>
#include "TrafficLightSystem.h"
#include "Automobile.h"
#include "EmergencyVehicle.h"

int main() {
    std::cout << "CSC 300 Project Week#4 Deliverable\n";
    std::cout << "Team: Yellow Means Go\n";
    std::cout << "Adaptive Traffic Light\n\n";

    // Initialize the TrafficLightSystem with a max queue length of 10
    TrafficLightSystem tls(10);

    while (true) {
        std::cout << "\nEnter 'v' for vehicle or 'p' for pedestrian (or 'q' to quit): ";
        char choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'q') {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }

        if (choice == 'v') {
            std::cout << "Enter 'a' for automobile or 'e' for emergency vehicle: ";
            char vehicleType;
            std::cin >> vehicleType;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            Vehicle* vehicle;
            if (vehicleType == 'e') {
                vehicle = new EmergencyVehicle();
            } else if (vehicleType == 'a') {
                vehicle = new Automobile();
            } else {
                std::cout << "Invalid vehicle type. Please enter 'a' or 'e'.\n";
                continue;
            }

            std::cout << "\nSelect road (1-4): ";
            int road;
            std::cin >> road;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (road >= 1 && road <= 4) {
                tls.handleVehicle(vehicle, road);
            } else {
                std::cout << "Invalid road number. Please enter a number between 1 and 4.\n";
            }

            delete vehicle;
        } else if (choice == 'p') {
            std::cout << "Pedestrian crossing button pressed. Allowing pedestrian to cross.\n";
        } else {
            std::cout << "Invalid input. Please try again.\n";
        }
    }

    return 0;
}
