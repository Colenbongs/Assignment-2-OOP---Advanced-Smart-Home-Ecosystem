#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "SmartDevice.h"

class Room {
private:
    string roomName;
    vector<SmartDevice*> devices;

public:
    Room(string name) {
        roomName = name;
    }

    ~Room() {
        for (auto device : devices) {
            delete device;
        }
    }

    void addDevice(SmartDevice* device) {
        devices.push_back(device);
        cout << "Added " << device->getType() << " '"
            << device->getName() << "' to " << roomName << endl;
    }

    SmartDevice* findDevice(string name) {
        for (auto device : devices) {
            if (device->getName() == name) {
                return device;
            }
        }
        return nullptr;
    }

    void showDevices() {
        if (devices.empty()) {
            cout << "   No devices in " << roomName << endl;
            return;
        }
        cout << "\n--- " << roomName << " ---" << endl;
        for (auto device : devices) {
            cout << "   ";
            device->showStatus();
        }
    }

    // NEW FEATURE 1: Apply scene to all devices in room
    void applyScene(string sceneName) {
        cout << "\nApplying '" << sceneName << "' scene to " << roomName << "..." << endl;

        if (sceneName == "Good Morning") {
            for (auto device : devices) {
                if (device->getType() == "LIGHT") {
                    device->turnOn();
                    device->adjust(80);
                }
                else if (device->getType() == "THERMOSTAT") {
                    device->turnOn();
                    device->adjust(22);
                }
                else if (device->getType() == "SPEAKER") {
                    device->turnOn();
                    device->adjust(30);
                }
            }
        }
        else if (sceneName == "Good Night") {
            for (auto device : devices) {
                if (device->getType() == "LIGHT") {
                    device->adjust(20);
                }
                else if (device->getType() == "SPEAKER") {
                    device->adjust(10);
                }
                else if (device->getType() == "CAMERA") {
                    device->turnOn();
                }
            }
        }
        else if (sceneName == "Away") {
            for (auto device : devices) {
                if (device->getType() != "CAMERA") {
                    device->turnOff();
                }
                else {
                    device->turnOn(); // Cameras stay on
                }
            }
        }
        else if (sceneName == "Movie Time") {
            for (auto device : devices) {
                if (device->getType() == "LIGHT") {
                    device->adjust(30);
                }
                else if (device->getType() == "SPEAKER") {
                    device->turnOn();
                    device->adjust(60);
                }
                else if (device->getType() == "THERMOSTAT") {
                    device->turnOn();
                    device->adjust(23);
                }
            }
        }
        cout << "Scene applied!" << endl;
    }

    // NEW FEATURE 2: Schedule device action
    void scheduleAction(string deviceName, string action, int hour, int minute) {
        cout << "\n[SCHEDULED] " << deviceName << " will turn " << action
            << " at " << hour << ":" << (minute < 10 ? "0" : "") << minute << endl;
    }

    string getName() { return roomName; }
    vector<SmartDevice*>& getDevices() { return devices; }
};

#endif