// OOP244-Seneca Course Management App- MS1
// File ICTCourse.h
// Version 1.0
// Date 07/26/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 
//////////////////////// ///////////////////////////////////

#include <string>;

#include "general.h"
#include "Course.h"


#ifndef _ICTCOURSE_H_
#define _ICTCOURSE_H_

namespace sict {

class ICTCourse : public Course {

    private:

        char computerSystem_[MAX_SYSTEM_LEN];
       
    public:

        ICTCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, const char* comp_system);
        ICTCourse() {
            strcpy(computerSystem_, "matrix");

        };

        const char* getComputerSystem() const;
        void setComputerSystem(const char* value);
        void display(std::ostream& os) const;
    };

 std::ostream& operator<<(std::ostream& os, const Course& ICT);

}
#endif