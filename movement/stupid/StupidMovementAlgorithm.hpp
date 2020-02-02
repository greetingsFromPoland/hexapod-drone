#import "../AbstractMovement.hpp"

#define MOVEMNT_STUPID_MAX_STEPS 4

namespace Movment {
    namespace Algorithm {

        class Stupid :
                public AbstractMovement {
        private:
            Movment::LegMovmentSequence prepareResult();
            LegPoisions positions[MOVEMNT_STUPID_MAX_STEPS];
            LegMovmentSequence movmentSequence;
        public:
            Stupid();

            Movment::LegMovmentSequence bodyUp(uint8_t height);

            Movment::LegMovmentSequence bodyDown(uint8_t height);

            Movment::LegMovmentSequence bodyClearance(uint8_t clearance);

            Movment::LegMovmentSequence bodyAngle(uint8_t xDegrees, uint8_t yDegrees);

            Movment::LegMovmentSequence go(uint8_t xDegrees, uint8_t speed);

            Movment::LegMovmentSequence * goForward(uint8_t speed);

            Movment::LegMovmentSequence goBackwards(uint8_t speed);

            Movment::LegMovmentSequence goRight(uint8_t speed);

            Movment::LegMovmentSequence goLeft(uint8_t speed);

            Movment::LegMovmentSequence turnRight(uint8_t speed);

            Movment::LegMovmentSequence turnLeft(uint8_t speed);

            void enable();

            void disable();
        };

        Stupid::Stupid() {
                this->movmentSequence.positions = this->positions;
        }

        Movment::LegMovmentSequence Stupid::prepareResult() {
            LegPoisions positions[3];
            LegMovmentSequence movmentSequence;
            movmentSequence.positions = positions;
            return movmentSequence;
        }

        Movment::LegMovmentSequence Stupid::bodyUp(uint8_t height) {
            return this->prepareResult();
        }

        Movment::LegMovmentSequence Stupid::bodyDown(uint8_t height) {
            return this->prepareResult();
        }

        Movment::LegMovmentSequence Stupid::bodyClearance(uint8_t clearance) {
            return this->prepareResult();

        }

        Movment::LegMovmentSequence Stupid::bodyAngle(uint8_t xDegrees, uint8_t yDegrees) {
            return this->prepareResult();

        }

        Movment::LegMovmentSequence Stupid::go(uint8_t xDegrees, uint8_t speed) {
            return this->prepareResult();

        }


        Movment::LegMovmentSequence * Stupid::goForward(uint8_t speed) {
            Serial.println("Stupid::goForward");

            this->positions[0] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18}};
            this->positions[1] = {{21,22,23},{24,25,26},{27,28,29},{30,31,32},{33,34,35},{36,37,38}};
            this->positions[2] = {{41,42,43},{44,45,46},{47,48,49},{50,51,52},{53,54,55},{56,57,58}};
            
            // this->movmentSequence.positions[0].leg1.coxaAngle = 200;
            // this->movmentSequence.positions[2].leg6 = {101, 102, 103};

            this->movmentSequence.steps = 3;

            return &this->movmentSequence;
        }

        Movment::LegMovmentSequence Stupid::goBackwards(uint8_t speed) {
             Serial.println("Stupid::goBackwards");
            return this->prepareResult();

        }

        Movment::LegMovmentSequence Stupid::goRight(uint8_t speed) {
            Serial.println("Stupid::goRight");
             return this->prepareResult();

        }

        Movment::LegMovmentSequence Stupid::goLeft(uint8_t speed) {
             Serial.println("Stupid::goLeft");
            return this->prepareResult();

        }

        Movment::LegMovmentSequence Stupid::turnRight(uint8_t speed) {
             Serial.println("Stupid::turnRight");
            return this->prepareResult();

        }

        Movment::LegMovmentSequence Stupid::turnLeft(uint8_t speed) {
            Serial.println("Stupid::turnLeft");
             return this->prepareResult();

        }

        void Stupid::enable() {

        }

        void Stupid::disable() {

        }
    }
}