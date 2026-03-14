#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"

class Light : public SmartDevice {
private:
    int brightness;

public:
    Light(string n) : SmartDevice(n, "LIGHT") {
        brightness = 0;
    }

    void turnOn() {
        SmartDevice::turnOn();
        brightness = 100;
        cout << "   Brightness: " << brightness << "%" << endl;
    }

    void turnOff() {
        SmartDevice::turnOff();
        brightness = 0;
    }

    string getStatus() {
        string status = SmartDevice::getStatus();
        status += ", Brightness: " + to_string(brightness) + "%";
        return status;
    }

    void showStatus() {
        cout << getStatus() << endl;
    }

    void adjust(int value) {
        if (value < 0 || value > 100) {
            cout << "Brightness must be 0-100" << endl;
            return;
        }
        brightness = value;
        cout << "Brightness now " << brightness << "%" << endl;
    }
};

#endif
