#pragma once

class Motor{
public:
    Motor(int pin);

    void drive();
    void stop();

private:
    int pin;
};
