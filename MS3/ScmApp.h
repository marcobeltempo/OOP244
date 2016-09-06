/* OOP244-Seneca Course Management App- MS4

 File ScmApp.h
 Version 1.4
 Date 7/19/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca
 
 Revision History
  __________________________________________________________________________________________
 | Name      | Date  | Reason                                                               |
 |------------------------------------------------------------------------------------------|
 | M.Beltempo 7/19/16  Declared the ScmAPP class                                            |        
 | M.Beltempo 7/29/16  Added tester friend class                                            |        
 | M.Beltempo 8/09/16  Added member variables fstream dataFile_ and char filename_[256]     |       
 |__________________________________________________________________________________________|

*/

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
        char  filename_[256];
        std::fstream dataFile_;

        void pause() const;
        void listCourses()const;
        void changeStudyLoad(const char* courseCode);
        void addACourse(int);
        void loadRecs();
        void saveRecs();

    public:

        ScmApp(const char* filename);
        ~ScmApp();
        ScmApp(const ScmApp& copy);
        ScmApp& operator = (const ScmApp& other);
        int run();

    };
}
#endif