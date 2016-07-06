// OOP244 Workshop 4 at Home
// File Enrollment.h
// Version 2.0
// Date 06/10/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/10/16 Defined Enrollment Class
// M.Beltempo 06/15/16 enrol & withdraw functions declarations
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
        void withdraw();
        int enrol(const Enrollment* enrollments, int size);
        void set(const char*, const char*, int, int, int, bool = false);
        void display(bool nameOnly = false) const;
        void setEmpty();
        bool isEnrolled() const;
        bool isValid() const;
        bool hasConflict(const Enrollment &other) const;

    };
}
#endif