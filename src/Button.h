#pragma once

class Button{
public:
    Button(int pin_left, int pin_right);

    void updateState();
    int isPressed();
    int isReleased();
};
