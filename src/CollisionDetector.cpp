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
    //return false;
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



#include "wiring_private.h"
#include "pins_arduino.h"

/* Measures the length (in microseconds) of a pulse on the pin; state is HIGH
* or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
* to 3 minutes in length, but must be called at least a few dozen microseconds
* before the start of the pulse. */
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
	// cache the port and bit of the pin in order to speed up the
	// pulse width measuring loop and achieve finer resolution.  calling
	// digitalRead() instead yields much coarser resolution.
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	uint8_t stateMask = (state ? bit : 0);
	unsigned long width = 0; // keep initialization out of time critical area

	// convert the timeout from microseconds to a number of times through
	// the initial loop; it takes 16 clock cycles per iteration.
	unsigned long numloops = 0;
	unsigned long maxloops = microsecondsToClockCycles(timeout) / 16;

	// wait for any previous pulse to end
	while ((*portInputRegister(port) & bit) == stateMask)
		if (numloops++ == maxloops)
			return 0;

	// wait for the pulse to start
	while ((*portInputRegister(port) & bit) != stateMask)
		if (numloops++ == maxloops)
			return 0;

	// wait for the pulse to stop
	while ((*portInputRegister(port) & bit) == stateMask) {
		if (numloops++ == maxloops)
			return 0;
		width++;
	}

	// convert the reading to microseconds. The loop has been determined
	// to be 20 clock cycles long and have about 16 clocks between the edge
	// and the start of the loop. There will be some error introduced by
	// the interrupt handlers.
	return clockCyclesToMicroseconds(width * 21 + 16);
}
