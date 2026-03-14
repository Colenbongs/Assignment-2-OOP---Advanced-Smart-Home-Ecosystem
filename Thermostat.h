#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Thermostat Class
	class Thermostat : public SmartDevice {
	private:
        int temperature;


	public:
		Thermostat(string n) : SmartDevice(n, "Thermostat"){
			temperature = 22.0;
		}

		
		void setTemp(int temp) {
			temperature = temp;
			cout << name << "temperature set to" << temperature << endl;
		}

        void showStatus() {
            SmartDevice::showStatus();
            cout << ", Temperature: " << temperature << "°C" << endl;
        }

        //
        void adjust(int value) {
            if (value < 10 || value > 35) {
                cout << "\x1B[31m[WARNING] Temperature must be 10-35°C!\x1B[0m" << endl;
                return;
            }
            temperature = value;
            cout << "Temperature set to " << temperature << "°C" << endl;
        }
    };
