#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <vector>
#include <ctime>
#include "SensorSimulator.h"

int main() {
    SensorSimulator simulator;

    //Random Seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    auto start = std::chrono::steady_clock::now();

    //simulate 5 seconds at 100ms intervals
    for (int i =  0; i < 50; i++){

        //Add random noise to acceleration values for realism
        double noise = (std::rand() % 5 - 2.5);
        simulator.setAcceleration(9.8 + noise);

        simulator.update(0.1); // deltaTime in seconds

        std::cout << "Current Altitude: " << simulator.getAltitude() << "m" << std::endl;

        if (simulator.isThresholdExceeded(1000.0)) {
            std::cout << "Alert: Altitude exceeded 1000m! Current: " << simulator.getAltitude() << std::endl;
        }

        std::this_thread::sleep_until(start + std::chrono::milliseconds(100 * (i + 1)));
    }

    try {
        simulator.logData("output/sensor_log.txt");
        std::cout << "Data logged successfully." << std::endl;
    }

    catch (const std::exception& e) {
        std::cerr << "Error logging data: " << e.what() << std::endl;
    }

    return 0;
}