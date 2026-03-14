#include <iostream>
#include <vector>
#include <string>
#include <conio.h> // for _getch() - waits for key press
#include <windows.h> // for SetConsoleTextAttribute - colors text
using namespace std;

#include "SmartDevice.h"
#include "Light.h"
#include "Thermostat.h"
#include "Speaker.h"
#include "Camera.h"
#include "Room.h"

// === HELPER FUNCTIONS FOR DISPLAY ===
// These functions make the program look nice and consistent

// Changes text color in console
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Color codes for easy reference
const int COLOR_GREEN = 10;   // Success messages
const int COLOR_YELLOW = 14;  // Prompts and menus  
const int COLOR_RED = 12;     // Error messages
const int COLOR_WHITE = 7;    // Normal text
const int COLOR_CYAN = 11;    // Device lists

// Clears the screen for a fresh menu
void clearScreen() {
    system("cls");
}

// Pauses until user presses a key
void pressAnyKey() {
    setColor(COLOR_YELLOW);
    cout << "\nPress any key to continue...";
    setColor(COLOR_WHITE);
    _getch(); // Waits for key press
}

// Shows all rooms with numbers
void displayRooms(vector<Room*>& rooms) {
    setColor(COLOR_YELLOW);
    cout << "\nAvailable rooms:" << endl;
    setColor(COLOR_WHITE);
    for (int i = 0; i < rooms.size(); i++) {
        cout << "   " << (i + 1) << ". " << rooms[i]->getName() << endl;
    }
}

// Shows all devices in a room with numbers
void displayDevicesInRoom(Room* room) {
    setColor(COLOR_CYAN);
    cout << "\nDevices in " << room->getName() << ":" << endl;
    setColor(COLOR_WHITE);
    vector<SmartDevice*>& devices = room->getDevices();
    for (int i = 0; i < devices.size(); i++) {
        cout << "   " << (i + 1) << ". ";
        devices[i]->showStatus(); // Shows device name and if it's ON/OFF
    }
}

