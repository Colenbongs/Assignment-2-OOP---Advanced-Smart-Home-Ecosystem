#ifndef SPEAKER_H
#define SPEAKER_H

#include "SmartDevice.h"

class Speaker : public SmartDevice {
private:
    int volume;

public:
    Speaker(string n) : SmartDevice(n, "SPEAKER") {
        volume = 50;
    }

    void turnOn() {
        SmartDevice::turnOn();
        cout << "   Volume: " << volume << "%" << endl;
    }

    void showStatus() {
        SmartDevice::showStatus();
        cout << ", Volume: " << volume << "%" << endl;
    }

    void adjust(int value) {
        if (value < 0 || value > 100) {
            cout << "\x1B[31m[WARNING] Volume must be 0-100!\x1B[0m" << endl;
            return;
        }
        volume = value;
        cout << "Volume set to " << volume << "%" << endl;
    }
};

#endif