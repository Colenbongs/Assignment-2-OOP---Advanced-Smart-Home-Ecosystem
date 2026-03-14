#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdexcept>
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
        SmartHome myHome("Mansion");
        vector<Room*> rooms;
        int choice;

        // create 10 rooms like a mansion
        cout << "\nSetting up Mansion with 10 rooms..." << endl;
        
        Room* living = new Room("Living Room");
        Room* master = new Room("Master Bedroom");
        Room* guest = new Room("Guest Bedroom");
        Room* kitchen = new Room("Kitchen");
        Room* dining = new Room("Dining Room");
        Room* theatre = new Room("Home Theatre");
        Room* office = new Room("Office");
        Room* garage = new Room("Garage");
        Room* garden = new Room("Garden");
        Room* security = new Room("Security Room");
        
        rooms.push_back(living);
        rooms.push_back(master);
        rooms.push_back(guest);
        rooms.push_back(kitchen);
        rooms.push_back(dining);
        rooms.push_back(theatre);
        rooms.push_back(office);
        rooms.push_back(garage);
        rooms.push_back(garden);
        rooms.push_back(security);
        
        // add all rooms to smart home
        myHome.addRoom(living);
        myHome.addRoom(master);
        myHome.addRoom(guest);
        myHome.addRoom(kitchen);
        myHome.addRoom(dining);
        myHome.addRoom(theatre);
        myHome.addRoom(office);
        myHome.addRoom(garage);
        myHome.addRoom(garden);
        myHome.addRoom(security);
        
        // add some initial devices to make it interesting
        living->addDevice(new Light("Ceiling Light"));
        living->addDevice(new Speaker("Living Room Speaker"));
        
        master->addDevice(new Light("Master Bed Light"));
        master->addDevice(new Thermostat("Master Thermostat"));
        
        guest->addDevice(new Light("Guest Bed Light"));
        
        kitchen->addDevice(new Light("Kitchen Light"));
        kitchen->addDevice(new Speaker("Kitchen Speaker"));
        
        dining->addDevice(new Light("Dining Light"));
        
        theatre->addDevice(new Light("Theatre Light"));
        theatre->addDevice(new Speaker("Surround Sound"));
        
        office->addDevice(new Light("Desk Light"));
        office->addDevice(new Thermostat("Office Thermostat"));
        
        garage->addDevice(new Light("Garage Light"));
        garage->addDevice(new Camera("Garage Camera"));
        
        garden->addDevice(new Light("Garden Light"));
        garden->addDevice(new Camera("Garden Camera"));
        
        security->addDevice(new Camera("Security Camera"));
        security->addDevice(new Light("Security Light"));

        setColor(COLOR_GREEN);
        cout << "\n==================================" << endl;
        cout << "    Mansion Setup Complete!" << endl;
        cout << "    10 rooms with 19 devices" << endl;
        cout << "==================================" << endl;
        setColor(COLOR_WHITE);
        pressAnyKey();

        do {
            try {
                // show menu
                clearScreen();
                setColor(COLOR_GREEN);
                cout << "================================" << endl;
                cout << "      MANSION SMART HOME" << endl;
                cout << "================================" << endl;
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
                    cout << "\n=== ALL DEVICES IN MANSION ===" << endl;
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
                    cout << "\nMansion Rooms:" << endl;
                    for (int i = 0; i < rooms.size(); i++) {
                        cout << " " << (i+1) << ". " << rooms[i]->getName() << endl;
                    }

                    // select room
                    cout << "\nPick room (1-10): ";
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
                    cout << "\nDevices in " << room->getName() << ":" << endl;
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
                    cout << "\nMansion Rooms:" << endl;
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
                    cout << "\nDevices in " << room->getName() << ":" << endl;
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
                    cout << "\nMansion Rooms:" << endl;
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
                    cout << "\nDevice added to " << room->getName() << endl;
                    pressAnyKey();
                }

                // add new room
                else if (choice == 5) {
                    clearScreen();
                    cout << "\nNew room name: ";
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
                    cout << "\nRoom '" << name << "' added to mansion" << endl;
                    pressAnyKey();
                }

                else if (choice == 6) {
                    // exit
                }

                else {
                    throw runtime_error("Choice must be between 1 and 6");
                }

            }
            catch (const runtime_error& e) {
                setColor(COLOR_RED);
                cout << "\nError: " << e.what() << endl;
                setColor(COLOR_WHITE);
                
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
        cout << "================================" << endl;
        cout << "    THANK YOU FOR USING" << endl;
        cout << "      MANSION SMART HOME" << endl;
        cout << "================================" << endl;
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
