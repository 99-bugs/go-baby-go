#include "Lights.h"

Lights::Lights(int pin)
{
  strip = Adafruit_NeoPixel(NUM_LEDS, pin, NEO_GRB + NEO_KHZ800);

  WHITE = strip.Color(255, 255, 255);
  RED = strip.Color(255, 0, 0);
  NO_COLOR = strip.Color(0,0,0);

  strip.begin();
}


void Lights::showHeadLights()
{
  setLightUnit(WHITE, RIGHT);
  setLightUnit(WHITE, LEFT);
  strip.show();
}

void Lights::showBreakLights()
{
  setLightUnit(RED, RIGHT);
  setLightUnit(RED, LEFT);
  strip.show();
}

void Lights::hideBreakLights()
{
  setLightUnit(NO_COLOR, RIGHT);
  setLightUnit(NO_COLOR, LEFT);
  strip.show();
}

void Lights::setLightUnit(uint32_t color, int unit){
  for(int i = (unit*this->NUM_LEDS_UNIT); i<((unit+1)*this->NUM_LEDS_UNIT);i++){
    strip.setPixelColor(i, color);
  }
  strip.show();
}
