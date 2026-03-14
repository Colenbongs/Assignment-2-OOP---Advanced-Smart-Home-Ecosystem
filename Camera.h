#ifndef CAMERA_H
#define CAMERA_H

#include "SmartDevice.h"

class Camera : public SmartDevice {
private:
    bool recording;

public:
    Camera(string n) : SmartDevice(n, "CAMERA") {
        recording = false;
    }

    void turnOn() {
        SmartDevice::turnOn();
        recording = true;
        cout << "   Camera is now RECORDING" << endl;
    }

    void turnOff() {
        SmartDevice::turnOff();
        recording = false;
    }

    void showStatus() {
        SmartDevice::showStatus();
        cout << ", Recording: " << (recording ? "YES" : "NO") << endl;
    }

    // Camera doesn't support adjust - will use base class version
};

#endif