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
        std::vector<double> datalog;

    public:

        void update(double deltaTime);
        double getAltitude() const;
        bool isThresholdExceeded(double threshold) const;
        void logData(const std::string& filename) const;
        void setAltitude(double acc);

};

#endif // SENSORSIMULATOR_H