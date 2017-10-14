#pragma once
#include <Adafruit_NeoPixel.h>

class Lights {
private:
  int NUM_LEDS = 28;
  int NUM_LEDS_UNIT = 7;

  //Order of units
  int FRONT_R = 0;
  int FRONT_L = 1;
  int BACK_R = 2;
  int BACK_L = 3;

  uint32_t RED,WHITE,NO_COLOR;

public:
    Lights(int pin);

    void showHeadLights();
    void showBreakLights();
    void hideBreakLights();
    void setLightUnit(uint32_t color, int unit);

};
