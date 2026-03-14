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
        // clean up devices when room is deleted
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
                    device->adjust(20); // dim lights
                }
                else if (device->getType() == "SPEAKER") {
                    device->adjust(10); // low volume
                }
                else if (device->getType() == "CAMERA") {
                    device->turnOn(); // security on at night
                }
            }
        }
        else if (sceneName == "Away") {
            for (auto device : devices) {
                if (device->getType() != "CAMERA") {
                    device->turnOff(); // turn off everything except cameras
                }
                else {
                    device->turnOn(); // cameras stay on for security
                }
            }
        }
        else if (sceneName == "Movie Time") {
            for (auto device : devices) {
                if (device->getType() == "LIGHT") {
                    device->adjust(30); // dim lights
                }
                else if (device->getType() == "SPEAKER") {
                    device->turnOn();
                    device->adjust(60); // medium volume
                }
                else if (device->getType() == "THERMOSTAT") {
                    device->turnOn();
                    device->adjust(23); // comfortable temp
                }
            }
        }
        cout << "Scene applied!" << endl;
    }

    void scheduleAction(string deviceName, string action, int hour, int minute) {
        cout << "\n[SCHEDULED] " << deviceName << " will turn " << action
            << " at " << hour << ":" << (minute < 10 ? "0" : "") << minute << endl;
    }

    string getName() { return roomName; }
    vector<SmartDevice*>& getDevices() { return devices; }
};

#endif
