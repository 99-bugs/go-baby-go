#pragma once

class CollisionDetector {
public:
    CollisionDetector(int trigger, int echo1, int echo2, int echo3);

    void updateState();
    int isDetected();

};
