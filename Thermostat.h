#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature; // in celsius

public:
    Thermostat(string n) : SmartDevice(n, "THERMOSTAT") {
        temperature = 22; // room temperature default
    }

    void turnOn() {
        SmartDevice::turnOn();
        cout << "   Current temp: " << temperature << "°C" << endl;
    }

    string getStatus() override {
        string status = SmartDevice::getStatus();
        status += ", Temperature: " + to_string(temperature) + "°C";
        return status;
    }

    void showStatus() {
        cout << getStatus() << endl;
    }

    void adjust(int value) {
        if (value < 10 || value > 35) {
            cout << "[WARNING] Temperature must be 10-35°C!" << endl;
            return;
        }
        temperature = value;
        cout << "Temperature set to " << temperature << "°C" << endl;
    }
};

#endif
