#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

#include "SmartDevice.h"
#include "Light.h"
#include "Thermostat.h"
#include "Speaker.h"
#include "Camera.h"
#include "Room.h"
#include "SmartHome.h"

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

const int COLOR_GREEN = 10;
const int COLOR_YELLOW = 14;
const int COLOR_RED = 12;
const int COLOR_WHITE = 7;
const int COLOR_CYAN = 11;

void clearScreen() {
    system("cls");
}

void pressAnyKey() {
    setColor(COLOR_YELLOW);
    cout << "\nPress any key to continue...";
    setColor(COLOR_WHITE);
    _getch();
}

int main() {
    SmartHome myHome("My Smart Home");
    vector<Room*> rooms;
    int choice;

    do {
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
        cin >> choice;

        if (choice == 1) {
            clearScreen();
            setColor(COLOR_GREEN);
            cout << "\n=== ALL DEVICES ===" << endl;
            setColor(COLOR_WHITE);
            
            if (rooms.empty()) {
                cout << "No rooms yet." << endl;
            } else {
                for (auto room : rooms) {
                    room->showDevices();
                }
            }
            pressAnyKey();
        }

        else if (choice == 2) {
            clearScreen();
            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\nNo rooms!" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                continue;
            }

            cout << "\nRooms:" << endl;
            for (int i = 0; i < rooms.size(); i++) {
                cout << " " << (i+1) << ". " << rooms[i]->getName() << endl;
            }

            cout << "\nPick room: ";
            int r;
            cin >> r;
            r--;

            if (r < 0 || r >= rooms.size()) {
                setColor(COLOR_RED);
                cout << "Bad room number" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                continue;
            }

            Room* room = rooms[r];
            
            if (room->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "No devices in this room" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                continue;
            }

            cout << "\nDevices:" << endl;
            for (int i = 0; i < room->getDevices().size(); i++) {
                cout << " " << (i+1) << ". ";
                room->getDevices()[i]->showStatus();
            }

            cout << "\nPick device: ";
            int d;
            cin >> d;
            d--;

            if (d < 0 || d >= room->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "Bad device number" << endl;
                setColor(COLOR_WHITE);
                pressAnyKey();
                continue;
            }

            SmartDevice* dev = room->getDevices()[d];

            cout << "\n1. ON  2. OFF" << endl;
            cout << "Choice: ";
            int onoff;
            cin >> onoff;

            if (onoff == 1) {
                dev->turnOn();
            } else if (onoff == 2) {
                dev->turnOff();
            } else {
                setColor(COLOR_RED);
                cout << "Bad choice" << endl;
            }
            
            pressAnyKey();
        }

        else if (choice == 3) {
            clearScreen();
            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\nNo rooms!" << endl;
                pressAnyKey();
                continue;
            }

            cout << "\nRooms:" << endl;
            for (int i = 0; i < rooms.size(); i++) {
                cout << " " << (i+1) << ". " << rooms[i]->getName() << endl;
            }

            cout << "\nPick room: ";
            int r;
            cin >> r;
            r--;

            if (r < 0 || r >= rooms.size()) {
                setColor(COLOR_RED);
                cout << "Bad room" << endl;
                pressAnyKey();
                continue;
            }

            Room* room = rooms[r];
            
            if (room->getDevices().empty()) {
                setColor(COLOR_RED);
                cout << "No devices" << endl;
                pressAnyKey();
                continue;
            }

            cout << "\nDevices:" << endl;
            for (int i = 0; i < room->getDevices().size(); i++) {
                cout << " " << (i+1) << ". ";
                room->getDevices()[i]->showStatus();
            }

            cout << "\nPick device: ";
            int d;
            cin >> d;
            d--;

            if (d < 0 || d >= room->getDevices().size()) {
                setColor(COLOR_RED);
                cout << "Bad device" << endl;
                pressAnyKey();
                continue;
            }

            SmartDevice* dev = room->getDevices()[d];

            if (dev->getType() == "CAMERA") {
                setColor(COLOR_RED);
                cout << "\nCameras cant be adjusted" << endl;
                pressAnyKey();
                continue;
            }

            cout << "\nEnter value: ";
            int val;
            cin >> val;
            dev->adjust(val);
            
            pressAnyKey();
        }

        else if (choice == 4) {
            clearScreen();
            if (rooms.empty()) {
                setColor(COLOR_RED);
                cout << "\nAdd a room first!" << endl;
                pressAnyKey();
                continue;
            }

            cout << "\nRooms:" << endl;
            for (int i = 0; i < rooms.size(); i++) {
                cout << " " << (i+1) << ". " << rooms[i]->getName() << endl;
            }

            cout << "\nPick room: ";
            int r;
            cin >> r;
            r--;

            if (r < 0 || r >= rooms.size()) {
                setColor(COLOR_RED);
                cout << "Bad room" << endl;
                pressAnyKey();
                continue;
            }

            cout << "\nDevice types:" << endl;
            cout << "1. Light" << endl;
            cout << "2. Thermostat" << endl;
            cout << "3. Speaker" << endl;
            cout << "4. Camera" << endl;
            cout << "Pick type: ";
            
            int t;
            cin >> t;
            cin.ignore();

            if (t < 1 || t > 4) {
                setColor(COLOR_RED);
                cout << "Bad type" << endl;
                pressAnyKey();
                continue;
            }

            cout << "Name: ";
            string name;
            getline(cin, name);

            Room* room = rooms[r];
            
            if (t == 1) room->addDevice(new Light(name));
            else if (t == 2) room->addDevice(new Thermostat(name));
            else if (t == 3) room->addDevice(new Speaker(name));
            else room->addDevice(new Camera(name));

            setColor(COLOR_GREEN);
            cout << "\nDevice added" << endl;
            pressAnyKey();
        }

        else if (choice == 5) {
            clearScreen();
            cout << "\nRoom name: ";
            string name;
            cin.ignore();
            getline(cin, name);

            Room* r = new Room(name);
            rooms.push_back(r);
            myHome.addRoom(r);

            setColor(COLOR_GREEN);
            cout << "\nRoom added" << endl;
            pressAnyKey();
        }

    } while (choice != 6);

    clearScreen();
    setColor(COLOR_GREEN);
    cout << "==========================" << endl;
    cout << "        GOODBYE" << endl;
    cout << "==========================" << endl;
    setColor(COLOR_WHITE);

    rooms.clear();
    return 0;
}
