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
        cout << "   Camera recording" << endl;
    }

    void turnOff() {
        SmartDevice::turnOff();
        recording = false;
    }

    string getStatus() {
        string status = SmartDevice::getStatus();
        if (recording) status += ", Recording: YES";
        else status += ", Recording: NO";
        return status;
    }

    void showStatus() {
        cout << getStatus() << endl;
    }
};

#endif
