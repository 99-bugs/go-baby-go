#pragma once

class CollisionDetector {
private:
    int SAFE_DISTANCE = 50;
    unsigned long TIME_OUT_DURATION = 1000; //ms

    int trigger, echo1, echo2, echo3;
    bool detected;
    unsigned long timeOutTime;

public:
    CollisionDetector(int trigger, int echo1, int echo2, int echo3);

    void updateState();
    bool isDetected();
    int pulseIn(int pin);

private:
    void triggerSensor(int pin);
    long getDistance(long duration);
};