int main() {
    vector<Room*> rooms; // Stores all rooms in the house
    int choice; // User's menu choice

    // === SETUP: Create starting rooms and devices ===
    rooms.push_back(new Room("Living Room"));
    rooms.push_back(new Room("Bedroom"));
    rooms.push_back(new Room("Kitchen"));

    // Add devices to Living Room
    rooms[0]->addDevice(new Light("Ceiling Light"));
    rooms[0]->addDevice(new Speaker("Smart Speaker"));
    rooms[0]->addDevice(new Camera("Front Camera"));

    // Add devices to Bedroom
    rooms[1]->addDevice(new Light("Bedside Lamp"));
    rooms[1]->addDevice(new Thermostat("Room Thermostat"));

    // Add devices to Kitchen
    rooms[2]->addDevice(new Light("Kitchen Light"));
    rooms[2]->addDevice(new Camera("Back Camera"));

    // Welcome message
    setColor(COLOR_GREEN);
    cout << "======================================" << endl;
    cout << "    Smart Home System Initialized" << endl;
    cout << "    3 rooms and 8 devices loaded" << endl;
    cout << "======================================" << endl;
    setColor(COLOR_WHITE);
    pressAnyKey();

    // === MAIN PROGRAM LOOP ===
    // Keeps showing menu until user chooses Exit (9)
    do {
        clearScreen();
        
        // Display main menu
        setColor(COLOR_GREEN);
        cout << "======================================" << endl;
        cout << "    SMART HOME CONTROL SYSTEM" << endl;
        cout << "======================================" << endl;
        setColor(COLOR_YELLOW);

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

        // === MENU OPTIONS ===
        
        // OPTION 1: View all devices in all rooms
        if (choice == 1) {
            clearScreen();
            setColor(COLOR_GREEN);
            cout << "\n=== ALL DEVICES ===" << endl;
            setColor(COLOR_WHITE);
            // Loop through each room and show its devices
            for (auto room : rooms) {
                room->showDevices();
            }
            pressAnyKey();
        }

        // OPTION 2: Turn a specific device ON or OFF
        else if (choice == 2) {
            clearScreen();

            // Check if there are any rooms
            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Step 1: Select room
            displayRooms(rooms);
            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            // Validate room selection
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

            // Step 2: Select device
            displayDevicesInRoom(targetRoom);
            setColor(COLOR_YELLOW);
            cout << "\nSelect device number: ";
            setColor(COLOR_WHITE);
            int deviceChoice;
            cin >> deviceChoice;

            // Validate device selection
            if (deviceChoice < 1 || deviceChoice > targetRoom->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device number!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                break;
            }

            // Step 3: Choose ON or OFF
            SmartDevice* device = targetRoom->getDevices()[deviceChoice - 1];
            setColor(COLOR_YELLOW);
            cout << "\n1. Turn ON" << endl;
            cout << "2. Turn OFF" << endl;
            cout << "Choice: ";
            setColor(COLOR_WHITE);
            int onOff;
            cin >> onOff;

            // Step 4: Apply the action
            cout << "\n";
            if (onOff == 1) {
                device->turnOn();
                setColor(COLOR_GREEN);
                cout << "[SAVED] Device state updated" << endl;
            }
            else if (onOff == 2) {
                device->turnOff();
                setColor(COLOR_GREEN);
                cout << "[SAVED] Device state updated" << endl;
            }
            else {
                setColor(COLOR_RED);
                cout << "[ERROR] Invalid choice!" << endl;
            }
            setColor(COLOR_WHITE);
            pressAnyKey();
        }

        // OPTION 3: Adjust device settings (brightness, temperature, volume)
        else if (choice == 3) {
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                pressAnyKey();
                break;
            }

            // Select room (same as above)
            displayRooms(rooms);
            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            if (targetRoom->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No devices in this room!" << endl;
                pressAnyKey();
                break;
            }

            // Select device
            displayDevicesInRoom(targetRoom);
            setColor(COLOR_YELLOW);
            cout << "\nSelect device number: ";
            setColor(COLOR_WHITE);
            int deviceChoice;
            cin >> deviceChoice;

            if (deviceChoice < 1 || deviceChoice > targetRoom->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device number!" << endl;
                pressAnyKey();
                break;
            }

            SmartDevice* device = targetRoom->getDevices()[deviceChoice - 1];

            // Cameras cannot be adjusted (they only record)
            if (device->getType() == "CAMERA") {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Cameras cannot be adjusted!" << endl;
                pressAnyKey();
                break;
            }

            // Get adjustment value from user
            setColor(COLOR_YELLOW);
            cout << "\nEnter adjustment value: ";
            setColor(COLOR_WHITE);
            int value;
            cin >> value;

            cout << "\n";
            device->adjust(value); // Each device type adjusts differently
            setColor(COLOR_GREEN);
            cout << "[SAVED] Device settings updated" << endl;
            pressAnyKey();
        }

        // OPTION 4: Add a new device to a room
        else if (choice == 4) {
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available! Please add a room first." << endl;
                pressAnyKey();
                break;
            }

            // Select room to add device to
            displayRooms(rooms);
            setColor(COLOR_YELLOW);
            cout << "\nSelect room number to add device to: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            // Choose device type
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
            cin.ignore(); // Clear the input buffer

            if (devType < 1 || devType > 4) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device type!" << endl;
                pressAnyKey();
                break;
            }

            // Name the device
            setColor(COLOR_YELLOW);
            cout << "Enter device name: ";
            setColor(COLOR_WHITE);
            string devName;
            getline(cin, devName);

            // Create the selected device type
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
            pressAnyKey();
        }

        // OPTION 5: Add a new room
        else if (choice == 5) {
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
            pressAnyKey();
        }

        // OPTION 6: Turn all devices in a room ON or OFF at once
        else if (choice == 6) {
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                pressAnyKey();
                break;
            }

            // Select room
            displayRooms(rooms);
            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            if (targetRoom->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No devices in this room!" << endl;
                pressAnyKey();
                break;
            }

            // Choose action for all devices
            setColor(COLOR_YELLOW);
            cout << "\n1. Turn ALL devices ON" << endl;
            cout << "2. Turn ALL devices OFF" << endl;
            cout << "Choice: ";
            setColor(COLOR_WHITE);
            int action;
            cin >> action;

            // Apply to every device in the room
            cout << "\n";
            if (action == 1) {
                for (auto device : targetRoom->getDevices()) {
                    device->turnOn();
                }
                setColor(COLOR_GREEN);
                cout << "\n[SAVED] All devices in " << targetRoom->getName() << " turned ON" << endl;
            }
            else if (action == 2) {
                for (auto device : targetRoom->getDevices()) {
                    device->turnOff();
                }
                setColor(COLOR_GREEN);
                cout << "\n[SAVED] All devices in " << targetRoom->getName() << " turned OFF" << endl;
            }
            else {
                setColor(COLOR_RED);
                cout << "[ERROR] Invalid choice!" << endl;
            }
            pressAnyKey();
        }

        // OPTION 7: Apply a preset scene (predefined settings)
        else if (choice == 7) {
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                pressAnyKey();
                break;
            }

            // Select room
            displayRooms(rooms);
            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            // Choose scene
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

            // Convert number to scene name
            string sceneName;
            switch (sceneChoice) {
            case 1: sceneName = "Good Morning"; break;
            case 2: sceneName = "Good Night"; break;
            case 3: sceneName = "Away"; break;
            case 4: sceneName = "Movie Time"; break;
            default:
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid scene!" << endl;
                pressAnyKey();
                continue;
            }

            cout << "\n";
            targetRoom->applyScene(sceneName); // Room handles all device settings
            setColor(COLOR_GREEN);
            cout << "[SAVED] Scene applied to " << targetRoom->getName() << endl;
            pressAnyKey();
        }

        // OPTION 8: Schedule a device to turn ON/OFF at a specific time
        else if (choice == 8) {
            clearScreen();

            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No rooms available!" << endl;
                pressAnyKey();
                break;
            }

            // Select room
            displayRooms(rooms);
            setColor(COLOR_YELLOW);
            cout << "\nSelect room number: ";
            setColor(COLOR_WHITE);
            int roomChoice;
            cin >> roomChoice;

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid room number!" << endl;
                pressAnyKey();
                break;
            }

            Room* targetRoom = rooms[roomChoice - 1];

            if (targetRoom->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] No devices in this room!" << endl;
                pressAnyKey();
                break;
            }

            // Select device to schedule
            displayDevicesInRoom(targetRoom);
            setColor(COLOR_YELLOW);
            cout << "\nSelect device number to schedule: ";
            setColor(COLOR_WHITE);
            int deviceChoice;
            cin >> deviceChoice;

            if (deviceChoice < 1 || deviceChoice > targetRoom->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Invalid device number!" << endl;
                pressAnyKey();
                break;
            }

            SmartDevice* device = targetRoom->getDevices()[deviceChoice - 1];

            // Get schedule time (24-hour format)
            setColor(COLOR_YELLOW);
            cout << "\nSchedule time (24h format):" << endl;
            cout << "Hour (0-23): ";
            setColor(COLOR_WHITE);
            int hour;
            cin >> hour;

            if (hour < 0 || hour > 23) {
                setColor(COLOR_RED);
                cout << "\n[ERROR] Hour must be 0-23!" << endl;
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
                pressAnyKey();
                break;
            }

            // Choose what to do at that time
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
            pressAnyKey();
        }

        // OPTION 9: Exit the program
        else if (choice == 9) {
            clearScreen();
            setColor(COLOR_GREEN);
            cout << "======================================" << endl;
            cout << "    Thank you for using Smart Home!" << endl;
            cout << "            Goodbye!" << endl;
            cout << "======================================" << endl;
            setColor(COLOR_WHITE);
        }

        // Invalid menu choice
        else {
            setColor(COLOR_RED);
            cout << "\n[ERROR] Invalid choice! Please select 1-9." << endl;
            setColor(COLOR_WHITE);
            pressAnyKey();
        }

    } while (choice != 9); // Keep running until user chooses Exit

    // === CLEANUP ===
    // Free memory to prevent memory leaks
    for (auto room : rooms) {
        delete room;
    }

    return 0;
}
