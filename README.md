# Realtime_Sensor_Simulator

A console-based C++ application that simulates sensor data (such as altitude and acceleration for a rocket) in real-time, processes it with basic thresholding logic, and logs outputs. This project mimics embedded systems monitoring, similar to an extremely simplified version of those used in aerospace applications at companies like SpaceX. It uses standard C++ libraries for timing, threading, and file I/O, making it lightweight and educational for building skills in systems programming, real-time simulation, and data handling.

The simulation runs for approximately 5 seconds, updating sensor values every 100ms with added random noise for realism. It checks if altitude exceeds a 1000m threshold (triggering an alert) and logs timestamped data to a file.

## Features
- **Real-Time Simulation**: Uses `<chrono>` and `<thread>` to simulate time-based updates at fixed intervals.
- **Physics-Based Sensor Model**: Simple Euler integration for velocity and altitude based on acceleration (with gravity/thrust approximation).
- **Noise Injection**: Random variation in acceleration to mimic real-world sensor imperfections.
- **Thresholding Logic**: Alerts if altitude exceeds a configurable threshold (default: 1000m).
- **Logging**: Writes timestamped altitude data to a text file with error handling.
- **Containerization**: Docker support for consistent builds and runs on Debian/Ubuntu-based environments.
- **Version Control Integration**: Git/GitHub for committing changes during development.

## Prerequisites
- **C++ Compiler**: g++ (GCC) or equivalent, supporting C++11 or later.
- **Development Tools**: Visual Studio, VSCode, or any IDE/editor with C++ support.
- **Docker**: For containerized builds and runs. Install from [docker.com](https://www.docker.com).
- **Operating System**: Tested on Ubuntu/Debian; should work on Windows/Mac with minor adjustments.
- **Libraries**: No external dependencies—uses only standard C++ headers (`<iostream>`, `<chrono>`, `<thread>`, `<random>`, `<fstream>`, `<vector>`, `<iomanip>`, `<stdexcept>`, `<ctime>`).

## Project Structure
- `main.cpp`: Entry point; handles the simulation loop, noise addition, thresholding, and logging invocation.
- `SensorSimulator.h`: Header file declaring the `SensorSimulator` class with private members (altitude, velocity, acceleration, dataLog) and public methods (update, getAltitude, isThresholdExceeded, logData, setAcceleration).
- `SensorSimulator.cpp`: Implementation of the class methods, including physics updates, logging with timestamps, and error handling.
- `Dockerfile`: Script for building a Docker image with g++ compilation.
- `README.md`: This file.
- `sensor_log.txt`: Generated output file (after running the app).

## Building and Running Locally (Without Docker)
1. **Clone the Repository**:
   ```
   git clone https://github.com/Butlchr17/Realtime_Sensor_Simulator.git
   cd Realtime_Sensor_Simulator
   ```

2. **Compile the Code**:
   Use g++ to build the executable:
   ```
   g++ -std=c++11 -o sensor_simulator main.cpp SensorSimulator.cpp
   ```
   - This creates the binary `sensor_simulator`.
   - If on Windows (e.g., with MinGW), adjust paths as needed.

3. **Run the Application**:
   ```
   ./sensor_simulator
   ```
   - The console will display real-time altitude updates (e.g., "Current Altitude: X m").
   - If altitude > 1000m, an alert prints (e.g., "Alert: Altitude exceeded 1000m!").
   - After ~5 seconds, it logs data and prints "Data logged successfully."
   - Check `sensor_log.txt` for output like:
     ```
     Timestamp: 2025-07-18 12:34:56, Altitude: 10.5
     Timestamp: 2025-07-18 12:34:56, Altitude: 21.0
     ...
     ```

4. **Clean Up** (Optional):
   ```
   rm sensor_simulator sensor_log.txt
   ```

## Building and Running with Docker
Docker ensures a consistent environment, ideal for cross-platform development or deployment.

1. **Build the Image**:
   From the project directory:
   ```
   docker build -t sensor-simulator-image .
   ```
   - This installs g++, copies files, and compiles the code inside an Ubuntu 24.04 container.
   - Image size: ~400MB.

2. **Run the Container**:
   For basic execution (log file not persisted):
   ```
   docker run --rm sensor-simulator-image
   ```
   - To persist `sensor_log.txt` locally (mounts a subdirectory to avoid overwriting the binary):
     - First, create an `output/` directory: `mkdir output`
     - Update `main.cpp` to log to `"output/sensor_log.txt"` and rebuild the image.
     - Run: `docker run --rm -v $(pwd)/output:/app/output sensor-simulator-image`

   Alternatively, run interactively:
   ```
   docker run -it --rm sensor-simulator-image bash
   ```
   - Inside the container: `./sensor_simulator`

3. **Troubleshooting Docker**:
   - If build fails: Check file names/casing, or use `--no-cache` flag.
   - Retrieve log from non-persisted run: Use `docker cp` as described in troubleshooting notes.
   - Remove image: `docker rmi sensor-simulator-image`.

## License
MIT License – Feel free to use, modify, and distribute.
