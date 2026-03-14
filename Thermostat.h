#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    Thermostat(string n) : SmartDevice(n, "THERMOSTAT") {
        temperature = 22; // default
    }

    void turnOn() {
        SmartDevice::turnOn();
        cout << "   Current temp: " << temperature << "°C" << endl;
    }

    void showStatus() {
        SmartDevice::showStatus();
        cout << ", Temperature: " << temperature << "°C" << endl;
    }

    void adjust(int value) {
        if (value < 10 || value > 35) {
            cout << "\x1B[31m[WARNING] Temperature must be 10-35°C!\x1B[0m" << endl;
            return;
        }
        temperature = value;
        cout << "Temperature set to " << temperature << "°C" << endl;
    }
};

#endif