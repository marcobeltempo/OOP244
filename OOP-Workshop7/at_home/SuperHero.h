// OOP244 Workshop 8: Derived Classes
// File	SuperHero.h
// Version 1.0
// Date	7/14/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/14/16 Implemented header file
//////////////////////// ///////////////////////////////////

#include <iostream>
#include "Hero.h"

#ifndef SUPER_HERO_H
#define SUPER_HERO_H

namespace sict {

    class SuperHero : public Hero {
  

        double _strength_multi;

    public:

        SuperHero() : Hero() {

            _strength_multi = -1;

        }
        SuperHero(const char* superHero_name, double superHero_strength, double super_multiplier);
        double getStrength();
        void operator*=(SuperHero& vs);
        void display(std::ostream& os) const;
       
    };


}
#endif