#include "Button.h"
#include "Arduino.h"

Button::Button(int pin_left, int pin_right)
{
  this->pinLeft = pin_left;
  this->pinRight = pin_right;
  pinMode(this->pinLeft, INPUT);
  pinMode(this->pinRight, INPUT);
  leftPressed = false;
  rightPressed = false;
}

void Button::updateState()
{
  leftPressed = digitalRead(this->pinLeft);
  rightPressed = digitalRead(this->pinRight);
}

bool Button::isPressed()
{
    return leftPressed || rightPressed;
}

bool Button::isReleased()
{
    return !isPressed();
}
