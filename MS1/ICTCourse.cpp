// OOP244-Seneca Course Management App- MS1
// File Course.cpp
// Version 1.0
// Date 07/19/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/28/2016 Added 5 argument constructor
//////////////////////// ///////////////////////////////////

#include <iostream>
#include <iomanip>

#include "ICTCourse.h"
#include "general.h"
using namespace std;

namespace sict {


   ICTCourse::ICTCourse(const char* courseCode,const char* courseTitle, int credits, int studyLoad, const char* comp_system) : Course
       (courseCode, courseTitle, credits, studyLoad)
   {

       setComputerSystem(comp_system);

    }


    const char* ICTCourse::getComputerSystem() const {

        return computerSystem_;

    }

    void ICTCourse::setComputerSystem(const char* value) {
        if ((value != NULL) && (value[0] == '\0')) {
            ICTCourse();
        }
        else {
        strcpy(computerSystem_, value);
    }
    }

    std::ostream& operator<<(std::ostream& os, const ICTCourse& ICT) {


       ICT.display(os);
        
        return os;
    }

   

    void ICTCourse::display(std::ostream& os) const {
      

        Course::display(os);
        os << setw(8) << left << computerSystem_ << setw(12) << "|"  << "|" <<endl;
       
           
    }



}


