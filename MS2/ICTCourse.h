// OOP244-Seneca Course Management App- MS2
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
// M.Beltempo 07/26/16 Defined ICTCourse class
// M.Beltempo 07/29/16 Added tester friend class
//////////////////////// ///////////////////////////////////

#include <string>

#include "general.h"
#include "Course.h"

#ifndef _ICTCOURSE_H_
#define _ICTCOURSE_H_

namespace sict {

class ICTCourse : public Course {
	
	 //Tester
        friend class  ICTCourseTester; //for submision testing
  
    private:

        char computerSystem_[MAX_SYSTEM_LEN];
       
    public:

        //constructors
        ICTCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, const char* comp_system);
        ICTCourse();

        const char* getComputerSystem() const;
        void setComputerSystem(const char* value);
        void display(std::ostream& os) const;

       
    };
 std::ostream& operator<<(std::ostream& os, const Course& ICT);

}
#endif