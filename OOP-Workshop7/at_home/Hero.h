// OOP244 Workshop 8: Derived Classes
// File	Hero.h
// Version 1.0
// Date	7/14/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/14/16 Implemented header file
//////////////////////// ///////////////////////////////////

#include <iostream>

#ifndef SICT_HERO_H
#define SICT_HERO_H

namespace sict {

    class Hero{

    protected:

        char _name[20];
        double _strength;

    public:

        Hero(const char* name, double strength);
        Hero();
        double getStrength() const;
        void display(std::ostream& os) const;
        void operator-=(double strength);
        void operator+=(double strength);
        bool isEmpty() const;
      
    };

    bool operator<(const Hero &, const Hero &);
}
#endif