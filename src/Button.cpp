#include "Button.h"
#include <Arduino.h>

Button::Button(int pin_left, int pin_right)
{
    this->pin_left = pin_left;
    this->pin_right = pin_right;
    pinMode(this->pin_left, INPUT_PULLUP);
    pinMode(this->pin_right, INPUT_PULLUP);
    button_state = false;
}

void Button::updateState()
{
    // Serial.println(digitalRead(this->pin_left));
    // Serial.println(digitalRead(this->pin_right));
    button_state = !digitalRead(this->pin_left) || !digitalRead(this->pin_right);
}

int Button::isPressed()
{
    return button_state;
}

int Button::isReleased()
{
    return !isPressed();
}