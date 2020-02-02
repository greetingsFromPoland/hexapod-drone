
#include "hardware/ServoController.hpp"
#include "input/BleInput.hpp"
#include "DroneController.hpp"
#include "robot/Leg.hpp"

ServoController servorDriverFirst = ServoController();
ServoController servorDriverSecond = ServoController(0x01);

Leg leg1 = Leg(&servorDriverFirst, 0, 1, 2);
Leg leg2 = Leg(&servorDriverFirst, 3, 4, 5);
Leg leg3 = Leg(&servorDriverFirst, 6, 7, 8);

Leg leg4 = Leg(&servorDriverSecond, 0, 1, 2);
Leg leg5 = Leg(&servorDriverSecond, 3, 4, 5);
Leg leg6 = Leg(&servorDriverSecond, 6, 7, 8);

DroneController droneController = DroneController(&leg1, &leg2, &leg3, &leg4, &leg5, &leg6);

// Android & IOS BLE Input
BleInput bleInput = BleInput(9, 10, &droneController);

// PS4 DualShock Input
// Aparatura 2.4GH Long Range PWM Input 

void setup() {
    Serial.begin(115200);
    Serial.println("Hexapod Drone v0.0.1");

    // Wszystko konfigurujemy dopiero jak jest Serial - by moc wysłać log. 
    servorDriverFirst.setup();
    servorDriverSecond.setup();
    droneController.setup();
    bleInput.setup();
}

void loop() {
    // Odczyt polecen + obliczenia
    bleInput.run();

    // Egzekucja zadan
    droneController.run();

}
