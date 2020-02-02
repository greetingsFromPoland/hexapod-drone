#pragma once

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 250

class ServoController {
private:
    Adafruit_PWMServoDriver servoDriver;
    uint8_t i2cAddr;
    bool i2cAddrSet = false;
public:
    ServoController();

    ServoController(uint8_t i2cAddr);

    void setAngle(uint8_t motorNumber, int angle);

    void setup();

    int pulseWidth(int angle);

    void setPin(uint8_t num, uint16_t val);

};

ServoController::ServoController(uint8_t i2cAddr) {
    this->i2cAddr = i2cAddr;
    this->i2cAddrSet = true;
}

ServoController::ServoController() {
}

void ServoController::setup() {
    Serial.println("Servo::setup()");
    if (this->i2cAddrSet) {
        this->servoDriver = Adafruit_PWMServoDriver(this->i2cAddr);
    } else {
        this->servoDriver = Adafruit_PWMServoDriver();
    }
    this->servoDriver.begin();
    this->servoDriver.setPWMFreq(FREQUENCY);

    for (int i = 0; i < 16; i++) {
        this->servoDriver.setPin(i, this->pulseWidth(135));
    }
}

int ServoController::pulseWidth(int angle) {
    int pulse_wide, analog_value;
    pulse_wide = map(angle, 0, 270, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
    return analog_value;
}

void ServoController::setAngle(uint8_t motorNumber, int angle) {
    this->servoDriver.setPin(motorNumber, this->pulseWidth(angle));
}

void ServoController::setPin(uint8_t num, uint16_t val) {
    this->servoDriver.setPin(num, val);
}  


