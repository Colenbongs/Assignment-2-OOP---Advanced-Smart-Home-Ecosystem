#ifndef SPEAKER_H
#define SPEAKER_H

#include "SmartDevice.h"

class Speaker : public SmartDevice {
private:
    int volumeLevel;

public:

    Speaker(string deviceName) : SmartDevice(deviceName, "SPEAKER") {
        volumeLevel = 50;   /*default volume*/
    }

    // Turn speaker on
    void turnOn() override {
        SmartDevice::turnOn();
        cout << "Speaker volume currently at " << volumeLevel << "%" << endl;
    }

    // status
    void showStatus() override {
        SmartDevice::showStatus();
        cout << " | Speaker volume: " << volumeLevel << "%" << endl;
    }

    // Adjust volume
    void adjust(int newVolume) override {

        if (newVolume < 0 || newVolume > 100) {
            cout << "[ERROR] Volume must be between 0 and 100." << endl;
            return;
        }

        volumeLevel = newVolume;

        cout << name << " volume updated to "
             << volumeLevel << "%" << endl;
    }
};

#endif
