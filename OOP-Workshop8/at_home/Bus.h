// OOP244 Workshop 8: Virtual Functions
// File	Bus.h
// Version 1.0
// Date	7/27/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo
///////////////////////////////////////////////////////////

#include <iostream>
#include "Vehicle.h"

#ifndef _BUS_H_
#define _BUS_H_

namespace sict {

    class Bus : public Vehicle {

    private:

        int _passengerCapacity;

    public:

        Bus();
        Bus(double bus_speed, int passenger_capacity);
        void accelerate();
        void brake();
        void display(std::ostream&) const;
        void set(std::istream& is);
    };
}
#endif
