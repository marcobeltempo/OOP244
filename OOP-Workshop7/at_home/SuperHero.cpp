// OOP244 Workshop 8: Derived Classes
// File	SuperHero.cpp
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
// M.Beltempo 07/14/16 removed setEmpty() function
// M.Beltempo 07/15/16 Fixed strength multiplier in *= operator
//////////////////////// ///////////////////////////////////

#include <iostream>
#include "SuperHero.h"


using namespace std;

namespace sict {


    SuperHero::SuperHero(const char* superHero_name, double superHero_strength, double super_multiplier) :
        Hero(superHero_name, superHero_strength) {

        if (superHero_strength < 0 || super_multiplier < 0) {

            //setEmpty();

            *this = SuperHero();
        }
        else {

            _strength_multi = super_multiplier;

        }
    }

    double SuperHero::getStrength() {

        return Hero::getStrength();
    }


    void SuperHero::operator*=(SuperHero& vs) {

        if (_strength < vs._strength) {

            vs._strength += _strength * _strength_multi;

            _strength = -1;
            _name[0] = '\0';
            //_strength_multi = -1;

        }
        else {

            _strength += vs._strength * _strength_multi;

            vs._strength = -1;
            vs._name[0] = '\0';
            // vs._strength_multi = -1;

        }
    }

    void SuperHero::display(std::ostream& os) const {
        if (!isEmpty()) {

            os << "living superhero! ";
            Hero::display(os);

        }else{

            cout << "deceased superhero!" << endl;
        }
    }

}

