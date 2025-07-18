# Use Ubuntu as the base image (24.04 LTS for stability)
FROM ubuntu:24.04

# Install g++ and other build esentials
Run apt-get update && apt-get install -y \
	build-essential \
	&& rm -rf /var/lib/apt/lists/*

# Set working directory inside the container
WORKDIR /app

# Set working directory inside the container
COPY main.cpp SensorSimulator.h SensorSimulator.cpp /app/

# Debug: List files in /app and show current working directory
RUN ls -la /app
RUN pwd

# Compile the C++ code with g++
RUN g++ -std=c++11 -o sensor_simulator main.cpp SensorSimulator.cpp

# Set the entrypoint to run the compiled executable
ENTRYPOINT ["./sensor_simulator"]
