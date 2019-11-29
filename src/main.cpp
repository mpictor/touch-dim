/*
 * unimplemented nice-to-have's:
 * - limit pwm values to avoid exceeding led current
 * - save brightness over power loss
 * - sleep whenever led is off?
 *   - min time for wakeup/detect touch
 * - power-off timer
 * - once certain there will be no changes, rebuild for lower clock and disable
 *   usb
 *   - p1/p3/p4 could be used for something... what?
 */

/* connections:
 * digispark model b (onboard LED on p0)
 *
 * P0----------------|>--- (onboard, offboard LEDs)
 * P1     10M ohm
 * P2----\/\/\/\/-|--O   <-- touch point
 * P3             |
 * P4             |
 * P5-------------|
 */

// pins
const int sendPin = 2;
const int sensePin = 5;
// using the first kickstarter model, confusingly called model b. built-in led
// is on pin 0
const int ledPin = 0;

const unsigned long second = 1000;
// differentiates between two press types. for long press: t > LONG_PRESS
const unsigned long LONG_PRESS = 2 * second;
// for short press: MIN_PRESS < t < LONG_PRESS
const unsigned long MIN_PRESS = second / 5;
const int MAX_BRIGHT = 255;
const int INCR_BRIGHT = 5;

// touch sensitivity threshold
const int threshold = 100;
// number of samples to take
const int samples = 30;
// loop delay - affects update rate
const int loop_time_ms = 100;

#include <CapacitiveSensor.h>

// digispark: send on 2, listen on 5
CapacitiveSensor capSensor = CapacitiveSensor( sendPin, sensePin );

bool pressed = false;
unsigned long pressBegan = 0;
int brightness = 0;
bool on = false;

void updateOutput() {
    int val = 0;
    if( on ) {
        val = brightness;
    }
    analogWrite( ledPin, val );
}

void press() {
    pressBegan = millis();
    pressed = true;
}

void stillPressed() {
    unsigned long duration = millis() - pressBegan;
    if( duration < LONG_PRESS ) {
        return;
    }
    on = true;
    if( brightness < MAX_BRIGHT ) {
        brightness += INCR_BRIGHT;
    } else {
        brightness = 0;
    }
    updateOutput();
}

void release() {
    pressed = false;
    unsigned long duration = millis() - pressBegan;
    if( duration < MIN_PRESS ) {
        return;
    }
    if( duration < LONG_PRESS ) {
        if( !on && brightness == 0 ) {
            brightness = MAX_BRIGHT;
        }
        on = !on;
        updateOutput();
    }
    // duration > LONG_PRESS: long press, do nothing on release
}

void setup() {
    pinMode( ledPin, OUTPUT );
    digitalWrite( ledPin, LOW );
}

void loop() {
    long sensorValue = capSensor.capacitiveSensor( samples );
    // events on short and long presses, and on release
    if( sensorValue > threshold ) {
        if( !pressed ) {
            press();
        } else {
            stillPressed();
        }
    } else {
        if( pressed ) {
            release();
        }
    }
    delay( loop_time_ms );
}
