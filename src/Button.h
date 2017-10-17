#pragma once

class Button{
private:
    bool leftPressed, rightPressed;
    int pinLeft, pinRight;

public:
    Button(int pin_left, int pin_right);

    void updateState();
    bool isPressed();
    bool isReleased();
};
