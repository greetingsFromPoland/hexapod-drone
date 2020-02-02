#pragma once
#define INPUT_COMMANDS_COUNT 3

namespace Input {

    namespace Commands {
        static const uint8_t
                LEG_1_TIBIA = 1,
                LEG_1_COXA = 2,
                LEG_1_FEMUR = 3,
                GO_FORWARD = 4,
                GO_BACKWARDS = 5,
                GO_RIGHT = 6,
                GO_LEFT = 7,
                TURN_LEFT = 8,
                TURN_RIGHT = 9;

    }

    class Listener {
    private:
        /* data */
    public:
        virtual void newCommand(uint8_t command, uint8_t a, uint8_t b, uint8_t c);
    };

}