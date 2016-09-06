/* OOP244-Seneca Course Management App- MS4

File ScmApp.cpp
Version 1.5
Date 7/19/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095

Revision History
__________________________________________________________________________________________
| Name      | Date  | Reason                                                               |
|------------------------------------------------------------------------------------------|
| M.Beltempo 7/19/16  Defined class functions                                              |
| M.Beltempo 7/21/16  Manualy recreated the display chart                                  |
| M.Beltempo 7/22/16  In addCourse() I used cin.getline for coruseTitle. cin >> casued     |
|                     infinite loop when whitespace was detected.                          |
| M.Beltempo 7/23/16  Used the display function from Course.cpp                            |
| M.Beltempo 7/29/16  Added input validation for menu(), addCourse() (selection only),     |
|                     changeStudyLoad().                                                   |
|                     In addCourse() replaced temp title to string conversion.             |
| M.Beltempo 8/09/16  Added option 5 and 6 to the menu                                     |
|                     Defined store() and loadRec() function                               |
| M.Beltempo 8/11/16  Modified the load function logic                                     |
|                     File was deleting on exit                                            |
|                     Only 1 line would load.                                              |
| M.Beltempo 8/12/16  Added display output for course detail lookup                        |
| M.Beltempo 8/17/16  Created an option 7 that remoes a course                             |
|__________________________________________________________________________________________|

*/

#include <iomanip>
#include <string.h>

#include "ScmApp.h"
#include "Course.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"

using namespace std;

namespace sict {


    ScmApp::ScmApp(const char* filename) {

        noOfCourses_ = 0;
        strncpy(filename_, filename, 256);

        for (int i = 0; i < MAX_NO_RECS; i++) {

            courseList_[i] = nullptr;
        }
    }

    ScmApp::~ScmApp() {

        for (int i = 0; i < MAX_NO_RECS; i++) {

            courseList_[i] = nullptr;
        }
    }

    ScmApp::ScmApp(const ScmApp& copy) {

        if (this != &copy) {
            if (copy.courseList_ != nullptr) {

                for (int i = 0; i < copy.noOfCourses_; i++) {

                    courseList_[i] = copy.courseList_[i];
                }
            }
            else {

                for (int i = 0; i < MAX_NO_RECS; i++) {

                    courseList_[i] = nullptr;
                }
            }
        }
    }
    ScmApp&  ScmApp::operator = (const ScmApp& other) {

        if (this == &other) {

            return *this;
        }
        else {

            courseList_[other.noOfCourses_] = new Course[other.noOfCourses_];

            for (int i = 0; i < other.noOfCourses_; i++) {

                courseList_[i] = other.courseList_[i];
            }

            return *this;
        }
    }



    void ScmApp::pause() const {

        cinClear();
        cout << "Press Enter to continue...                                                                         |";
        cin.get();
    }

    //Display the main system menu
    int ScmApp::menu() {

        int validSelection = -99;

        cout << "Seneca Course Management Tool" << endl
            << "1- List courses." << endl
            << "2- Display the details of a course." << endl
            << "3- Add a course." << endl
            << "4- Change the study load of a course." << endl
            << "5- Load courses from a file." << endl
            << "6- Save courses to a file." << endl
            << "7- Remove a course." << endl
            << "0- Exit program" << endl
            << ">";

        cin >> validSelection;

        if (cin.fail() || validSelection > 7) {

            validSelection = -1;
        }

        return validSelection;
    }

    void ScmApp::listCourses()const {

        cout << endl << endl;
        cout << " Row | Code |               Course Title              | Credits | Study Load | System | Lang. Req. |" << endl;
        cout << "-----|------|-----------------------------------------|---------|------------|--------|------------|" << endl;

        for (int i = 0; i < noOfCourses_; i++) {

            cout << right << setw(5) << i << "|";
            cout << *courseList_[i];

            if (i == 10) {

                pause(); //pause when list of courses is 10 or greater
            }
        }

        cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
    }

    int ScmApp::searchACourse(const char* courseCode)const {

        bool match = false;
        int i;
        for (i = 0; i < noOfCourses_; i++) {

            if (*courseList_[i] == courseCode) {

                match = true;
                break;
            }
        }
        return  match ? i : -1;
    }

    void ScmApp::addACourse(int courseType) {

        if (courseType == 1) {

            ICTCourse* addICT = new ICTCourse;
            addICT->read(cin);
            courseList_[noOfCourses_] = addICT;
        }
        else if (courseType == 2) {

            GenEdCourse* addGenEd = new GenEdCourse;
            addGenEd-> read(cin);
            courseList_[noOfCourses_] = addGenEd;
        }

        cout << endl << endl;
        noOfCourses_++;
    }

    void ScmApp::changeStudyLoad(const char* courseCode) {

        int search = searchACourse(courseCode);
        int addStudyLoad;
        bool validStudyLoad = false;

        if (search >= 0 && *courseList_[search] == courseCode) {
            do {
/*
                cout << "1- Change course code." << endl
                    << "2- Change course load." << endl
                    << "3- Change credits." << endl;
                    */
                cout << "Please enter the amount of the study load: ";
                cin >> addStudyLoad;

                if (cin.good()) {
                    validStudyLoad = true;
                    *courseList_[search] += addStudyLoad;
                }
                else {

                    cinClear();
                    cout << endl << "===Invalid Study Load, try again.===" << endl << endl;  
                }
            } while (!validStudyLoad);
        }
        else {

            cout << "Not found!" << endl;
        }
    }

