// OOP244 Workshop 4 In Lab
// File Enrollment.h
// Version 1.0
// Date 06/10/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/10/16 Defined Enrollment Class
//////////////////////// ///////////////////////////////////

#ifndef _ENROLLMENT_H_
#define _ENROLLMENT_H_

namespace sict{

    class Enrollment {

    private:
        char name_[31];
        char code_[11];
        int year_;
        int semester_;
        int slot_;
        bool enrolled_;

    public:
        Enrollment();
        ~Enrollment();
        Enrollment(const char* name, const char* code, int year, int semester, int time);
        void set(const char*, const char*, int, int, int, bool = false);
        void display(bool nameOnly = false) const;
        void setEmpty();
        bool isEnrolled() const;
        bool isValid() const;
        bool hasConflict(const Enrollment &other) const;
        
    };
}
#endif