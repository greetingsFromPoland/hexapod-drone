#pragma once

#include "input/InputListener.hpp"
#include "robot/Leg.hpp"
#include "movement/stupid/StupidMovementAlgorithm.hpp"
#include "movement/AbstractMovement.hpp"

class DroneController :
        public Input::Listener {
private:
    Leg *leg1;
    Leg *leg2;
    Leg *leg3;
    Leg *leg4;
    Leg *leg5;
    Leg *leg6;
    Movment::Algorithm::Stupid stupid = Movment::Algorithm::Stupid();
    Movment::AbstractMovement *currentMovementController;
    Movment::LegMovmentSequence *legMovmentSequence;
    bool working = false;
    byte currentSequecneStep = 0;
    void printLegPositions(Movment::LegPoisions *legPoisions);

public:
    DroneController(Leg *leg1, Leg *leg2, Leg *leg3, Leg *leg4, Leg *leg5, Leg *leg6);

    void newCommand(uint8_t command, uint8_t a, uint8_t b, uint8_t c);

    void setup();

    void run();
};

DroneController::DroneController(Leg *leg1, Leg *leg2, Leg *leg3, Leg *leg4, Leg *leg5, Leg *leg6) {
    this->leg1 = leg1;
    this->leg2 = leg2;
    this->leg3 = leg3;
    this->leg4 = leg4;
    this->leg5 = leg5;
    this->leg6 = leg6;

}

void DroneController::setup() {
    Serial.println("DroneController::setup");

    this->currentMovementController = &this->stupid;

}

void DroneController::newCommand(uint8_t command, uint8_t a, uint8_t b, uint8_t c) {

    switch (command) {
        case Input::Commands::LEG_1_COXA:
            this->leg1->setCoxaAngle(a);
            break;
        case Input::Commands::LEG_1_FEMUR:
            this->leg1->setFemurAngle(a);
            break;
        case Input::Commands::LEG_1_TIBIA:
            this->leg1->setTibiaAngle(a);
            break;
        case Input::Commands::GO_FORWARD:
            this->legMovmentSequence = this->currentMovementController->goForward(a);
            this->working = true;
                                Serial.print("In swith: ");

                    Serial.println(this->legMovmentSequence->positions[this->currentSequecneStep].leg1.coxaAngle);

            break;
        case Input::Commands::GO_BACKWARDS:
            this->legMovmentSequence = &this->currentMovementController->goBackwards(a);
            this->working = true;
            break;
        case Input::Commands::GO_RIGHT:
            this->legMovmentSequence = &this->currentMovementController->goRight(a);
            this->working = true;
            break;
        case Input::Commands::GO_LEFT:
            this->legMovmentSequence = &this->currentMovementController->goLeft(a);
            this->working = true;
            break;
        case Input::Commands::TURN_LEFT:
            this->legMovmentSequence = &this->currentMovementController->turnLeft(a);
            this->working = true;
            break;
        case Input::Commands::TURN_RIGHT:
            this->legMovmentSequence = &this->currentMovementController->turnRight(a);
            this->working = true;
            break;
    }
}

void DroneController::run() {

    if(this->working){


        Movment::LegPoisions *legPoisions = &this->legMovmentSequence->positions[this->currentSequecneStep];

        this->printLegPositions(legPoisions);

        if(this->currentSequecneStep +1 >= this->legMovmentSequence->steps){
            this->working = false;
            this->currentSequecneStep = 0;
        }else{
            this->currentSequecneStep++;
        }



    }
}
    void DroneController::printLegPositions(Movment::LegPoisions *legPoisions){
        Serial.print("Leg1: Coxa: ");
        Serial.print(legPoisions->leg1.coxaAngle);
        Serial.print(", Femur: ");
        Serial.print(legPoisions->leg1.femurAngle);
        Serial.print(", Tibia: ");
        Serial.print(legPoisions->leg1.tibiaAngle);

        Serial.print("; Leg2: Coxa: ");
        Serial.print(legPoisions->leg2.coxaAngle);
        Serial.print(", Femur: ");
        Serial.print(legPoisions->leg2.femurAngle);
        Serial.print(", Tibia: ");
        Serial.print(legPoisions->leg2.tibiaAngle);
        
                Serial.print("; Leg4: Coxa: ");
        Serial.print(legPoisions->leg3.coxaAngle);
        Serial.print(", Femur: ");
        Serial.print(legPoisions->leg3.femurAngle);
        Serial.print(", Tibia: ");
        Serial.print(legPoisions->leg3.tibiaAngle);

                Serial.print("; Leg4: Coxa: ");
        Serial.print(legPoisions->leg4.coxaAngle);
        Serial.print(", Femur: ");
        Serial.print(legPoisions->leg4.femurAngle);
        Serial.print(", Tibia: ");
        Serial.print(legPoisions->leg4.tibiaAngle);

                Serial.print("; Leg5: Coxa: ");
        Serial.print(legPoisions->leg5.coxaAngle);
        Serial.print(", Femur: ");
        Serial.print(legPoisions->leg5.femurAngle);
        Serial.print(", Tibia: ");
        Serial.print(legPoisions->leg5.tibiaAngle);
        
                Serial.print("; Leg6: Coxa: ");
        Serial.print(legPoisions->leg6.coxaAngle);
        Serial.print(", Femur: ");
        Serial.print(legPoisions->leg6.femurAngle);
        Serial.print(", Tibia: ");
        Serial.print(legPoisions->leg6.tibiaAngle);
             Serial.println(" ");

    // Serial.println("DroneController::run");
}