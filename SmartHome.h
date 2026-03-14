#ifndef SMARTHOME_H
#define SMARTHOME_H

#include <vector>
#include "Room.h"

class SmartHome {
private:
    vector<Room> rooms;

public:

    void addRoom(Room room) {
        rooms.push_back(room);
    }

    void showAllStatus() {

        cout << "\n===== SMART HOME STATUS =====\n";

        for (auto &room : rooms) {
            room.showStatus();
        }
    }
};

#endif