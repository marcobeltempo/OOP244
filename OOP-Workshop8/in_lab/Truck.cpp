// OOP244 Workshop 8: Virtual Functions
// File	Truck.cpp
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

#include "Truck.h"

using namespace std;

namespace sict {

    Truck::Truck() {

        setSpeed(0.0);
        tow = false;
    }

    Truck::Truck(double truck_speed, bool towing_capacity) {

        setSpeed(truck_speed);
        tow = towing_capacity;
    }

    void Truck::accelerate() {

        double truck_acl_speed = getSpeed();

        truck_acl_speed += 50;
        setSpeed(truck_acl_speed);
    }

    void Truck::brake() {
        double truck_brake_speed = getSpeed();
        
        truck_brake_speed -= 20;
        setSpeed(truck_brake_speed);
    }

    void Truck::display(std::ostream& os) const {

        double truckSpeed = getSpeed();

        os << "This truck is going " << truckSpeed << " after acceleration and braking, and";
            
            if (tow) {
                
                cout << " it can be used to tow." << endl; 
            }
            else {

                cout << " it cannot be used to tow." << endl;
            }
    }

    void Truck::Truck::set(std::istream& is) {
        double userSpeed;

        cout << "Truck => speed: ";
        cin >> userSpeed;
        setSpeed(userSpeed);

        cout << "Truck can tow? (true=1 / false=0): ";
        cin >> tow;


    }
}