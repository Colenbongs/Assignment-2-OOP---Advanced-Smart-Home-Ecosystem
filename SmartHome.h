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
        for (auto room : rooms) {
            delete room;
        }
    }

    void addRoom(Room* room) {
        rooms.push_back(room);
        cout << "Room '" << room->getName() << "' added" << endl;
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

    string getName() {
        return homeName;
    }
};

#endif
