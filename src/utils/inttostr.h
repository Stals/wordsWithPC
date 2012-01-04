#ifndef INTTOSTR_H
#define INTTOSTR_H
#include <string>
#include <sstream>


inline std::string inttostr(int number){
    std::stringstream ss;
    ss<<number;
    std::string str;
    ss>>str;
    return str;
}


#endif // INTTOSTR_H
