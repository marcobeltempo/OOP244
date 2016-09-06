// OOP244 Workshop 8: Virtual Functions
// File	vehicle.h
// Version .0
// Date	7/27/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


#include <iostream>

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

namespace sict {

    class Vehicle {

    private:

        double speed;
  
    public:

        Vehicle();
        Vehicle(double);
        double getSpeed() const;
        void setSpeed(double newSpeed);
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void display(std::ostream&) const = 0;
        virtual void set(std::istream&) = 0;
    };

    void move(Vehicle& moveVehicle);
    void show(const Vehicle& showVehicle);

    
    std::istream& operator >> (std::istream&, Vehicle&); 
    std::ostream& operator<<(std::ostream&, Vehicle&); 
}
#endif