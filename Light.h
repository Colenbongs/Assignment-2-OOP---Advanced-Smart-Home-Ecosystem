#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"

class Light : public SmartDevice {
private:
    int brightness; // 0 to 100

public:
    Light(string n) : SmartDevice(n, "LIGHT") {
        brightness = 0;
    }

    void turnOn() {
        SmartDevice::turnOn();
        brightness = 100; // default when turned on
        cout << "   Brightness set to " << brightness << "%" << endl;
    }

    void turnOff() {
        SmartDevice::turnOff();
        brightness = 0;
    }

    string getStatus() override {
        string status = SmartDevice::getStatus();
        status += ", Brightness: " + to_string(brightness) + "%";
        return status;
    }

    void showStatus() {
        cout << getStatus() << endl;
    }

    void adjust(int value) {
        if (value < 0 || value > 100) {
            cout << "[WARNING] Brightness must be 0-100!" << endl;
            return;
        }
        brightness = value;
        cout << "Brightness adjusted to " << brightness << "%" << endl;
    }
};

#endif
