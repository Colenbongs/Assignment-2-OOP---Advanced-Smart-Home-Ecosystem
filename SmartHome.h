#ifndef SMARTHOME_H
#define SMARTHOME_H

#include "Room.h"
#include <vector>

class SmartHome {
private:
    vector<Room*> rooms;
    string homeName;

public:
    SmartHome(string name) {
        homeName = name;
    }
    
    ~SmartHome() {
        // clean up all rooms
        for (auto room : rooms) {
            delete room;
        }
    }
    
    void addRoom(Room* room) {
        rooms.push_back(room);
        cout << "Room '" << room->getName() << "' added to " << homeName << endl;
    }
    
    Room* getRoom(int index) {
        if (index >= 0 && index < rooms.size()) {
            return rooms[index];
        }
        return nullptr;
    }
    
    int getRoomCount() {
        return rooms.size();
    }
    
    void showAllRooms() {
        cout << "\n=== " << homeName << " - All Rooms ===" << endl;
        if (rooms.empty()) {
            cout << "   No rooms in this smart home" << endl;
            return;
        }
        for (int i = 0; i < rooms.size(); i++) {
            cout << "   " << (i + 1) << ". " << rooms[i]->getName() << endl;
        }
    }
    
    void showAllDevices() {
        cout << "\n=== " << homeName << " - All Devices ===" << endl;
        if (rooms.empty()) {
            cout << "   No rooms to display" << endl;
            return;
        }
        for (auto room : rooms) {
            room->showDevices();
        }
    }
    
    string getName() {
        return homeName;
    }
};

#endif
