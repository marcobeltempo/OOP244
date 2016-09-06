// OOP244-Seneca Course Management App- MS2
// File ScmApp.h
// Version 2.0
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
// M.Beltempo 07/29/16 Added tester friend class
//////////////////////// ///////////////////////////////////

#include <iostream>

#include "Course.h"
#include "general.h"

#ifndef _SCMAPP_H_
#define _SCMAPP_H_

namespace sict {

    class ScmApp {

        //Tester
        friend class ScmAppTester; //for submision testing

    private:

        Course* courseList_[MAX_NO_RECS];
        int noOfCourses_;
        int menu();
        int searchACourse(const char* courseCode)const;
        void pause() const;
        void listCourses()const;
        void changeStudyLoad(const char* courseCode);
        void addACourse(int);

    public:

        ScmApp();
        ~ScmApp();
        ScmApp(const ScmApp& copy);
        ScmApp& operator = (const ScmApp& other);
        int run();


    };
}
#endif