    void ScmApp::loadRecs() {

        int i = 0;
        char objectType;

        dataFile_.open(filename_, ios::in);

        if (!dataFile_.is_open()) {

            dataFile_.clear();
            dataFile_.close();
            dataFile_.open(filename_, ios::out);
            dataFile_.close();
        }

        else {

            while (!dataFile_.fail()) {

                if (noOfCourses_ > MAX_NO_RECS) {

                    cout << "Error: A max of 2000 records can be loaded at a time" << endl;
                    break;
                }

                if (!courseList_[i]) {

                    courseList_[i] = nullptr;
                }

                dataFile_ >> objectType;

                string str(1, objectType);

                if (str == TYPE_GEN) {

                    GenEdCourse* GenEd = new GenEdCourse;
                    courseList_[i] = GenEd;
                }

                else if (str == TYPE_ICT) {

                    ICTCourse* ICT = new ICTCourse;
                    courseList_[i] = ICT;
                }

                if (str == TYPE_GEN || str == TYPE_ICT) {

                    dataFile_.get(objectType);
                    courseList_[i]->load(dataFile_);
                    i++;
                }
            }
            noOfCourses_ = i;
        }
        dataFile_.close();
    }

    void ScmApp::saveRecs() {

        dataFile_.open(filename_, ios::out);

        for (int i = 0; i < noOfCourses_; i++) {

            courseList_[i]->store(dataFile_);
        }

        dataFile_.close();
    }

    void ScmApp::removeCourse(int i, const char* removeCourse) {

        bool valid = false;
        char confirm;
        char tempCourse[MAX_COURSECODE_LEN + 1];
        strcpy(tempCourse, removeCourse);
   
        do {
            cout << "Are you sure you want to remove " << tempCourse << " (Y|N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y') {

                for (i; i < noOfCourses_; ++i) {

                    courseList_[i] = courseList_[i + 1];

                }

                cout << endl << endl << tempCourse << " course successfully removed" << endl << endl;
                noOfCourses_ = noOfCourses_ - 1;
                courseList_[i] = nullptr;
                valid = true;

            }
            else if (confirm == 'N' || confirm == 'n') {

                cout << endl << endl << tempCourse << " course was NOT removed" << endl << endl;
                valid = true;
            }
            else {

                cinClear();
                cout << endl << "===Invalid Selection, try again.=== " << endl << endl;
            }
        } while (!valid);
    }

    int ScmApp::run() {

        bool exit = false;
        char courseCode[MAX_COURSECODE_LEN + 1];

        do {

            int selection = menu();

            if (selection == 1) {

                //display the course list
                listCourses();
            }
            else if (selection == 2) {

                //prompts user for course code lookup
                cout << endl << "Please enter the course code : ";
                cin >> courseCode;

                int i = searchACourse(courseCode);

                if (i >= 0) {

                    cout << endl << endl;
                    cout << " Row | Code |               Course Title              | Credits | Study Load | System | Lang. Req. |" << endl;
                    cout << "-----|------|-----------------------------------------|---------|------------|--------|------------|" << endl;
                    cout << right << setw(5) << i << "|" << *courseList_[i];
                    cout << "----------------------------------------------------------------------------------------------------" << endl << endl;
                }
                else {

                    cinClear();
                    cout << endl << "Not Found!" << endl << endl;
                }
            }
            else if (selection == 3) {

                bool validCourseType = false;
               
                do {
                    
                    int courseType = 0;
               
                    cout << "Please enter the course type (1-ICT or 2-GenEd): ";
                    
                    cin >> courseType;
           
                    if (!cin.fail() && courseType == 1 || courseType == 2) {

                        validCourseType = true;
                        addACourse(courseType);
                    }
                    else {
                        
                        cinClear();
                        cout << endl << endl << "===Invalid Selection, try again.=== " << endl << endl << endl;
                    }
                } while (!validCourseType);
            }

            else if (selection == 4) {

                char* courseCode;
                courseCode = new char[MAX_COURSECODE_LEN + 1];

                //prompts user for course code and new study load
                cout << endl << endl << "Please enter the course code : ";
                cin >> strcpy(courseCode, courseCode);

                if (!cin.fail()) {

                    cinClear();
                    cout << endl << "Not Found!" << endl << endl;
                }
                else {
                
                changeStudyLoad(courseCode);
                cout << endl << endl;
              }

            }
            else if (selection == 5) {

                fstream fileName;
                loadRecs();
            }
            else if (selection == 6) {

                saveRecs();
            }
            else if (selection == 7) {

                char* course;
                course = new char[MAX_COURSECODE_LEN + 1];
              
                cout << endl << "Enter a course to remove: ";
                cin >> course;

                int y = 0;
                y = searchACourse(course);

                if (y >= 0) {

                    removeCourse(y, course);
                }
            else {

                cinClear();
                cout << endl << "Course Not Found!" << endl << endl;
            }
               
            }
            else if (selection == 0) {

                //exit
                cout << endl << endl << "Goodbye!!" << endl << endl;
                exit = true;

            }
            else {

                cinClear();
                cout << endl << "===Invalid Selection, try again.===" << endl << endl;                
            }

        } while (!exit);
        return 0;
    }

}