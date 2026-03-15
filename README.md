# Smart Home Control System

## Project Overview
A console-based Smart Home Control System that allows users to manage and control various smart devices across different rooms. The system simulates a real smart home environment with core device control features.

## Group Members - Group F

| Student Number | Name |
|---------------|------|
| 220115085 | Sandile Sibeko |
| 221152725 | Mongiwethu Eddy Ncube |
| 220068905 | Keamogetse Selebano |
| 220122253 | Ndzulamo Michelle Yingwani |
| 220080694 | Hlonipho Nersely Bila |
| 220061777 | Zizile Ezona Mbanqi |
| 219027546 | Bongane Sithole |

## Features

### Core Functionality
- Multiple Room Management: Create and manage different rooms
- Device Control: Turn devices ON/OFF individually
- Device Adjustment: Adjust settings for different device types
- Add Devices: Add new devices to any room
- Add Rooms: Create new rooms in the smart home

### Supported Devices
| Device Type | Functions | Adjustable Properties |
|-------------|-----------|----------------------|
| Light | ON/OFF | Brightness level (0-100%) |
| Thermostat | ON/OFF | Temperature setting (10-35°C) |
| Speaker | ON/OFF | Volume level (0-100%) |
| Camera | ON/OFF | Not adjustable |

## System Architecture

### Class Structure
```
SmartDevice (Abstract Base Class)
    ├── Light
    ├── Thermostat  
    ├── Speaker
    └── Camera

Room
    └── Contains multiple SmartDevice objects

SmartHome
    └── Contains multiple Room objects
```

### Key Components
- SmartDevice: Abstract base class defining common device behavior
- Device Classes: Specific implementations for each device type
- Room Class: Manages devices within a specific room
- SmartHome Class: Manages all rooms in the home
- Main Program: User interface with error handling

## How to Run

### Prerequisites
- Windows Operating System
- C++ Compiler (Visual Studio, MinGW, etc.)
- Console/Command Prompt

### Compilation (with g++)
```bash
g++ main.cpp -o SmartHome.exe -std=c++11
```

### Execution
```bash
./SmartHome.exe
```

## User Guide

### Main Menu Options

| Option | Description |
|--------|-------------|
| 1. View all devices | Display all devices in every room with their current status |
| 2. Turn ON/OFF device | Select a specific device and change its power state |
| 3. Adjust device | Modify device settings (brightness, temperature, volume) |
| 4. Add new device | Create and place a new device in any room |
| 5. Add new room | Create a new room in the house |
| 6. Exit | Close the application |

### Color Coding
- Green: Headers and success messages
- Yellow: Menu options and prompts
- Red: Error messages
- White: Regular text

## Example Usage

### Starting the Program
```
==========================
    SMART HOME SYSTEM
==========================

1. View all devices
2. Turn ON/OFF device
3. Adjust device
4. Add new device
5. Add new room
6. Exit

Choice: 
```

### Adding a New Room
1. Select option 5 from main menu
2. Enter room name (e.g., "Study")
3. Room is created and ready for devices

### Adding a New Device
1. Select option 4 from main menu
2. Choose a room from the list
3. Select device type (1-Light, 2-Thermostat, 3-Speaker, 4-Camera)
4. Enter device name
5. Device is now available for control

### Turning a Device ON/OFF
1. Select option 2 from main menu
2. Choose room containing the device
3. Choose device from list
4. Select 1 for ON or 2 for OFF

## Learning Outcomes

This project demonstrates:
- Object-Oriented Programming principles
  - Inheritance (devices inherit from SmartDevice)
  - Polymorphism (virtual functions)
  - Encapsulation (private members with public methods)
  - Abstraction (abstract base class)

- C++ Concepts
  - Dynamic memory allocation
  - Virtual functions and overriding
  - Exception handling with try-catch
  - Vector containers
  - File organization with header files

- Software Design
  - Clean user interface
  - Input validation
  - Error recovery
  - Memory management

## Technical Details

### Error Handling
The program includes comprehensive error handling:
- Try-catch blocks for all user inputs
- Validation of numeric ranges
- Null pointer checks
- Empty room/device checks
- Input buffer clearing after errors

### Memory Management
- Destructors properly clean up allocated memory
- Rooms delete their devices
- SmartHome deletes all rooms
- No memory leaks

## Requirements Met

From the assignment specifications:
- Multiple device types (Lights, Thermostats, Speakers, Cameras)
- Devices grouped into Rooms
- Turn devices on/off
- Adjust device settings
- View device status
- Extensible design (easy to add new devices)
- Polymorphic control through base class
- Cameras cannot be adjusted
- Encapsulation (private member variables)
- SmartHome class manages multiple rooms

## References

### Books
1. Deitel, P. & Deitel, H. (2017). C++ How to Program (10th ed.). Pearson Education.
2. Stroustrup, B. (2013). The C++ Programming Language (4th ed.). Addison-Wesley.

### Online Resources
3. cplusplus.com. (2026). C++ Reference Tutorial. http://www.cplusplus.com/doc/tutorial/
4. GeeksforGeeks. (2026). Object-Oriented Programming in C++. https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/
5. Microsoft Docs. (2026). C++ Language Documentation. https://docs.microsoft.com/en-us/cpp/cpp/
6. TutorialsPoint. (2026). C++ Inheritance. https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm

### Academic Sources
7. University of Johannesburg. (2026). APM11A1 Learning Unit 1: Introduction to OOP. [Course Material]
8. University of Johannesburg. (2026). APM11A1 Learning Unit 2: Inheritance and Polymorphism. [Course Material]

## Declaration

We hereby declare that this assignment is our own original work. All sources used have been properly referenced. We understand that plagiarism constitutes academic misconduct and may result in disciplinary action.

| Name | Signature | Date |
|------|-----------|------|
| Sandile Sibeko | S. Sibeko | 15 March 2026 |
| Mongiwethu Eddy Ncube | M.E. Ncube | 15 March 2026 |
| Keamogetse Selebano | K. Selebano | 15 March 2026 |
| Ndzulamo Michelle Yingwani | N.M. Yingwani | 15 March 2026 |
| Hlonipho Nersely Bila | H.N. Bila | 15 March 2026 |
| Zizile Ezona Mbanqi | Z.E. Mbanqi | 15 March 2026 |
| Bongane Sithole | B. Sithole | 15 March 2026 |

---
**Course**: APM11A1  
**Assignment**: 2 - Advanced Smart Home Ecosystem  
**Date**: 15 March 2026  
**Institution**: University of Johannesburg
```
