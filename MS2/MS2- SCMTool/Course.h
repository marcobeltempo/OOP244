// OOP244-Seneca Course Management App- MS2
// File Course.h
// Version 2.0
// Date 07/19/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/19/16 Declared the Course class
// M.Beltempo 07/28/16 Made display() virtual to allow redefinition of << from derived classes
// M.Beltempo 07/29/16 Added tester friend class
//////////////////////// ///////////////////////////////////

#include "general.h"

#ifndef _COURSE_H_
#define _COURSE_H_

namespace sict{

    class Course {

	//Tester
        friend class CourseTester; //for submision testing
		
    private:

        char courseCode_[MAX_COURSECODE_LEN + 1]; 
        char* courseTitle_;
        int credits_;
        int studyLoad_;

    public:

        virtual void display(std::ostream& os) const;

        //Constructors
        Course();
        Course(const char* courseCode, const char* courseTitle, int credits, int studyLoad);
        Course(const Course&);
        Course& operator = (const Course& other);

        //Destructor
        ~Course();

        //Setters
        void setCourseCode(const char* );
        void setCourseTitle(const char*);
        void setCredits(int);
        void setStudyLoad(int);

        //Getters
        const char* getCourseCode() const;
        const char* getCourseTitle() const;
        int getCredits();
        int getStudyLoad();
        bool isEmpty();

        //Overloaded operators 
        bool operator == (const char*);
        int operator += (int newStudyLoad);
       
        
    };
   std::ostream& operator<<(std::ostream& os, const Course& course);
   
}
#endif
