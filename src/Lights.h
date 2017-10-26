#pragma once
#include <Adafruit_NeoPixel.h>

class Lights {
private:
  int NUM_LEDS = 14;
  int NUM_LEDS_UNIT = 7;
  Adafruit_NeoPixel strip;

  //Order of units
  int RIGHT = 0;
  int LEFT = 1;


  uint32_t RED,WHITE,NO_COLOR;

public:
    Lights(int pin);

    void showHeadLights();
    void showBreakLights();
    void hideBreakLights();
    void setLightUnit(uint32_t color, int unit);

};
