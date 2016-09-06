// OOP244-Seneca Course Management App- MS1
// File ScmApp.h
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
// M.Beltempo 07/19/16 Declared the ScmAPP class
//////////////////////// ///////////////////////////////////

#include <iostream>

#include "Course.h"

#include "general.h"

#ifndef _SCMAPP_H_
#define _SCMAPP_H_

namespace sict {

    class ScmApp {

    private:

        Course* courseList_[MAX_NO_RECS];
        int noOfCourses;
        int menu();
        int searchACourse(const char* courseCode)const;
        void pause() const;
        void listCourses()const;
        void changeStudyLoad(const char* courseCode);
        void addACourse(int);

    public:

        ScmApp();
        ScmApp(const ScmApp& copy);
        ScmApp& operator = (const ScmApp& other);
        int run();

    };
}

#endif