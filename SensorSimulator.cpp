#include "SensorSimulator.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <ctime>

SensorSimulator::SensorSimulator() : altitude(0.0), velocity(0.0), acceleration(9.8) {}

void SensorSimulator::update(double deltaTime) {
    velocity += acceleration * deltaTime;
    altitude += velocity * deltaTime;
    dataLog.push_back({std::chrono::system_clock::now(), altitude});
}

double SensorSimulator::getAltitude() const {
    return altitude;
}

bool SensorSimulator::isThresholdExceeded(double threshold) const {
    return altitude > threshold;
}

void SensorSimulator::logData(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open log file.");
    }

    for (const auto& entry : dataLog) {
        auto time = entry.first;
        auto tt = std::chrono::system_clock::to_time_t(time);
        file << "Timestamp: " << std::put_time(std::localtime(&tt), "%F %T") << ", Altitude: " << entry.second << std::endl;
    }

    file.close();
}

void SensorSimulator::setAcceleration(double acc) {
    acceleration = acc;
}