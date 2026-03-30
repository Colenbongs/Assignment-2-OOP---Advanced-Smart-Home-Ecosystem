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
        cout << "Added " << device->getType() << " to " << roomName << endl;
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

    string getName() { return roomName; }
    vector<SmartDevice*>& getDevices() { return devices; }
};

#endif
