#ifndef EVENTFLAG_H
#define EVENTFLAG_H

// Class to handle event flags for the Traffic Light System
class EventFlag {
private:
    bool emergencyDetected; // Flag to indicate if an emergency is detected

public:
    // Constructor initializes the emergency flag to false
    EventFlag() : emergencyDetected(false) {}

    // Sets the emergency flag to the specified status
    void setEmergencyDetected(bool status) {
        emergencyDetected = status;
    }

    // Returns the current status of the emergency flag
    bool isEmergencyDetected() const {
        return emergencyDetected;
    }
};

#endif // EVENTFLAG_H
