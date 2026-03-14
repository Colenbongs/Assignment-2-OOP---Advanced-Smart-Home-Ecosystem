#ifndef CAMERA_H
#define CAMERA_H

#include "SmartDevice.h"

class Camera : public SmartDevice {
private:
    bool recording;

public:
    // Constructor initializes name via base class and sets recording to false
    Camera(string name) : SmartDevice(name), recording(false) {}

    // Required by assignment: Toggle recording status [cite: 33, 68]
    void startRecord() {
        if (isOn) {
            recording = true;
            cout << "Camera [" << name << "] started recording." << endl;
        } else {
            cout << "Error: Cannot record. Camera [" << name << "] is OFF." << endl;
        }
    }

    void stopRecord() {
        recording = false;
        cout << "Camera [" << name << "] stopped recording." << endl;
    }

    string getStatus() override {
        string powerStatus = isOn ? "ON" : "OFF";
        string recordStatus = recording ? "RECORDING" : "IDLE";
        return "Power: " + powerStatus + " | Status: " + recordStatus;
    }

    // Helper for your main.cpp to identify device type
    string getType() override {
        return "CAMERA";
    }

    // Override turnOff to ensure recording stops when power is cut
    void turnOff() override {
        SmartDevice::turnOff();
        recording = false;
    }

    // Assignment specifies cameras cannot be "adjusted" 
    void adjust(int value) override {
        cout << "[REJECTED] Security Cameras cannot be adjusted via value." << endl;
    }
};

#endif
