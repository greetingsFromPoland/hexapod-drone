#pragma once

#include <SoftwareSerial.h>
#include "InputListener.hpp"

class BleInput {
private:
    char command;
    SoftwareSerial ble = SoftwareSerial(0, 0);
    bool inputListernerSet = false;
    Input::Listener *inputListener;

    int parseIntFromCmd(String cmd, uint8_t numberPosition);

    void nofifyListener(uint8_t command, uint8_t a, uint8_t b, uint8_t c);

public:
    BleInput(uint8_t txPin, uint8_t rxPin);

    BleInput(uint8_t txPin, uint8_t rxPin, Input::Listener *inputListener);

    void setInputListener(Input::Listener *inputListener);

    void run();

    void setup();
};

BleInput::BleInput(uint8_t txPin, uint8_t rxPin) {

}

BleInput::BleInput(uint8_t txPin, uint8_t rxPin, Input::Listener *inputListener) {
    this->setInputListener(inputListener);
}


void BleInput::setup() {
    Serial.println("BleInput::setip");
    this->ble = SoftwareSerial(10, 9);
    this->ble.begin(9600);
}


void BleInput::setInputListener(Input::Listener *inputListener) {
    this->inputListener = inputListener;
    this->inputListernerSet = true;
}

void BleInput::run() {
    if (this->ble.available()) {
        String s = "";
        char c;
        while ((c = this->ble.read()) != -1) {
            s += c;
            delay(5);
        }
        this->command = s[0];


        Serial.print("From BT: ");
        Serial.print(s);

        switch (this->command) {
            case 'a':
                this->nofifyListener(Input::Commands::LEG_1_TIBIA, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'b':
                this->nofifyListener(Input::Commands::LEG_1_COXA, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'c':
                this->nofifyListener(Input::Commands::LEG_1_FEMUR, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'd':
                this->nofifyListener(Input::Commands::GO_FORWARD, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'e':
                this->nofifyListener(Input::Commands::GO_BACKWARDS, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'f':
                this->nofifyListener(Input::Commands::GO_RIGHT, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'h':
                this->nofifyListener(Input::Commands::GO_LEFT, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'i':
                this->nofifyListener(Input::Commands::TURN_LEFT, this->parseIntFromCmd(s, 0), 0, 0);
                break;
            case 'j':
                this->nofifyListener(Input::Commands::TURN_RIGHT, this->parseIntFromCmd(s, 0), 0, 0);
                break;
        }

    }
}

void BleInput::nofifyListener(uint8_t command, uint8_t a, uint8_t b, uint8_t c) {
    if (this->inputListernerSet) {
        this->inputListener->newCommand(command, a, b, c);
    }
}

int BleInput::parseIntFromCmd(String cmd, uint8_t numberPosition) {
    uint8_t spacePosition = 0;
    for (uint8_t i = 0; i < cmd.length(); i++) {
        if (cmd[i] == ' ') {
            spacePosition = i;
            break;
        }
    }

    String bufforForParsedNumberAsString;
    char bufferForParsedNumberAsChar[3];

    bufferForParsedNumberAsChar[0] = cmd[2];
    bufferForParsedNumberAsChar[1] = cmd[3];
    bufferForParsedNumberAsChar[2] = cmd[4];

    bufforForParsedNumberAsString = String(bufferForParsedNumberAsChar);
    return bufforForParsedNumberAsString.toInt();
}
