#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // for _getch()
#include <windows.h> // for SetConsoleTextAttribute
using namespace std;

#include "SmartDevice.h"
#include "Light.h"
#include "Thermostat.h"
#include "Speaker.h"
#include "Camera.h"
#include "Room.h"

// Function to set console color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Color constants
const int COLOR_GREEN = 10;
const int COLOR_YELLOW = 14;
const int COLOR_RED = 12;
const int COLOR_WHITE = 7;
const int COLOR_CYAN = 11;

// Function to clear screen
void clearScreen() {
    system("cls");
}

// Function to pause and wait for key press
void pressAnyKey() {
    setColor(COLOR_YELLOW);
    cout << "\nPress any key to continue...";
    setColor(COLOR_WHITE);
    _getch();
}

// Helper function to display rooms with numbers (prompts in yellow)
void displayRooms(vector<Room*>& rooms) {
    setColor(COLOR_YELLOW);
    cout << "\nAvailable rooms:" << endl;
    setColor(COLOR_WHITE);
    for (int i = 0; i < rooms.size(); i++) {
        cout << "   " << (i + 1) << ". " << rooms[i]->getName() << endl;
    }
}

// Helper function to display devices in a room with numbers
void displayDevicesInRoom(Room* room) {
    setColor(COLOR_CYAN);
    cout << "\nDevices in " << room->getName() << ":" << endl;
    setColor(COLOR_WHITE);
    vector<SmartDevice*>& devices = room->getDevices();
    for (int i = 0; i < devices.size(); i++) {
        cout << "   " << (i + 1) << ". ";
        devices[i]->showStatus();
    }
}

