// OOP244 Workshop 8: Derived Classes
// File	Hero.cpp
// Version 1.1
// Date	7/14/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/14/16 Implemented member functions + helper function
// M.Beltempo 07 / 15 / 16 fixed the isValid() function to check for nullptr
//////////////////////// ///////////////////////////////////

#include <iostream>
#include <string>
#include "Hero.h"

using namespace std;

namespace sict {

    Hero::Hero(const char* name, double strength) {

        strncpy(_name, name, 20);
        _strength = strength;
       // _name[21] = '\0';
    }

    Hero::Hero() {

        _name[0] = '\0';
        _strength = -1;
    }

    bool Hero::isEmpty() const {

        return _name != nullptr && _name[0] == '\0';
    
    }
    double Hero::getStrength() const {

        if (_strength) {

            return _strength;
        }
        else {

            return 0.00;
        }
    }

    void Hero::display(std::ostream& os) const {

        if (!isEmpty()) {
           os << _name << " - " << _strength << endl;

        }
        else {
            // do nothing
        }
    }
    bool operator<(const Hero& A, const Hero& B) {

        return A.getStrength() < B.getStrength();
    }

    void Hero::operator-=(double strength) {

        if (strength > _strength) {

            _strength = 0.00;

        }else{

            _strength = _strength - strength;
        }
    }

    void Hero::operator+=(double strength) {

        _strength = _strength + strength;
    }

}