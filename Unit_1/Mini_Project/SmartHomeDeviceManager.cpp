#include <iostream>
#include <string>
using namespace std;

class SmartDevice
{
private:
    int deviceID;
    string deviceType;
    string location;
    string status;
    string lastUpdated;

public:
    SmartDevice(int id, string type, string loc, string stat, string time)
    {
        deviceID = id;
        deviceType = type;
        location = loc;
        status = stat;
        lastUpdated = time;
    }

    void switchOn()
    {
        status = "ON";
    }

    void switchOff()
    {
        status = "OFF";
    }

    void updateStatus(string newStatus, string time)
    {
        status = newStatus;
        lastUpdated = time;
    }

    void display()
    {
        cout << "Device ID    : " << deviceID << endl;
        cout << "Device Type  : " << deviceType << endl;
        cout << "Location     : " << location << endl;
        cout << "Status       : " << status << endl;
        cout << "Last Updated : " << lastUpdated << endl;
        cout << "-----------------------------" << endl;
    }
};

int main()
{
    SmartDevice d1(101, "Light", "Living Room", "ON", "10:30 AM");
    SmartDevice d2(102, "Camera", "Main Gate", "ON", "10:35 AM");
    SmartDevice d3(103, "Door Lock", "Front Door", "OFF", "10:40 AM");
    SmartDevice d4(104, "Thermostat", "Bedroom", "ON", "10:45 AM");

    cout << "\n===== SMART HOME DASHBOARD =====\n" << endl;

    d1.display();
    d2.display();
    d3.display();
    d4.display();

    return 0;
}
