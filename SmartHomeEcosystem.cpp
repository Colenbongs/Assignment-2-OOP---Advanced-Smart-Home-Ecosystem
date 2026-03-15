#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdexcept>  // for exceptions
using namespace std;

#include "SmartDevice.h"
#include "Light.h"
#include "Thermostat.h"
#include "Speaker.h"
#include "Camera.h"
#include "Room.h"
#include "SmartHome.h"

// change console text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// color codes
const int COLOR_GREEN = 10;
const int COLOR_YELLOW = 14;
const int COLOR_RED = 12;
const int COLOR_WHITE = 7;

// clear screen
void clearScreen() {
    system("cls");
}

// wait for key press
void pressAnyKey() {
    setColor(COLOR_YELLOW);
    cout << "\nPress any key to continue...";
    setColor(COLOR_WHITE);
    _getch();
}

int main() {
    try {
        SmartHome myHome("My Smart Home");
        vector<Room*> rooms;
        int choice;

        do {
            try {
                // show menu
                clearScreen();
                setColor(COLOR_GREEN);
                cout << "==========================" << endl;
                cout << "    SMART HOME SYSTEM" << endl;
                cout << "==========================" << endl;
                setColor(COLOR_YELLOW);

                cout << "\n1. View all devices" << endl;
                cout << "2. Turn ON/OFF device" << endl;
                cout << "3. Adjust device" << endl;
                cout << "4. Add new device" << endl;
                cout << "5. Add new room" << endl;
                cout << "6. Exit" << endl;

                setColor(COLOR_YELLOW);
                cout << "\nChoice: ";
                setColor(COLOR_WHITE);
                
                if (!(cin >> choice)) {
                    throw runtime_error("Invalid input - please enter a number");
                }

                // view all devices
                if (choice == 1) {
                    clearScreen();
                    setColor(COLOR_GREEN);
                    cout << "\n=== ALL DEVICES ===" << endl;
                    setColor(COLOR_WHITE);
                    
                    if (rooms.empty()) {
                        cout << "No rooms yet." << endl;
                    } else {
                        for (auto room : rooms) {
                            if (room == nullptr) {
                                throw runtime_error("Null room found");
                            }
                            room->showDevices();
                        }
                    }
                    pressAnyKey();
                }

                // turn device on or off
                else if (choice == 2) {
                    clearScreen();
                    if (rooms.empty()) {
                        throw runtime_error("No rooms available");
                    }

                    // show rooms
                    cout << "\nRooms:" << endl;
                    for (int i = 0; i < rooms.size(); i++) {
                        cout << " " << (i+1) << ". " << rooms[i]->getName() << endl;
                    }

                    // select room
                    cout << "\nPick room: ";
                    int r;
                    if (!(cin >> r)) {
                        throw runtime_error("Invalid room number");
                    }
                    r--;

                    if (r < 0 || r >= rooms.size()) {
                        throw runtime_error("Room number out of range");
                    }

                    Room* room = rooms[r];
                    if (room == nullptr) {
                        throw runtime_error("Room is null");
                    }
                    
                    // check if room has devices
                    if (room->getDevices().empty()) {
                        throw runtime_error("No devices in this room");
                    }

                    // show devices in room
                    cout << "\nDevices:" << endl;
                    for (int i = 0; i < room->getDevices().size(); i++) {
                        cout << " " << (i+1) << ". ";
                        room->getDevices()[i]->showStatus();
                    }

                    // select device
                    cout << "\nPick device: ";
                    int d;
                    if (!(cin >> d)) {
                        throw runtime_error("Invalid device number");
                    }
                    d--;

                    if (d < 0 || d >= room->getDevices().size()) {
                        throw runtime_error("Device number out of range");
                    }

                    SmartDevice* dev = room->getDevices()[d];
                    if (dev == nullptr) {
                        throw runtime_error("Device is null");
                    }

                    // choose on or off
                    cout << "\n1. ON  2. OFF" << endl;
                    cout << "Choice: ";
                    int onoff;
                    if (!(cin >> onoff)) {
                        throw runtime_error("Invalid choice");
                    }

                    if (onoff == 1) {
                        dev->turnOn();
                    } else if (onoff == 2) {
                        dev->turnOff();
                    } else {
                        throw runtime_error("Choice must be 1 or 2");
                    }
                    
                    pressAnyKey();
                }

                // adjust device settings
                else if (choice == 3) {
                    clearScreen();
                    if (rooms.empty()) {
                        throw runtime_error("No rooms available");
                    }

                    // show rooms
                    cout << "\nRooms:" << endl;
                    for (int i = 0; i < rooms.size(); i++) {
                        cout << " " << (i+1) << ". " << rooms[i]->getName() << endl;
                    }

                    // select room
                    cout << "\nPick room: ";
                    int r;
                    if (!(cin >> r)) {
                        throw runtime_error("Invalid room number");
                    }
                    r--;

                    if (r < 0 || r >= rooms.size()) {
                        throw runtime_error("Room number out of range");
                    }

                    Room* room = rooms[r];
                    if (room == nullptr) {
                        throw runtime_error("Room is null");
                    }
                    
                    // check if room has devices
                    if (room->getDevices().empty()) {
                        throw runtime_error("No devices in this room");
                    }

                    // show devices
                    cout << "\nDevices:" << endl;
                    for (int i = 0; i < room->getDevices().size(); i++) {
                        cout << " " << (i+1) << ". ";
                        room->getDevices()[i]->showStatus();
                    }

                    // select device
                    cout << "\nPick device: ";
                    int d;
                    if (!(cin >> d)) {
                        throw runtime_error("Invalid device number");
                    }
                    d--;

                    if (d < 0 || d >= room->getDevices().size()) {
                        throw runtime_error("Device number out of range");
                    }

                    SmartDevice* dev = room->getDevices()[d];
                    if (dev == nullptr) {
                        throw runtime_error("Device is null");
                    }

                    // cameras cant be adjusted
                    if (dev->getType() == "CAMERA") {
                        throw runtime_error("Cameras cannot be adjusted");
                    }

                    // get adjustment value
                    cout << "\nEnter value: ";
                    int val;
                    if (!(cin >> val)) {
                        throw runtime_error("Invalid value");
                    }
                    dev->adjust(val);
                    
                    pressAnyKey();
                }

                // add new device to a room
                else if (choice == 4) {
                    clearScreen();
                    if (rooms.empty()) {
                        throw runtime_error("Please add a room first");
                    }

                    // show rooms
                    cout << "\nRooms:" << endl;
                    for (int i = 0; i < rooms.size(); i++) {
                        cout << " " << (i+1) << ". " << rooms[i]->getName() << endl;
                    }

                    // select room
                    cout << "\nPick room: ";
                    int r;
                    if (!(cin >> r)) {
                        throw runtime_error("Invalid room number");
                    }
                    r--;

                    if (r < 0 || r >= rooms.size()) {
                        throw runtime_error("Room number out of range");
                    }

                    Room* room = rooms[r];
                    if (room == nullptr) {
                        throw runtime_error("Room is null");
                    }

                    // choose device type
                    cout << "\nDevice types:" << endl;
                    cout << "1. Light" << endl;
                    cout << "2. Thermostat" << endl;
                    cout << "3. Speaker" << endl;
                    cout << "4. Camera" << endl;
                    cout << "Pick type: ";
                    
                    int t;
                    if (!(cin >> t)) {
                        throw runtime_error("Invalid device type");
                    }
                    cin.ignore();

                    if (t < 1 || t > 4) {
                        throw runtime_error("Device type must be 1-4");
                    }

                    // get device name
                    cout << "Name: ";
                    string name;
                    getline(cin, name);
                    
                    if (name.empty()) {
                        throw runtime_error("Device name cannot be empty");
                    }

                    // create and add device
                    if (t == 1) room->addDevice(new Light(name));
                    else if (t == 2) room->addDevice(new Thermostat(name));
                    else if (t == 3) room->addDevice(new Speaker(name));
                    else room->addDevice(new Camera(name));

                    setColor(COLOR_GREEN);
                    cout << "\nDevice added" << endl;
                    pressAnyKey();
                }

                // add new room
                else if (choice == 5) {
                    clearScreen();
                    cout << "\nRoom name: ";
                    string name;
                    cin.ignore();
                    getline(cin, name);
                    
                    if (name.empty()) {
                        throw runtime_error("Room name cannot be empty");
                    }

                    Room* r = new Room(name);
                    if (r == nullptr) {
                        throw runtime_error("Failed to create room");
                    }
                    
                    rooms.push_back(r);
                    myHome.addRoom(r);

                    setColor(COLOR_GREEN);
                    cout << "\nRoom added" << endl;
                    pressAnyKey();
                }

                else if (choice == 6) {
                    // exit - do nothing
                }

                else {
                    throw runtime_error("Choice must be between 1 and 6");
                }

            }
            catch (const runtime_error& e) {
                setColor(COLOR_RED);
                cout << "\nError: " << e.what() << endl;
                setColor(COLOR_WHITE);
                
                // clear input buffer
                cin.clear();
                cin.ignore(10000, '\n');
                
                pressAnyKey();
            }
            catch (...) {
                setColor(COLOR_RED);
                cout << "\nUnknown error occurred" << endl;
                setColor(COLOR_WHITE);
                
                cin.clear();
                cin.ignore(10000, '\n');
                
                pressAnyKey();
            }

        } while (choice != 6);

        // exit message
        clearScreen();
        setColor(COLOR_GREEN);
        cout << "==========================" << endl;
        cout << "        GOODBYE" << endl;
        cout << "==========================" << endl;
        setColor(COLOR_WHITE);

        rooms.clear();
        return 0;
    }
    catch (const bad_alloc& e) {
        setColor(COLOR_RED);
        cout << "\nMemory allocation error: " << e.what() << endl;
        setColor(COLOR_WHITE);
        return 1;
    }
    catch (const exception& e) {
        setColor(COLOR_RED);
        cout << "\nFatal error: " << e.what() << endl;
        setColor(COLOR_WHITE);
        return 1;
    }
    catch (...) {
        setColor(COLOR_RED);
        cout << "\nUnknown fatal error" << endl;
        setColor(COLOR_WHITE);
        return 1;
    }
}
