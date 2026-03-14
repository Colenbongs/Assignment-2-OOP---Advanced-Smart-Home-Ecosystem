# Smart Home Control System

## 📱 Project Overview
A console-based Smart Home Control System that allows users to manage and control various smart devices across different rooms. The system simulates a real smart home environment with features like device control, scheduling, and scene management.

## 👥 Group Members - Group F
| Student Number | Name |
|---------------|------|
| 220115085 | Sandile Sibeko |
| 221152725 | Mongiwethu Eddy Ncube |
| 220068905 | Keamogetse Selebano |
| 220122253 | Ndzulamo Michelle Yingwani |
| 220080694 | Hlonipho Nersely Bila |
| 220061777 | Zizile Ezona Mbanqi |
| 219027546 | Bongane Sithole |

## 🎯 Features

### Core Functionality
- **Multiple Room Management**: Create and manage different rooms (Living Room, Bedroom, Kitchen, etc.)
- **Device Control**: Turn devices ON/OFF individually
- **Bulk Operations**: Control all devices in a room simultaneously
- **Device Adjustment**: Adjust settings for different device types
- **Scene Management**: Apply preset scenes (Good Morning, Good Night, Away, Movie Time)
- **Scheduling**: Set timers for devices to turn ON/OFF at specific times

### Supported Devices
| Device Type | Functions | Adjustable Properties |
|------------|-----------|----------------------|
| 💡 Light | ON/OFF | Brightness level |
| 🌡️ Thermostat | ON/OFF | Temperature setting |
| 🔈 Speaker | ON/OFF | Volume level |
| 📹 Camera | ON/OFF | Not adjustable |

## 🏗️ System Architecture

### Class Structure
```
SmartDevice (Abstract Base Class)
    ├── Light
    ├── Thermostat  
    ├── Speaker
    └── Camera

Room
    └── Contains multiple SmartDevice objects
```

### Key Components
- **SmartDevice**: Abstract base class defining common device behavior
- **Device Classes**: Specific implementations for each device type
- **Room Class**: Manages devices within a specific room
- **Main Program**: User interface and menu system

## 🚀 How to Run

### Prerequisites
- Windows Operating System
- C++ Compiler (MinGW, Visual Studio, etc.)
- Console/Command Prompt

### Compilation
```bash
g++ main.cpp SmartDevice.cpp Light.cpp Thermostat.cpp Speaker.cpp Camera.cpp Room.cpp -o SmartHome.exe
```

### Execution
```bash
./SmartHome.exe
```

## 📖 User Guide

### Main Menu Options

1. **View all devices** - Display all devices in every room with their current status
2. **Turn device ON/OFF** - Select a specific device and change its power state
3. **Adjust device** - Modify device settings (brightness, temperature, volume)
4. **Add new device** - Create and place a new device in any room
5. **Add new room** - Create a new room in the house
6. **Room control** - Turn all devices in a room ON or OFF at once
7. **Apply Scene** - Apply preset configurations to a room
8. **Schedule Device** - Set automatic ON/OFF times for devices
9. **Exit** - Close the application

### Scene Presets

| Scene | Effect |
|-------|--------|
| 🌅 Good Morning | Lights ON, Thermostat warm, Speaker plays morning news |
| 🌙 Good Night | All devices OFF, Thermostat adjusts for sleeping |
| 🏃 Away | All devices OFF (security mode) |
| 🎬 Movie Time | Lights dim, Speaker optimizes for movies |

### Color Coding
- 🟢 **Green**: Headers and success messages
- 🟡 **Yellow**: Menu options and prompts
- 🔴 **Red**: Error messages
- 🔵 **Cyan**: Device listings
- ⚪ **White**: Regular text

## 💡 Example Usage

### Adding a New Device
1. Select option 4 from main menu
2. Choose a room (e.g., Living Room)
3. Select device type (e.g., 1 for Light)
4. Enter device name (e.g., "Floor Lamp")
5. Device is now available for control

### Scheduling a Device
1. Select option 8 from main menu
2. Choose room and device
3. Set time (e.g., 07:30)
4. Choose action (ON/OFF)
5. Device will automatically execute at specified time

## 🎓 Learning Outcomes
This project demonstrates:
- Object-Oriented Programming principles
- Inheritance and polymorphism
- Abstract classes and interfaces
- Vector containers and dynamic memory
- User interface design
- Input validation
- File structure organization

## 📝 Notes
- The system uses console colors for better user experience
- All data is stored in memory during runtime
- Input validation prevents invalid entries
- Memory is properly cleaned up on exit

## 🔧 Technical Requirements
- Windows OS (uses Windows.h for console colors)
- C++11 or later
- Console supporting ANSI color codes

---
*Developed as part of coursework demonstration*
