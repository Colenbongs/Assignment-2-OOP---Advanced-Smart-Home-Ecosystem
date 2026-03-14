#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature;

public:
    Thermostat(string n) : SmartDevice(n, "THERMOSTAT") {
        temperature = 22;
    }

    string getStatus() {
        string status = SmartDevice::getStatus();
        status += ", Temp: " + to_string(temperature) + "C";
        return status;
    }

    void showStatus() {
        cout << getStatus() << endl;
    }

    void adjust(int value) {
        if (value < 10 || value > 35) {
            cout << "Temp must be 10-35C" << endl;
            return;
        }
        temperature = value;
        cout << "Temp now " << temperature << "C" << endl;
    }
};

#endif
