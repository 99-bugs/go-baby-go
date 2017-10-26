#include <Adafruit_NeoPixel.h>


#define DEBUG true

#include "src/Lights.h"
#include "src/Button.h"
#include "src/CollisionDetector.h"
#include "src/Motor.h"

const int STEER_LEFT = 12;
const int STEER_RIGHT = 11;
const int NEOPIXEL_FRONT = 6;
const int NEOPIXEL_BACK = 9;
const int TRIGGER = 2;
const int ECHO_1 = 3;
const int ECHO_2 = 4;
const int ECHO_3 = 5;
const int MOTOR = 8;

Motor motor(MOTOR);
Button button(STEER_LEFT, STEER_RIGHT);
CollisionDetector collision(TRIGGER, ECHO_1, ECHO_2, ECHO_3);

Lights lightsb(NEOPIXEL_BACK);
Lights lightsf(NEOPIXEL_FRONT);

void setup() {
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println("Car Initializing...");
  #endif
  lightsf.showHeadLights();
  lightsb.showBreakLights();
}

void loop() {
  delay(100);
  button.updateState();
  collision.updateState();
  
  if(button.isPressed() && !collision.isDetected()){
    motor.drive();
    lightsb.hideBreakLights();
    #ifdef DEBUG
      Serial.println(" - Driving!");
    #endif
  } else {
    motor.stop();
    lightsb.showBreakLights();
    #ifdef DEBUG
      Serial.println(" - Stopped!");
    #endif
  }
}
