#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int pin)
{
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
}

void Motor::drive()
{
    digitalWrite(this->pin, 1);
}

void Motor::stop()
{
    digitalWrite(this->pin, 0);
}