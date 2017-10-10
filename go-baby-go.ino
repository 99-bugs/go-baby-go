
#include "src/Lights.h"
#include "src/Button.h"
#include "src/CollisionDetector.h"
#include "src/Motor.h"

const int STEER_LEFT = 5;
const int STEER_RIGHT = 4;
const int NEOPIXEL = 12;
const int TRIGGER = 14;
const int ECHO_1 = 2;
const int ECHO_2 = 16;
const int ECHO_3 = 15;
const int MOTOR = 13;

Motor motor(MOTOR);
Button button(STEER_LEFT, STEER_RIGHT);
CollisionDetector collision(TRIGGER, ECHO_1, ECHO_2, ECHO_3);
Lights lights(NEOPIXEL);

void setup() {
  lights.showHeadLights();
}

void loop() {
  button.updateState();
  collision.updateState();

  if(button.isPressed() && !collision.isDetected()){
    motor.drive();
    lights.hideBreakLights();
  } else {
    motor.stop();
    lights.showBreakLights();
  }
}



