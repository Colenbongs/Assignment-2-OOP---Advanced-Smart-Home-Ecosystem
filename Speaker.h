#ifndef SPEAKER_H
#define SPEAKER_H

#include "SmartDevice.h"

class Speaker : public SmartDevice {
private:
    int volume; // 0 to 100

public:
    Speaker(string n) : SmartDevice(n, "SPEAKER") {
        volume = 50; // medium volume default
    }

    void turnOn() {
        SmartDevice::turnOn();
        cout << "   Volume: " << volume << "%" << endl;
    }

    string getStatus() override {
        string status = SmartDevice::getStatus();
        status += ", Volume: " + to_string(volume) + "%";
        return status;
    }

    void showStatus() {
        cout << getStatus() << endl;
    }

    void adjust(int value) {
        if (value < 0 || value > 100) {
            cout << "[WARNING] Volume must be 0-100!" << endl;
            return;
        }
        volume = value;
        cout << "Volume set to " << volume << "%" << endl;
    }
};

#endif
