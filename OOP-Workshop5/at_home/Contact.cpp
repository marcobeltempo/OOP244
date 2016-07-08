// OOP244 Workshop 5 at Home : Classes with resources 
// File Contact.cpp
// Version 1.0
// Date 07/06/16
// Author Marco Beltempo
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/06/16 Implemeted copy constructor
// M.Beltempo 07/06/16 Implemeted assignment oeperator
// M.Beltempo 07/07/16 Called assignment operator in copy constructor for efficency
//////////////////////// ///////////////////////////////////

#include "Contact.h"
#include "PhoneNumber.h"
#include <cstring> 
#include <iostream> 

using namespace std;

namespace sict {

    void Contact::read() {
        cout << "Contact Name: ";
        cin.getline(name_, 41, '\n');
        cout << "Please enter " << _noPN << " phone numbers: " << endl;
        for (int i = 0; i < _noPN; i++) {
            cout << i + 1 << ": ";
            phoneNumber_[i].read();
        }
    }

    bool Contact::isEmpty() const {
        return phoneNumber_ == nullptr;
    }

    void Contact::setEmpty() {
        name_[0] = 0;
        _noPN = 0;
        phoneNumber_ = nullptr;
    }

    Contact::Contact() {

        setEmpty();
    }

    Contact::Contact(const char * name, int number) {

        phoneNumber_ = new PhoneNumber[number];
        name_[41] = '\0';
        strncpy(name_, name, 41);
        _noPN = number;

    }

    Contact::~Contact() {

        delete[] phoneNumber_;

    }

    void Contact::display() {

        cout << name_ << endl;

        for (int i = 0; i < _noPN; i++) {
            phoneNumber_[i].display();
            //cout << setw(67) << setfill ('-');
        }

        // draw a 40 char line using '-' and go to new line

        for (int i = 0; i < 40; i++) {
            cout << "-";
        }
        cout << endl;
    }

    Contact::Contact(Contact& copied_contact) {

        // full copy constructor code
       /*
           if (copied_contact.isEmpty())
           {
               setEmpty();

           }
           else {
               strncpy(name_, copied_contact.name_, 40);
               _noPN = copied_contact._noPN;
               phoneNumber_ = new PhoneNumber[copied_contact._noPN];

               for (int i = 0; i < copied_contact._noPN; i++) {

                   phoneNumber_[i] = copied_contact.phoneNumber_[i];
               }
           } */

           // implemented the overloaded assignment operator for efficeny
        phoneNumber_ = nullptr;
        *this = copied_contact;
    }

    Contact& Contact::operator=(const Contact& copy) {


        if (this == &copy) {

            return *this;
        }
        else

            delete[] phoneNumber_;

        //Copy Constructor Code
        strncpy(name_, copy.name_, 40);
        _noPN = copy._noPN;
        phoneNumber_ = new PhoneNumber[copy._noPN];

        for (int i = 0; i < copy._noPN; i++) {

            phoneNumber_[i] = copy.phoneNumber_[i];
        }
        return *this;

    }

}