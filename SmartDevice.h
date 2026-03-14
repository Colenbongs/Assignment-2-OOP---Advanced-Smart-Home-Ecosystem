#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
#include <iostream>
using namespace std;

// Base class for all devices
class SmartDevice {
protected:
    string name;
    string type;
    bool powerStatus;

public:
    SmartDevice(string n, string t) {
        name = n;
        type = t;
        powerStatus = false;
    }

    virtual ~SmartDevice() {}

    virtual void turnOn() {
        powerStatus = true;
        cout << "[" << type << "] " << name << " is now ON" << endl;
    }

    virtual void turnOff() {
        powerStatus = false;
        cout << "[" << type << "] " << name << " is now OFF" << endl;
    }

    virtual void showStatus() {
        cout << "[" << type << "] " << name << ": "
            << (powerStatus ? "ON" : "OFF");
    }

    virtual void adjust(int value) {
        cout << "This device cannot be adjusted" << endl;
    }

    string getName() { return name; }
    string getType() { return type; }
    bool isOn() { return powerStatus; }
};

#endif