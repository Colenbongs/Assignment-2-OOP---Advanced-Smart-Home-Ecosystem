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
        cout << "   Brightness set to " << brightness << "%" << endl;
    }

    void turnOff() {
        SmartDevice::turnOff();
        brightness = 0;
    }

    void showStatus() {
        SmartDevice::showStatus();
        cout << ", Brightness: " << brightness << "%" << endl;
    }

    void adjust(int value) {
        if (value < 0 || value > 100) {
            // Red text for warnings in Windows console
            cout << "\x1B[31m[WARNING] Brightness must be 0-100!\x1B[0m" << endl;
            return;
        }
        brightness = value;
        cout << "Brightness adjusted to " << brightness << "%" << endl;
    }
};

#endif