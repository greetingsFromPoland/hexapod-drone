#pragma once

#include "../hardware/ServoController.hpp"


class Leg {
private:
    uint8_t coxaServoNumber;
    uint8_t femurServoNumber;
    uint8_t tibiaServoNumber;
    ServoController *servoController;
public:
    Leg(ServoController *servoController, uint8_t coxaServoNumber, uint8_t femurServoNumber, uint8_t tibiaServoNumber);

    uint8_t setCoxaAngle(uint8_t angle);

    uint8_t setFemurAngle(uint8_t angle);

    uint8_t setTibiaAngle(uint8_t angle);
};

Leg::Leg(ServoController *servoController, uint8_t coxaServoNumber, uint8_t femurServoNumber,
         uint8_t tibiaServoNumber) {
    this->coxaServoNumber = coxaServoNumber;
    this->femurServoNumber = femurServoNumber;
    this->tibiaServoNumber = tibiaServoNumber;
    this->servoController = servoController;
}

uint8_t Leg::setCoxaAngle(uint8_t angle) {
    Serial.print("Leg::setCoxaAngle");
    Serial.println(angle);
    this->servoController->setAngle(this->coxaServoNumber, angle);
    return 0;
}

uint8_t Leg::setFemurAngle(uint8_t angle) {
    Serial.print("Leg::setFemurAngle");
    Serial.println(angle);
    this->servoController->setAngle(this->femurServoNumber, angle);
    return 0;
}

uint8_t Leg::setTibiaAngle(uint8_t angle) {
    Serial.print("Leg::setTibiaAngle");
    Serial.println(angle);
    this->servoController->setAngle(this->tibiaServoNumber, angle);
    return 0;
}
