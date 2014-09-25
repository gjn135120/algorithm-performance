#ifndef STR_H
#define STR_H 
#include <string>

namespace stringutil
{
    void erasePunct(std::string &s);
    void stringToLower(std::string &s);
    bool isAllDigit(const std::string &s);
}


#endif  /*STR_H*/
