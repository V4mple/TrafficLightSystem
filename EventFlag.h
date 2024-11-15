#ifndef EVENT_FLAG_H
#define EVENT_FLAG_H

class EventFlag {
private:
    bool isEmergencyDetected;
    bool isQueueFull;
public:
    EventFlag() : isEmergencyDetected(false), isQueueFull(false) {}

    void setEmergencyDetected(bool status) { isEmergencyDetected = status; }
    bool getEmergencyDetected() const { return isEmergencyDetected; }

    void setQueueFull(bool status) { isQueueFull = status; }
    bool getQueueFull() const { return isQueueFull; }

    void resetFlags() {
        isEmergencyDetected = false;
        isQueueFull = false;
    }
};

#endif // EVENT_FLAG_H