int main() {
    vector<Room*> rooms;
    int choice;

    // Create some initial rooms
    rooms.push_back(new Room("Living Room"));
    rooms.push_back(new Room("Bedroom"));
    rooms.push_back(new Room("Kitchen"));

    // Add some initial devices
    rooms[0]->addDevice(new Light("Ceiling Light"));
    rooms[0]->addDevice(new Speaker("Smart Speaker"));
    rooms[0]->addDevice(new Camera("Front Camera"));

    rooms[1]->addDevice(new Light("Bedside Lamp"));
    rooms[1]->addDevice(new Thermostat("Room Thermostat"));

    rooms[2]->addDevice(new Light("Kitchen Light"));
    rooms[2]->addDevice(new Camera("Back Camera"));

    // Show success message for initialization
    setColor(COLOR_GREEN);
    cout << "======================================" << endl;
    cout << "    Smart Home System Initialized" << endl;
    cout << "    3 rooms and 8 devices loaded" << endl;
    cout << "======================================" << endl;
    setColor(COLOR_WHITE);
    pressAnyKey();

    do {
        clearScreen();
        setColor(COLOR_GREEN); // Green for header
        cout << "======================================" << endl;
        cout << "    SMART HOME CONTROL SYSTEM" << endl;
        cout << "======================================" << endl;
        setColor(COLOR_YELLOW); // Yellow for menu options

        cout << "\n1. View all devices" << endl;
        cout << "2. Turn device ON/OFF" << endl;
        cout << "3. Adjust device" << endl;
        cout << "4. Add new device" << endl;
        cout << "5. Add new room" << endl;
        cout << "6. Room control (all ON/OFF)" << endl;
        cout << "7. Apply Scene" << endl;
        cout << "8. Schedule Device" << endl;
        cout << "9. Exit" << endl;

        setColor(COLOR_YELLOW);
        cout << "\nChoice: ";
        setColor(COLOR_WHITE);
        cin >> choice;

        switch (choice) {
        case 1: { // View all devices
            clearScreen();
            setColor(COLOR_GREEN);
            cout << "\n=== ALL DEVICES ===" << endl;
            setColor(COLOR_WHITE);
            for (auto room : rooms) {
                room->showDevices();
            }
            pressAnyKey();
            break;
        }

        case 2: { // Turn device ON/OFF
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display rooms with numbers
            displayRooms(rooms);

            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            // Check if room has devices
            if (targetRoom->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No devices in this room!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display devices in selected room
            displayDevicesInRoom(targetRoom);

            setColor(COLOR_YELLOW);
            cout << "\nSelect device number: ";
            setColor(COLOR_WHITE);
            int deviceChoice;
            cin >> deviceChoice;

            if (deviceChoice < 1 || deviceChoice > targetRoom->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            SmartDevice* device = targetRoom->getDevices()[deviceChoice - 1];

            setColor(COLOR_YELLOW);
            cout << "\n1. Turn ON" << endl;
            cout << "2. Turn OFF" << endl;
            cout << "Choice: ";
            setColor(COLOR_WHITE);
            int onOff;
            cin >> onOff;

            cout << "\n";
            if (onOff == 1) {
                device->turnOn();
                setColor(COLOR_GREEN);
                cout << "[SAVED] Device state updated" << endl;
                setColor(COLOR_WHITE);
            }
            else if (onOff == 2) {
                device->turnOff();
                setColor(COLOR_GREEN);
                cout << "[SAVED] Device state updated" << endl;
                setColor(COLOR_WHITE);
            }
            else {
                setColor(COLOR_RED);
                cout << "[ERROR] Invalid choice!" << endl;
                setColor(COLOR_WHITE);
            }
            pressAnyKey();
            break;
        }

        case 3: { // Adjust device
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display rooms with numbers
            displayRooms(rooms);

            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            // Check if room has devices
            if (targetRoom->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No devices in this room!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display devices in selected room
            displayDevicesInRoom(targetRoom);

            setColor(COLOR_YELLOW);
            cout << "\nSelect device number: ";
            setColor(COLOR_WHITE);
            int deviceChoice;
            cin >> deviceChoice;

            if (deviceChoice < 1 || deviceChoice > targetRoom->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            SmartDevice* device = targetRoom->getDevices()[deviceChoice - 1];

            // Check if device can be adjusted (Camera can't)
            if (device->getType() == "CAMERA") {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Cameras cannot be adjusted!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            setColor(COLOR_YELLOW);
            cout << "\nEnter adjustment value: ";
            setColor(COLOR_WHITE);
            int value;
            cin >> value;

            cout << "\n";
            device->adjust(value);
            setColor(COLOR_GREEN);
            cout << "[SAVED] Device settings updated" << endl;
            setColor(COLOR_WHITE);
            pressAnyKey();
            break;
        }

        case 4: { // Add new device
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available! Please add a room first." << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display rooms with numbers
            displayRooms(rooms);

            setColor(COLOR_YELLOW);
            cout << "\nSelect room number to add device to: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            setColor(COLOR_YELLOW);
            cout << "\nDevice types:" << endl;
            cout << "   1. Light" << endl;
            cout << "   2. Thermostat" << endl;
            cout << "   3. Speaker" << endl;
            cout << "   4. Camera" << endl;
            cout << "Select device type: ";
            setColor(COLOR_WHITE);
            int devType;
            cin >> devType;
            cin.ignore();

            if (devType < 1 || devType > 4) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device type!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            setColor(COLOR_YELLOW);
            cout << "Enter device name: ";
            setColor(COLOR_WHITE);
            string devName;
            getline(cin, devName);

            cout << "\n";
            switch (devType) {
            case 1:
                targetRoom->addDevice(new Light(devName));
                break;
            case 2:
                targetRoom->addDevice(new Thermostat(devName));
                break;
            case 3:
                targetRoom->addDevice(new Speaker(devName));
                break;
            case 4:
                targetRoom->addDevice(new Camera(devName));
                break;
            }
            setColor(COLOR_GREEN);
            cout << "[SAVED] New device added to " << targetRoom->getName() << endl;
            setColor(COLOR_WHITE);
            pressAnyKey();
            break;
        }

        case 5: { // Add new room
            clearScreen();
            setColor(COLOR_YELLOW);
            cout << "Enter new room name: ";
            setColor(COLOR_WHITE);
            string newRoom;
            cin.ignore();
            getline(cin, newRoom);

            rooms.push_back(new Room(newRoom));
            setColor(COLOR_GREEN);
            cout << "\n[SAVED] Room '" << newRoom << "' added successfully!" << endl;
            setColor(COLOR_WHITE);
            pressAnyKey();
            break;
        }

        case 6: { // Room control (all ON/OFF)
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display rooms with numbers
            displayRooms(rooms);

            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            // Check if room has devices
            if (targetRoom->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No devices in this room!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            setColor(COLOR_YELLOW);
            cout << "\n1. Turn ALL devices ON" << endl;
            cout << "2. Turn ALL devices OFF" << endl;
            cout << "Choice: ";
            setColor(COLOR_WHITE);
            int action;
            cin >> action;

            cout << "\n";
            if (action == 1) {
                for (auto device : targetRoom->getDevices()) {
                    device->turnOn();
                }
                setColor(COLOR_GREEN);
                cout << "\n[SAVED] All devices in " << targetRoom->getName() << " turned ON" << endl;
                setColor(COLOR_WHITE);
            }
            else if (action == 2) {
                for (auto device : targetRoom->getDevices()) {
                    device->turnOff();
                }
                setColor(COLOR_GREEN);
                cout << "\n[SAVED] All devices in " << targetRoom->getName() << " turned OFF" << endl;
                setColor(COLOR_WHITE);
            }
            else {
                setColor(COLOR_RED);
                cout << "[ERROR] Invalid choice!" << endl;
                setColor(COLOR_WHITE);
            }
            pressAnyKey();
            break;
        }

        case 7: { // Apply Scene
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display rooms with numbers
            displayRooms(rooms);

            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            setColor(COLOR_YELLOW);
            cout << "\nAvailable Scenes:" << endl;
            cout << "   1. Good Morning" << endl;
            cout << "   2. Good Night" << endl;
            cout << "   3. Away" << endl;
            cout << "   4. Movie Time" << endl;
            cout << "Select scene: ";
            setColor(COLOR_WHITE);

            int sceneChoice;
            cin >> sceneChoice;

            string sceneName;
            switch (sceneChoice) {
            case 1: sceneName = "Good Morning"; break;
            case 2: sceneName = "Good Night"; break;
            case 3: sceneName = "Away"; break;
            case 4: sceneName = "Movie Time"; break;
            default:
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid scene!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                continue;
            }

            cout << "\n";
            targetRoom->applyScene(sceneName);
            setColor(COLOR_GREEN);
            cout << "[SAVED] Scene applied to " << targetRoom->getName() << endl;
            setColor(COLOR_WHITE);
            pressAnyKey();
            break;
        }

        case 8: { // Schedule Device
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display rooms with numbers
            displayRooms(rooms);

            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            // Check if room has devices
            if (targetRoom->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No devices in this room!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Display devices in selected room
            displayDevicesInRoom(targetRoom);

            setColor(COLOR_YELLOW);
            cout << "\nSelect device number to schedule: ";
            setColor(COLOR_WHITE);
            int deviceChoice;
            cin >> deviceChoice;

            if (deviceChoice < 1 || deviceChoice > targetRoom->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            SmartDevice* device = targetRoom->getDevices()[deviceChoice - 1];

            setColor(COLOR_YELLOW);
            cout << "\nSchedule time (24h format):" << endl;
            cout << "Hour (0-23): ";
            setColor(COLOR_WHITE);
            int hour;
            cin >> hour;

            if (hour < 0 || hour > 23) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Hour must be 0-23!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            setColor(COLOR_YELLOW);
            cout << "Minute (0-59): ";
            setColor(COLOR_WHITE);
            int minute;
            cin >> minute;

            if (minute < 0 || minute > 59) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Minute must be 0-59!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            setColor(COLOR_YELLOW);
            cout << "\nAction:" << endl;
            cout << "   1. Turn ON" << endl;
            cout << "   2. Turn OFF" << endl;
            cout << "Choice: ";
            setColor(COLOR_WHITE);
            int action;
            cin >> action;

            string actionStr = (action == 1) ? "ON" : "OFF";

            cout << "\n";
            targetRoom->scheduleAction(device->getName(), actionStr, hour, minute);
            setColor(COLOR_GREEN);
            cout << "[SAVED] Schedule created successfully" << endl;
            setColor(COLOR_WHITE);
            pressAnyKey();
            break;
        }

        case 9: // Exit
            clearScreen();
            setColor(COLOR_GREEN);
            cout << "======================================" << endl;
            cout << "    Thank you for using Smart Home!" << endl;
            cout << "            Goodbye!" << endl;
            cout << "======================================" << endl;
            setColor(COLOR_WHITE);
            break;

        default:
            setColor(COLOR_RED);
            cout << "\n[ERROR] Invalid choice! Please select 1-9." << endl;
            setColor(COLOR_WHITE);
            pressAnyKey();
        }

    } while (choice != 9);

    // Clean up
    for (auto room : rooms) {
        delete room;
    }

    return 0;
}