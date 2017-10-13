
// Comment out the line below to run the code in 'production' mode
#define DEBUG true

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
const int MOTOR = 9;
const int BUTTON = 11;

Motor motor(MOTOR);
Button button(BUTTON, STEER_RIGHT);
CollisionDetector collision(TRIGGER, ECHO_1, ECHO_2, ECHO_3);
Lights lights(NEOPIXEL);

void setup() {
  lights.showHeadLights();
  #ifdef DEBUG
  Serial.begin(115200);
  Serial.println("--- Start of application ---");
  #endif
}

void loop() {
  button.updateState();
  collision.updateState();

  #ifdef DEBUG
  Serial.print("Button state: ");
  Serial.println(button.isPressed());
  #endif

  if(button.isPressed() && !collision.isDetected()){
    motor.drive();
    lights.hideBreakLights();
  } else {
    motor.stop();
    lights.showBreakLights();
  }
  #ifdef DEBUG
  delay(500);
  #endif
}



