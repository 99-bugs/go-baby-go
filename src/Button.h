#pragma once

#include <Arduino.h>

class Button{
public:
    Button(int pin_left, int pin_right);

    void updateState();
    int isPressed();
    int isReleased();

private:
    int pin_left;
    int pin_right;
    int button_state;
};
