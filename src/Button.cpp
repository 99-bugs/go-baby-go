#include "Button.h"

Button::Button(int pin_left, int pin_right)
{

}

void Button::updateState()
{

}

int Button::isPressed()
{
    return false;
}

int Button::isReleased()
{
    return !isPressed();
}