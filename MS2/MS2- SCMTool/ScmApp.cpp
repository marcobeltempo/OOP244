// OOP244-Seneca Course Management App- MS2
// File ScmAPP.cpp
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
// M.Beltempo 07/19/16 defined class functions
// M.Beltempo 07/21/16 manuualy recreated the display chart
// M.Beltempo 07/22/16 in addCourse() I used cin.getline for coruseTitle. cin >> casued infinite loop when whitespace was detected
// M.beltempo 07/23/16 Used the display function from Course.cpp
// M.Beltempo 07/29/16 Added input validation for menu(), addCourse() (selection only), changeStudyLoad();
// M.Beltempo 07/29/16 In addCourse() replaced temp title to string conversion
//////////////////////// ///////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string.h>

#include "ScmApp.h"
#include "Course.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"

using namespace std;

namespace sict {

    ScmApp::ScmApp() {

        noOfCourses_ = 0;
    }

    ScmApp::~ScmApp() {

        for (int i = 0; i < MAX_NO_RECS; i++) {

            courseList_[i] = nullptr;
        }
    }

    ScmApp::ScmApp(const ScmApp& copy) {

        if (this != &copy) {
            if (copy.courseList_ != nullptr) {

                courseList_[copy.noOfCourses_] = new Course[copy.noOfCourses_];

                for (int i = 0; i < copy.noOfCourses_; i++) {

                    courseList_[i] = copy.courseList_[i];
                }
            }
            else {

                courseList_[MAX_NO_RECS] = nullptr;
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

        cin.ignore();
        cout << "Press Enter to continue..." << endl;
        cin.clear();
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
            << "0- Exit program" << endl
            << ">";
        
        cin >> validSelection;
        
        if (validSelection == 1) {

            validSelection = 1;
        }
        else if (validSelection == 2) {

            validSelection = 2;
        }
        else if (validSelection == 3) {

            validSelection = 3;
        }
        else if (validSelection == 4) {

            validSelection = 4;
        }
        else if (validSelection == 0) {

            validSelection = 0;
        }
        else  {

            validSelection = -1;
        }

        return validSelection;
    }

    void ScmApp::listCourses()const {

        cout << endl << endl;
        cout << " Row" << " | " << "Code" << " | " << "               Course Title              " << " | " << "Credits" " | " << "Study Load" << " | " << "System" " | " << "Lang.Req." " | " << endl;
        cout << "-----" << "|" << "------" << "|" << "-------------------------------------------" << "|" << "---------" "|" << "------------" << "|" << "--------" "|" << "-----------" "|" << endl;

        for (int i = 0; i < noOfCourses_; i++) {

            cout << right << setw(5) << i << "|";
            cout << *courseList_[i];

            if (i >= 10) {

                pause(); //pause when list of courses is 10 or greater
            }
        }

        cout << "-----------------------------------------------------------------------------------------------------" << endl << endl;
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

    void ScmApp::changeStudyLoad(const char* courseCode) {

        int search = searchACourse(courseCode);
        int addStudyLoad;
        bool validStudyLoad = false;

          if (search >= 0 && *courseList_[search] == courseCode) {
                do {
                    cout << "Please enter the amount of the study load: ";
                    cin >> addStudyLoad;

                    if (cin.good()) {
                        validStudyLoad = true;
                        *courseList_[search] += addStudyLoad;
                    }
                    else {
                        cin.clear();
                        //and empty it
                        cin.ignore();
                        cout << endl << "===Invalid Study Load, try again.===" << endl;
                        cout << endl;
                    }
                } while (!validStudyLoad);
           } 
            else{

               cout << "Not found!" << endl;
           }
    }

    void ScmApp::addACourse(int courseType) {

        ICTCourse* addICTCourse = new ICTCourse;
        GenEdCourse* addGenEdCourse = new GenEdCourse;

        char tempCourseCode[MAX_COURSECODE_LEN + 1];
        char tempCourseICT[MAX_SYSTEM_LEN];
        char* tempCourseTitle;
        string str_title;

        int tempStudyLoad = 0;
        int tempCredits = 0;
        int tempGenEd = 0;

        for (int i = 0; i == 0; i++) {

            cout << endl << endl;
            cout << "Course Code: ";
            cin >> tempCourseCode;
            cin.ignore();

            cout << "Course Title: ";
            getline(cin, str_title);

            tempCourseTitle = new char[str_title.length() + 1]; // use size of string to asign to char array
            strcpy(tempCourseTitle, str_title.c_str());         //convert string to c string

            cout << "Course Credit: ";
            cin >> tempCredits;
            cin.ignore();

            cout << "Study Load: ";
            cin >> tempStudyLoad;

            if (courseType == 1) {

                cout << "Computer system: ";
                cin >> tempCourseICT;

                addICTCourse = new ICTCourse(tempCourseCode, tempCourseTitle, tempCredits, tempStudyLoad, tempCourseICT);

                courseList_[noOfCourses_] = addICTCourse;

            }
            else if (courseType == 2) {

                cout << "Language Requirement: ";
                cin >> tempGenEd;

                addGenEdCourse = new GenEdCourse(tempCourseCode, tempCourseTitle, tempCredits, tempStudyLoad, tempGenEd);
                courseList_[noOfCourses_] = addGenEdCourse;
            }
        }

        cout << endl << endl;
        noOfCourses_++;
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
                    cout << "Please enter the course code : ";
                    cin >> courseCode;

                    searchACourse(courseCode);

                    if (searchACourse(courseCode) < 0) {

                        cout << "Not Found!" << endl;

                    }
                    else {

                        cout << "Found!" << endl;
                    }
                }
                else if (selection == 3) {

                    int courseType = 0;
                    bool validCourseType = false;

                    do {
                        cout << "Please enter the course type (1-ICT or 2-GenEd): ";
                        cin >> courseType;

                        if ((cin.good()) && (courseType == 1 || courseType == 2)) {

                            validCourseType = true;
                            addACourse(courseType);

                        }
                        else {

                            cin.clear();
                            //and empty it
                            cin.ignore();
                            cout << endl << "===Invalid Selection, try again.=== " << endl;
                            cout << endl;

                        }
                    } while (!validCourseType);
                }

                else if (selection == 4) {

                    char* courseCode;
                    courseCode = new char[MAX_COURSECODE_LEN + 1];

                    //prompts user for course code and new study load
                    cout << endl << endl;
                    cout << "Please enter the course code : ";
                    cin >> strcpy(courseCode, courseCode);

                    changeStudyLoad(courseCode);

                    cout << endl << endl;

                }
                else if (selection == 0) {

                    //exit
                    cout << endl << endl << "Goodbye!!" << endl;
                    exit = true;

                }
                else {

                    cout << "===Invalid Selection, try again.===" << endl;
                    pause();        
                }
                
        } while (!exit);
        return 0;
    }
    
}