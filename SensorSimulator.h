#ifndef SENSORSIMULATOR_H
#define SENSORSIMULATOR_H

#include <vector>
#include <string>
#include <chrono>

class SensorSimulator {
    private:

        double altitude;
        double velocity;
        double acceleration;
        std::vector<std::pair<std::chrono::system_clock::time_point, double>> dataLog;

    public:
    
        SensorSimulator();

        void update(double deltaTime);
        double getAltitude() const;
        bool isThresholdExceeded(double threshold) const;
        void logData(const std::string& filename) const;
        void setAcceleration(double acc);

};

#endif // SENSORSIMULATOR_H