/* OOP244-Seneca Course Management App- MS4

 File Streamable.h
 Version 1.4
 Date 8/08/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca
 SID 031028095

 Revision History
  __________________________________________________________________________________________
 | Name      | Date    | Reason                                                             |
 |------------------------------------------------------------------------------------------|
 | M.Beltempo 8/08/2016  Declared pure virtual functions for parent class                   |
 |__________________________________________________________________________________________|

*/

#include <fstream>

#ifndef _STREAMABLE_H_
#define _STREAMABLE_H_

using namespace std;

namespace sict {

    class Streamable {

    public:
       virtual fstream& store(fstream& file, bool addNewLine = true) const = 0;
       virtual fstream& load(std::fstream& file) = 0;
       virtual ostream& display(ostream& os) const = 0;
       virtual istream& read(istream& is) = 0;
    };

}
#endif
