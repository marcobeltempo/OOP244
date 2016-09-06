// OOP244-Seneca Course Management App- MS1
// File GenEdCourse.h
// Version 1.0
// Date 07/26/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 
//////////////////////// ///////////////////////////////////


#include "general.h"
#include "Course.h"

#ifndef _GEN_ED_COURSE_H_
#define _GEN_ED_COURSE_H_

namespace sict {

    class GenEdCourse : public Course {

    private:

        int langLevel_;
       

    public:
        GenEdCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, int language_level);
        GenEdCourse() { langLevel_ = 0; };
        int getLangLevel() const;
        void setLangLevel(int value);
        void display(std::ostream& os) const;

    };
   std::ostream& operator << (std::ostream& os, const GenEdCourse& GenEd);


}
#endif