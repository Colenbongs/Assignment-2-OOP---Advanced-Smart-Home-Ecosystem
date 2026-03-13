# Assignment-2-OOP---Advanced-Smart-Home-Ecosystem
Advanced Programming OOP assignment: C++ Smart Home Ecosystem that controls lights, thermostats, speakers, and security cameras using object-oriented principles.


# Smart Home Ecosystem (Assignment 2)
## Advanced Object-Oriented Programming Assignment

---

## Table of Contents
1. [Overview](#overview)
2. [Features](#features)
3. [Class Hierarchy](#class-hierarchy)
4. [Requirements Met](#requirements-met)
5. [Setup Instructions](#setup-instructions)
6. [Usage Guide](#usage-guide)
7. [Code Structure](#code-structure)
8. [Error Handling](#error-handling)
9. [Sample Output](#sample-output)
10. [Troubleshooting](#troubleshooting)
11. [References](#references)

---

## Overview

The Smart Home Ecosystem is a console-based C++ application that demonstrates core Object-Oriented Programming concepts including inheritance, polymorphism, encapsulation, and composition. The system simulates a smart home environment where users can manage various smart devices across different rooms.

This project was developed as part of the APM11A1 Assignment 2, following specific business rules and constraints outlined in the assignment brief. The system manages multiple device types (Lights, Thermostats, Speakers, and Security Cameras) organized into rooms, with a user-friendly menu interface.

---

## Features

### Core Functionality
- **Device Management**: Control Lights, Thermostats, Speakers, and Security Cameras
- **Room Organization**: Group devices by rooms (Living Room, Bedroom, Kitchen, etc.)
- **Polymorphic Control**: Common interface for all devices through base class pointers
- **Status Tracking**: View real-time status of all devices with unique IDs

### Device Capabilities

| Device Type | Capabilities | Adjustable Settings |
|-------------|--------------|---------------------|
| Light | On/Off, Brightness control | 0-100% brightness |
| Thermostat | On/Off, Temperature control | 10-35°C |
| Speaker | On/Off, Volume control | 0-100% volume |
| Camera | On/Off, Recording status | Not adjustable |

### System Features
- Unique Device IDs for tracking
- Last Used Timestamp tracking
- Room statistics by device type
- System dashboard with overall statistics
- Colored console output for visual feedback
- Comprehensive error handling
- Input validation with clear warnings

---

## Class Hierarchy

```
SmartDevice (Abstract Base Class)
├── Light
├── Thermostat
├── Speaker
└── Camera

Room (contains multiple SmartDevice objects)
└── SmartHome (contains multiple Room objects)
```

### Class Relationships
- **Inheritance**: All device classes inherit from SmartDevice
- **Composition**: Room contains SmartDevice objects; SmartHome contains Room objects
- **Polymorphism**: Device control through base class pointers

---

## Requirements Met

### Business Rules
- Each device inherits from SmartDevice base class
- All devices implement turnOn(), turnOff(), and getStatus()
- Rooms can contain multiple devices
- Smart Home manages multiple rooms
- Security cameras cannot be adjusted (only on/off and status)

### Constraints
- **Encapsulation**: Private member variables with public accessor methods
- **Polymorphism**: Device control through base class pointers
- **Scalability**: New devices can be added without modifying existing code
- **Usability**: Clear console-based menu interaction

---

## Setup Instructions

### Prerequisites
- Visual Studio 2022 (Community, Professional, or Enterprise)
- Windows 10 or Windows 11 operating system
- Basic understanding of C++ and OOP concepts

### Step-by-Step Setup

#### 1. Create New Project
```
1. Open Visual Studio 2022
2. Click "Create a new project"
3. Select "Console App" (C++)
4. Name the project: "SmartHomeEcosystem"
5. Choose a location for the project
6. Click "Create"
```

#### 2. Add Header Files
Right-click on the "Header Files" folder in Solution Explorer, then select:
```
Add → New Item → Header File (.h)
```

Create the following header files:
- SmartDevice.h
- Light.h
- Thermostat.h
- Speaker.h
- Camera.h
- Room.h

#### 3. Add Source File
The main source file is already created as SmartHomeEcosystem.cpp in the "Source Files" folder. Replace its contents with the provided code.

#### 4. Configure Project Settings
```
1. Right-click on the project in Solution Explorer
2. Select "Properties"
3. Set Configuration to "All Configurations"
4. Navigate to: C/C++ → Language
5. Set "C++ Language Standard" to "ISO C++17 Standard (/std:c++17)"
6. Click "Apply" and "OK"
```

#### 5. Build and Run
```
Press Ctrl + Shift + B to build the solution
Press Ctrl + F5 to run without debugging
Press F5 to run with debugging
```

---

## Usage Guide

### Main Menu Options

Upon running the program, the main menu displays:

```
================================================
     SMART HOME CONTROL SYSTEM
================================================
Date/Time: [current date and time]
================================================

MAIN MENU
1. View all devices
2. Turn device ON/OFF
3. Adjust device settings
4. Add new device
5. Add new room
6. Room control (all ON/OFF)
7. System statistics
8. Exit

Choice: _
```

### Detailed Option Descriptions

#### Option 1: View All Devices
Displays all rooms and their devices with current status:
- Device type, name, and unique ID
- Power state (ON or OFF)
- Current settings (brightness, temperature, volume, recording status)

#### Option 2: Turn Device ON/OFF
1. Enter the room name
2. View devices in that room
3. Enter the device name
4. Choose 1 for ON or 2 for OFF

#### Option 3: Adjust Device Settings
1. Enter the room name
2. Enter the device name
3. Enter adjustment value:
   - Lights: 0-100 (brightness percentage)
   - Thermostats: 10-35 (temperature in Celsius)
   - Speakers: 0-100 (volume percentage)
   - Cameras: Cannot adjust (warning displayed)

#### Option 4: Add New Device
1. Select room by number from the displayed list
2. Choose device type (1-4)
3. Enter a name for the new device
4. Confirmation message displays with assigned device ID

#### Option 5: Add New Room
1. Enter the new room name
2. Enter room area in square meters (default 20.0)
3. Enter floor number (default 1)
4. Confirmation message displays

#### Option 6: Room Control
1. Enter the room name
2. Choose 1 to turn ALL devices ON
3. Choose 2 to turn ALL devices OFF

#### Option 7: System Statistics
Displays:
- Total number of rooms
- Total number of devices (by type)
- Number of devices currently ON
- Usage rate percentage

#### Option 8: Exit
Cleanly exits the program with a goodbye message.

---

## Code Structure

### File Organization

```
SmartHomeEcosystem/
│
├── Header Files/
│   ├── SmartDevice.h      # Abstract base class definition
│   ├── Light.h            # Light device class definition
│   ├── Thermostat.h       # Thermostat device class definition
│   ├── Speaker.h          # Speaker device class definition
│   ├── Camera.h           # Camera device class definition
│   └── Room.h             # Room class definition
│
└── Source Files/
    └── SmartHomeEcosystem.cpp  # Main program implementation
```

### Key Code Components

#### SmartDevice.h (Base Class)
```cpp
class SmartDevice {
protected:
    string name;
    string type;
    bool powerStatus;
    int deviceID;
    static int nextID;
    time_t lastUsed;

public:
    SmartDevice(string n, string t);
    virtual ~SmartDevice();
    virtual void turnOn();
    virtual void turnOff();
    virtual void showStatus();
    virtual void adjust(int value);
    string getName();
    string getType();
    bool isOn();
    int getID();
};
```

#### Polymorphic Control Example
```cpp
// Vector of base class pointers
vector<SmartDevice*> devices;

// Add different device types
devices.push_back(new Light("Desk Lamp"));
devices.push_back(new Thermostat("Living Room Thermostat"));
devices.push_back(new Speaker("Kitchen Speaker"));

// Polymorphic calls
for (auto device : devices) {
    device->turnOn();  // Calls appropriate derived class method
    device->showStatus();
}
```

---

## Error Handling

### Input Validation
The system includes comprehensive input validation:

| Input Type | Validation | Error Message |
|------------|------------|---------------|
| Menu choice | Must be 1-8 | [ERROR] Invalid choice! Please enter 1-8. |
| Room selection | Must be within range | [ERROR] Invalid room selection! |
| Device type | Must be 1-4 | [ERROR] Invalid device type! |
| Device name | Cannot be empty | [ERROR] Device name cannot be empty! |
| Adjustment values | Must be within range | [WARNING] Brightness must be 0-100! |

### Exception Handling
```cpp
try {
    targetRoom->addDevice(new Light(devName));
}
catch (bad_alloc&) {
    setColor(12); // Red
    cout << "[ERROR] Memory allocation failed!" << endl;
}
catch (...) {
    setColor(12); // Red
    cout << "[ERROR] Failed to create device!" << endl;
}
```

### Color Coding
- **Green**: Headers and success messages
- **Red**: Errors and warnings
- **Yellow**: Exit messages
- **White**: Normal text and prompts

---

## Sample Output

### Adding a New Device
```
================================================
     SMART HOME CONTROL SYSTEM
================================================

Available rooms:
   1. Living Room
   2. Bedroom
   3. Kitchen

Select room by number (1-3): 1

Device types:
   1. Light
   2. Thermostat
   3. Speaker
   4. Camera
Choice: 1

Enter device name: Desk Lamp

Added LIGHT 'Desk Lamp' to Living Room (ID: 1004)

✓ Device 'Desk Lamp' added to Living Room successfully!
```

### Viewing System Statistics
```
=== SYSTEM STATISTICS ===
Total rooms: 3
Total devices: 8
  - Lights: 4
  - Thermostats: 1
  - Speakers: 1
  - Cameras: 2

Devices currently ON: 3/8
Usage rate: 37.5%
```

### Error Message Example
```
[WARNING] Brightness must be 0-100!
```

---

## Troubleshooting

### Common Issues and Solutions

| Issue | Cause | Solution |
|-------|-------|----------|
| C4996: 'ctime' unsafe | Microsoft security warning | Add #define _CRT_SECURE_NO_WARNINGS at top of file |
| Colors not displaying | Virtual terminal not enabled | Add code to enable ENABLE_VIRTUAL_TERMINAL_PROCESSING |
| Multiple definition errors | Static variable in header | Move definition to .cpp file |
| Cannot add devices | Input buffer issues | Use number selection for rooms instead of typing names |
| Infinite loop on bad input | cin failure state | Add cin.clear() and cin.ignore() after invalid input |

### Quick Fixes

#### Fix for C4996 Warning
Add this line at the very top of SmartHomeEcosystem.cpp:
```cpp
#define _CRT_SECURE_NO_WARNINGS
```

#### Fix for Static Variable Error
Create SmartDevice.cpp with:
```cpp
#include "SmartDevice.h"
int SmartDevice::nextID = 1000;
```

#### Fix for Input Buffer Issues
```cpp
void clearInputBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}
```

---

## References

### Academic References

1. Deitel, P. & Deitel, H. (2017). *C++ How to Program* (10th ed.). Pearson Education.

2. Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.

3. University of Johannesburg. (2026). *APM11A1 Learning Guide 2026*. Department of Applied Mathematics.

4. University of Johannesburg. (2025). *Policy: Plagiarism*. Retrieved from UJ Library.

### Online Resources

5. Microsoft Corporation. (2026). *Visual Studio 2022 Documentation*. Retrieved from https://docs.microsoft.com/en-us/cpp/

6. cppreference.com. (2026). *C++ Reference*. Retrieved from https://en.cppreference.com/

7. Standard C++ Foundation. (2026). *C++ Core Guidelines*. Retrieved from https://isocpp.github.io/CppCoreGuidelines/

### Assignment Requirements

8. University of Johannesburg. (2026). *APM11A1 Assignment 2: OOP*. Department of Applied Mathematics.

---

## Declaration

We hereby declare that this assignment is our own original work. We have acknowledged all sources used and adhered to the University of Johannesburg's plagiarism policy.

---

</div>
