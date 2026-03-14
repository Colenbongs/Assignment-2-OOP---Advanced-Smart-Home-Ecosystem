#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
#include <iostream>
using namespace std;

// base class for all devices
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

    // returns device status as string
    virtual string getStatus() {
        string status = "[" + type + "] " + name + ": ";
        status += (powerStatus ? "ON" : "OFF");
        return status;
    }

    // shows status on screen
    virtual void showStatus() {
        cout << getStatus();
    }

    // most devices override this
    virtual void adjust(int value) {
        cout << "This device cannot be adjusted" << endl;
    }

    string getName() { return name; }
    string getType() { return type; }
    bool isOn() { return powerStatus; }
};

#endif
