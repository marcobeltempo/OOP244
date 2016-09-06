// OOP244-Seneca Course Management App- MS1
// File ScmAPP.cpp
// Version 1.0
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
//////////////////////// ///////////////////////////////////


#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

#include "ScmApp.h"
#include "Course.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"

using namespace std;

namespace sict {

    ScmApp::ScmApp() {

        courseList_[0] = nullptr;
        noOfCourses = 0;
    }

    ScmApp::ScmApp(const ScmApp& copy) {

        if (this != &copy) {
            if (copy.courseList_ != nullptr) {

                // delete[]  courseList_;
                courseList_[copy.noOfCourses] = new Course[copy.noOfCourses];

                for (int i = 0; i < copy.noOfCourses; i++) {

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

            //            delete[] courseList_;
            courseList_[other.noOfCourses] = new Course[other.noOfCourses];

            for (int i = 0; i < other.noOfCourses; i++) {

                courseList_[i] = other.courseList_[i];
            }
            return *this;
        }
    }

    void ScmApp::pause() const {
        cin.ignore();
        cout << "Press Enter to continue..." << endl;

        cin.get();
        // system("pause");

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

        if (validSelection > -1 || validSelection < 5) {

            // do nothing
        }
        else {

            validSelection = -1;
        }
        return validSelection;
        cin.ignore(); //clear buffer
    }

    void ScmApp::listCourses()const {

        cout << endl << endl;
        cout << " Row" << " | " << "Code" << " | " << "               Course Title              " << " | " << "Credits" " | " << "Study Load" << " | " << "System" " | " << "Lang.Req." " | " << endl;
        cout << "-----" << "|" << "------" << "|" << "-------------------------------------------" << "|" << "---------" "|" << "------------" << "|" << "--------" "|" << "-----------" "|" << endl;
        //   if (!courseList_[0]) {
        for (int i = 0; i < noOfCourses; i++) {

            cout << setfill(' ') << right << setw(5) << (i) << "|";
               cout << *courseList_[i];
          
            if (i >= 10) {
                pause(); //pause when list of courses is 10 or greater

            }
        }
        cout << "-----------------------------------------------------------------------------------------------------" << endl << endl;;

    }

    int ScmApp::searchACourse(const char* courseCode)const {

        int course_index = -1;
        for (int i = 0; i < noOfCourses; i++) {

            if (*courseList_[i] == courseCode) {

                course_index = i;
            }
        }
        return course_index;
    }
    void ScmApp::changeStudyLoad(const char* courseCode) {

        int search = searchACourse(courseCode);
        int addStudyLoad;

        if (search < 0) {
            cout << "Not found!" << endl;

        }

        else {
            for (int i = 0; i < noOfCourses; i++) {
                if (*courseList_[i] == courseCode) {

                    cout << "Please enter the amount of the study load: ";
                    cin.ignore();
                    cin >> addStudyLoad;

                    *courseList_[i] += addStudyLoad;
                }
            }
        }
    }

    void ScmApp::addACourse(int courseType) {

        //Course* addCourse = new Course;
        ICTCourse* addICTCourse = new ICTCourse;
        GenEdCourse* addGenEdCourse = new GenEdCourse;
        char tempCourseCode[MAX_COURSECODE_LEN + 1];
        char* tempCourseTitle = new char;
        char tempCourseICT[MAX_SYSTEM_LEN ];

        int tempStudyLoad = 0;
        int tempCredits = 0;
        int tempGenEd = 0;

       // do {
           
                for (int i = 0; i == 0; i++) {

                    cout << endl << endl;
                    cout << "Course Code: ";
                    cin >> tempCourseCode;
                    // cin.getline(tempCourseCode, MAX_COURSECODE_LEN + 1);
                    cin.ignore();

                    cout << "Course Title: ";
                    cin.getline(tempCourseTitle, MAX_LENGTH); //cin.getline to accept whitespace

                    cout << "Course Credit: ";
                    cin >> tempCredits;

                    cout << "Study Load: ";
                    cin >> tempStudyLoad;
                    cin.ignore();
                    

                    if (courseType == 1) {

                        cout << "Computer system: ";
                       cin >> tempCourseICT;
                       
                        addICTCourse = new ICTCourse(tempCourseCode, tempCourseTitle, tempCredits, tempStudyLoad, tempCourseICT);
                 
                        courseList_[noOfCourses] = addICTCourse;
                  
                    }
                    else if (courseType == 2) {

                        cout << "Language Requirement: ";
                        cin >> tempGenEd; 
                        
                        addGenEdCourse = new GenEdCourse(tempCourseCode, tempCourseTitle, tempCredits, tempStudyLoad, tempGenEd);
                        courseList_[noOfCourses] = addGenEdCourse;
                        
                    }
                   
                }
                 cout << endl << endl;
                 //courseList_[noOfCourses] = addCourse;
                 noOfCourses++;
            }
            
    int ScmApp::run() {
        int selection;
        char courseCode[MAX_COURSECODE_LEN];

        do {

            menu();
            cin >> selection;

            if (selection == 1) {

                //display the course list
                listCourses();
            }
            else if (selection == 2) {
                //prompts user for course code lookup
                cout << "Please enter the course code : ";
                cin >> courseCode[MAX_COURSECODE_LEN];

                searchACourse(courseCode);

                if (!searchACourse(courseCode)) {

                    cout << "Not Found!" << endl;
                }

            }
            else if (selection == 3) {

                int courseType = 0;

                do {
                    cout << "Please enter the course type (1-ICT or 2-GenEd): ";
                    cin >> courseType;
                    if (courseType == 1 || courseType == 2) {

                        addACourse(courseType);
                    }
                    else {
                        cout << endl << "===Invalid Selection, try again.===" << endl;
                        cout << endl;
                    }
                } while (courseType < 1 ||  courseType > 2);
            }
               
            else if (selection == 4) {
                //prompts user for course code and new study load
                cout << endl << endl;
                char* courseCode = nullptr;
                cout << "Please enter the course code : ";
                courseCode = new char[MAX_COURSECODE_LEN];
                cin >> strcpy(courseCode, courseCode);

                changeStudyLoad(courseCode);
                cout << endl << endl;
            }
            else if (selection == 0) {

                //exit

                cout << endl << endl << "Goodbye!!" << endl;
                break;
            }

            else {

                cout << "===Invalid Selection, try again.===" << endl;
                pause();
            }
        } while (selection > -1 || selection < 5);

        return 0;
    }
}

