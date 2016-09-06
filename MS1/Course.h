// OOP244-Seneca Course Management App- MS1
// File Course.h
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
// M.Beltempo 07/19/16 Declared the Course class
//////////////////////// ///////////////////////////////////


#include "general.h"

#ifndef _COURSE_H_
#define _COURSE_H_

namespace sict{

    class Course {

    private:

        char courseCode_[MAX_COURSECODE_LEN + 1]; 
        char* courseTitle_;
        int credits_;
        int studyLoad_;

    public:

        //Constructors
        Course();
        Course(const char* courseCode, const char* courseTitle, int credits, int studyLoad);
        Course(const Course&);
        Course& operator = (const Course& other);
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
        virtual void display(std::ostream& os) const;

    };
   std::ostream& operator<<(std::ostream& os, const Course& course);
   
}

#endif
