#ifndef EVENTFLAG_H
#define EVENTFLAG_H

class EventFlag {
private:
    bool emergencyDetected;

public:
    EventFlag() : emergencyDetected(false) {}

    void setEmergencyDetected(bool status) {
        emergencyDetected = status;
    }

    bool isEmergencyDetected() const {
        return emergencyDetected;
    }
};

#endif // EVENTFLAG_H
