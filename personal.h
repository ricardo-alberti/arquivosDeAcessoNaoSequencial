#ifndef PERSONAL
#define PERSONAL

#include <fstream.h>
#include <cstring.h>
using namespace std;

class Personal {
public:
Personal();
    Personal(char*,char*,char*,int,long);
    void writeToFile(fstream&) const;
    void readFromFile(fstream&);
    void readKey();
    int size () const {
        return 9 + nameLen + cityLen + sizeof(year) + sizeof(salary);
    }
    bool operator==(const Personal& pr) const {
        return strncmp(pr.SSN,SSN,9) == 0;
    }

protected:
    const int nameLen, cityLen;
    char SSN[10],*name, *city;
    int year;
    long salary;
    ostream& operator<<(ostream& out,Personal& pr) {
        return pr.writeLegibly(out);
    }
    istream& readFromConsole(istream&);
    friend istream& operator>>(istream& in, Personal& pr) {
        return pr.readFromConsole(in);
    }
};

#endif    

        
