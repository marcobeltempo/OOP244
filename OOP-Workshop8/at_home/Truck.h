// OOP244 Workshop 8: Virtual Functions
// File	Truck.h
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

#include <iostream>
#include "Vehicle.h"

#ifndef _TRUCK_H_
#define _TRUCK_H_

namespace sict {

    class Truck : public Vehicle {

    private:

        bool tow;
       
    public:

        Truck();
        Truck(double bus_speed, bool towingCapacity = false);
        void accelerate();
        void brake();
        void display(std::ostream&) const;
        void Truck::set(std::istream& is);
    };
}

#endif
