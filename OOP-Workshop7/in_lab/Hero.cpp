// OOP244 Workshop 8: Derived Classes
// File	Hero.cpp
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
// M.Beltempo 07/14/16 Implemented member functions + helper function
//////////////////////// ///////////////////////////////////

#include <iostream>
#include "Hero.h"

using namespace std;

namespace sict {

    Hero::Hero(char const* name, double strength) {

        strcpy(_name, name);
        _strength = strength;

    }

    Hero::Hero() {

        _name[0] = 0;
        _strength = 0.00;
    }

    bool Hero::isEmpty() const {

        return _name && _name[0] && _strength >= 0.00;

    }
    double Hero::getStrength() const {

        if (_strength) {

            return _strength;
        }
        else {

            return 0.0;
        }
    }
    void Hero::display(std::ostream& os) const {

        if (os) {
            cout << _name << " - " << _strength << endl;

        }
        else {


        }
    }
    bool operator<(const Hero& A, const Hero& B) {


        return A.getStrength() < B.getStrength();



    }
    void Hero::operator-=(double strength) {

        if (strength > _strength) {

            _strength = 0.00;
        }
        else {

            _strength = _strength - strength;
        }
    }
    void Hero::operator+=(double strength) {

        _strength = _strength + strength;

    }

    Hero::~Hero() {


    }
}