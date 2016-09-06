// OOP244 Workshop 8: Virtual Functions
// File	main.cpp
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
// 
///////////////////////////////////////////////////////////



#include <iostream>
#include "Bus.h"
#include "Truck.h"

using namespace sict;

int main()
{
    Bus cityBus;
    Truck pickUp;
    std::cin >> cityBus >> pickUp;
    std::cout << cityBus << pickUp;

    return 0;
}
