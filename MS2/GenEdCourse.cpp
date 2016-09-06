// OOP244-Seneca Course Management App- MS2
// File GenEdCourse.cpp
// Version 1.0
// Date 07/27/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/27/2016 Defined member functions
// M.Beltempo 07/28/2016 Replaced single arg. constructor with 5 arg.
//////////////////////// ///////////////////////////////////

#include <iostream>
#include <iomanip>

#include "GenEdCourse.h"
#include "general.h"
using namespace std;

namespace sict {

 
    GenEdCourse::GenEdCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, int language_level) : Course
    (courseCode, courseTitle, credits, studyLoad) {

        setLangLevel(language_level);
    }

    int GenEdCourse::getLangLevel() const {

        return langLevel_;
    }
    void GenEdCourse::setLangLevel(int value) {

        langLevel_ = value;
    }

    std::ostream& operator<<(std::ostream& os, const GenEdCourse& GenEd) {

        GenEd.display(os);

        return os;
    }

    void GenEdCourse::display(std::ostream& os) const{
        
        Course::display(os);

        os  << setw(9) << "|" << setw(11) << right << langLevel_ << "|" << endl;
    }

}