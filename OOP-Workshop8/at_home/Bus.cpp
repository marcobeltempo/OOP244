// OOP244 Workshop 8: Virtual Functions
// File	Bus.cpp
// Version 1.0
// Date	7/27/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////

#include "Bus.h"

using namespace std;
namespace sict {

    Bus::Bus(){

        setSpeed(0.0);
    }

    Bus::Bus(double bus_speed, int total_passengers) {

        setSpeed(bus_speed);
        _passengerCapacity = total_passengers;
    }

    void Bus::accelerate() {

        double bus_acl_speed = getSpeed();

        bus_acl_speed = bus_acl_speed +20;
        setSpeed(bus_acl_speed);
    }

    void Bus::brake() {

        double bus_brake_speed = getSpeed();

        bus_brake_speed -= 10;
        setSpeed(bus_brake_speed);
    }

    void Bus::display(std::ostream& os) const {

        double speed = getSpeed();
        os << "This bus has total capacity of " <<
            _passengerCapacity << " passengers and has a speed of " << 
            speed << " after acceleration and braking." << endl;
    }

    void Bus::Bus::set(std::istream& is) {
        double userSpeed;
        
        cout << "Bus => total capacity: ";
        cin >> _passengerCapacity;

        cout << "Bus => speed: ";
        cin >> userSpeed;
        setSpeed(userSpeed);

    }
}