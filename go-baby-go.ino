#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN_FRONT_RIGHT 6
#define PIN_FRONT_LEFT 7
#define PIN_BACK_LEFT 8
#define PIN_BACK_RIGHT 9

const unsigned int NUMBER_OF_LED_STRINGS = 4;
const unsigned int NUMBER_OF_PIXELS = 7;
Adafruit_NeoPixel front_R = Adafruit_NeoPixel(NUMBER_OF_PIXELS, PIN_FRONT_RIGHT);
Adafruit_NeoPixel front_L = Adafruit_NeoPixel(NUMBER_OF_PIXELS, PIN_FRONT_LEFT);
Adafruit_NeoPixel back_R = Adafruit_NeoPixel(NUMBER_OF_PIXELS, PIN_BACK_LEFT);
Adafruit_NeoPixel back_L = Adafruit_NeoPixel(NUMBER_OF_PIXELS, PIN_BACK_RIGHT);

Adafruit_NeoPixel * lights[NUMBER_OF_LED_STRINGS];


void setup() {

#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  lights[0] = &front_R;
  lights[1] = &front_L;
  lights[2] = &back_R;
  lights[3] = &back_L;

  for (int i = 0; i < NUMBER_OF_LED_STRINGS; i++) {
    lights[i]->begin();
    lights[i]->show();
  }


}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(&front_R, front_R.Color(255, 255, 255), 0); // White
  colorWipe(&front_L, front_L.Color(255, 255, 255), 0); // White
  colorWipe(&back_R, back_R.Color(255, 0, 0), 0); // red
  colorWipe(&back_L, back_L.Color(255, 0, 0), 0); // red
}


void colorWipe(Adafruit_NeoPixel * strip, uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < NUMBER_OF_PIXELS; i++) {
    strip->setPixelColor(i, c);
    strip->show();
    delay(wait);
  }
}


