# Traffic Light System 🚦

CSC 300 Week#4 Deliverable

## 📋 Project Overview
The Traffic Light System uses sensors to detect vehicles and pedestrian button activations at an intersection. It prioritizes emergency vehicles and manages vehicle queues to reduce congestion. The simulation continues until an emergency vehicle arrives or a queue backs up to 10 vehicles, at which point the light turns green to clear the traffic.

### Key Features
- **Vehicle Detection**: Detects regular and emergency vehicles.
- **Queue Management**: Monitors queue lengths and clears traffic when full.
- **Emergency Vehicle Priority**: Overrides normal signal operations to allow emergency vehicles to pass.
- **Pedestrian Crossings**: Handles pedestrian button presses for safe crossing.


### ⚙️ Build Instructions
To build and run the project, make sure you have **CMake** installed.

1. Clone the repository:
   ```bash
   git clone https://github.com/Mark-Langston/TrafficLightSystem.git
   cd TrafficLightSystem

### Build the project using CMake

mkdir build
cd build
cmake ..
make
