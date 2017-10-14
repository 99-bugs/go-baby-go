#define DEBUG true

#include "CollisionDetector.h"
#include "Arduino.h"

CollisionDetector::CollisionDetector(int trigger, int echo1, int echo2, int echo3)
{
    detected = true;
    this->trigger = trigger;
    this->echo1 = echo1;
    this->echo2 = echo2;
    this->echo3 = echo3;
    pinMode(this->trigger, OUTPUT);
    pinMode(this->echo1, INPUT);
    pinMode(this->echo2, INPUT);
    pinMode(this->echo3, INPUT);
}

void CollisionDetector::updateState()
{
    triggerSensor(trigger);
    long duration = pulseIn(echo1, HIGH,50000);

    #ifdef DEBUG
      Serial.print("Distance: ");
      Serial.print(getDistance(duration));
    #endif

    if(getDistance(duration) < SAFE_DISTANCE){
      detected = true;
      timeOutTime = millis();
    } else if(millis() > (timeOutTime + TIME_OUT_DURATION)) {
      detected = false;
    }
    else detected = true;
}

bool CollisionDetector::isDetected()
{
    return detected;
}


void CollisionDetector::triggerSensor(int pin){
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
}

long CollisionDetector::getDistance(long duration){
  return duration*0.034/2;
}
