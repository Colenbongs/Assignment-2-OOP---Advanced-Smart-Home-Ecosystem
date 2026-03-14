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

    string getStatus() {
        string status = SmartDevice::getStatus();
        status += ", Volume: " + to_string(volume) + "%";
        return status;
    }

    void showStatus() {
        cout << getStatus() << endl;
    }

    void adjust(int value) {
        if (value < 0 || value > 100) {
            cout << "Volume must be 0-100" << endl;
            return;
        }
        volume = value;
        cout << "Volume now " << volume << "%" << endl;
    }
};

#endif
