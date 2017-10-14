
#define DEBUG true

#include "src/Lights.h"
#include "src/Button.h"
#include "src/CollisionDetector.h"
#include "src/Motor.h"

const int STEER_LEFT = 12;
const int STEER_RIGHT = 11;
const int NEOPIXEL = 6;
const int TRIGGER = 2;
const int ECHO_1 = 3;
const int ECHO_2 = 4;
const int ECHO_3 = 5;
const int MOTOR = 13;

Motor motor(MOTOR);
Button button(STEER_LEFT, STEER_RIGHT);
CollisionDetector collision(TRIGGER, ECHO_1, ECHO_2, ECHO_3);
Lights lights(NEOPIXEL);

void setup() {
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println("Car Initializing...");
  #endif
  lights.showHeadLights();
}

void loop() {
  button.updateState();
  collision.updateState();

  if(button.isPressed() && !collision.isDetected()){
    motor.drive();
    lights.hideBreakLights();
    #ifdef DEBUG
      Serial.println(" - Driving!");
    #endif
  } else {
    motor.stop();
    lights.showBreakLights();
    #ifdef DEBUG
      Serial.println(" - Stopped!");
    #endif
  }
}
