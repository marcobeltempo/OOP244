/* OOP244-Seneca Course Management App- MS4

 File MS1_Main.cpp
 Version 1.2
 Date 7/19/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca

 Revision History
  _________________________________________________________________________________________
 | Name      | Date  |  Reason                                                             |
 |-----------------------------------------------------------------------------------------|
 | M.Beltempo 7/20/16  Main used to test program                                           |
 | M.Beltempo 8/09/16  Added file name                                                     |
 |_________________________________________________________________________________________|

*/

#include "ScmApp.h"
#include "Course.h"

using namespace std;
using namespace sict;

int main() {

    ScmApp app("file.txt");
   
    app.run();

    return 0;
}





