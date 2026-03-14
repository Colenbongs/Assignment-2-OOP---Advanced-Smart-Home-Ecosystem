#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
#include <iostream>
using namespace std;

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
        cout << name << " is now ON" << endl;
    }

    virtual void turnOff() {
        powerStatus = false;
        cout << name << " is now OFF" << endl;
    }

    virtual string getStatus() {
        string status = name + ": ";
        if (powerStatus) status += "ON";
        else status += "OFF";
        return status;
    }

    virtual void showStatus() {
        cout << getStatus();
    }

    virtual void adjust(int value) {
        cout << name << " cannot be adjusted" << endl;
    }

    string getName() { return name; }
    string getType() { return type; }
};

#endif
