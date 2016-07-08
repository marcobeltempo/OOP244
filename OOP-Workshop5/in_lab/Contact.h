// OOP244 Workshop 5 In Lab: Classes with resources 
// File Contact.h
// Version 1.0
// Date 07/03/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
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
        Contact(const Contact& copied_contact);
        Contact& operator =(const Contact& copy);
    };

}
#endif