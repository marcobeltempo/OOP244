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
// M.Beltempo 06/06/16 
//////////////////////// ///////////////////////////////////

#ifndef _CONTACT_H_
#define _CONTACT_H_
#include "PhoneNumber.h"

namespace sict {
    class Contact {
        char name_[41];
        PhoneNumber * phoneNumber_;
        int _noPN;
        void setEmpty();

        public:

        void read();
        bool isEmpty() const;
        Contact();
        Contact(const char * name, int number);
        ~Contact();
        void display();
        Contact(Contact& copied_contact);
        Contact& operator =(const Contact& copy);
    };

}
#endif