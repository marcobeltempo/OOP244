// OOP244 Workshop 8: Virtual Functions
// File	vehicle.cpp
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

#include "Vehicle.h"

namespace sict{

Vehicle::Vehicle() {

    speed = 0.0;
}

Vehicle::Vehicle(double newSpeed) {

    if (newSpeed > 0) {

        setSpeed(newSpeed);
    } 
    else {
        speed = 0;
    }
}

double Vehicle::getSpeed() const {

    return speed;
}

void Vehicle::setSpeed(double speed_) {

    if (speed_ > 0) {

        speed = speed_;
    }
    else {

        speed = 0.0;
    }
}

void move(Vehicle& moveVehicle) {

    moveVehicle.accelerate();
    moveVehicle.brake();
}

void show(const Vehicle& showVehicle) {

    showVehicle.display(std::cout);
}

std::istream& operator >> (std::istream& is, Vehicle& V) {

    V.set(is);

    return is;
}
std::ostream& operator<<(std::ostream& os, Vehicle& v) {

   move(v);
   v.display(os);

   return os;
}
}