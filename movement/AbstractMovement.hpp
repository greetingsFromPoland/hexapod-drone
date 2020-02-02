
namespace Movment {
    struct LegPosition {
        byte coxaAngle;
        byte femurAngle;
        byte tibiaAngle;
    };

    struct LegPoisions {
        LegPosition leg1;
        LegPosition leg2;
        LegPosition leg3;
        LegPosition leg4;
        LegPosition leg5;
        LegPosition leg6;
    };

    struct LegMovmentSequence {
        LegPoisions *positions;
        byte steps;
    };


    class AbstractMovement {
    private:

    public:
        virtual LegMovmentSequence bodyUp(uint8_t height);

        virtual LegMovmentSequence bodyDown(uint8_t height);

        virtual LegMovmentSequence bodyClearance(uint8_t clearance);

        virtual LegMovmentSequence bodyAngle(uint8_t xDegrees, uint8_t zDegrees);

        virtual LegMovmentSequence go(uint8_t xDegrees, uint8_t speed);

        virtual LegMovmentSequence * goForward(uint8_t speed);

        virtual LegMovmentSequence goBackwards(uint8_t speed);

        virtual LegMovmentSequence goRight(uint8_t speed);

        virtual LegMovmentSequence goLeft(uint8_t speed);

        virtual LegMovmentSequence turnRight(uint8_t speed);

        virtual LegMovmentSequence turnLeft(uint8_t speed);

        virtual void enable();

        virtual void disable();
    };


} 

