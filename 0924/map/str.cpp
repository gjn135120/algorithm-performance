#include "str.h"
#include <ctype.h>


using namespace std;

namespace stringutil
{
    void erasePunct(string &s)
    {
        string::iterator it = s.begin();
        while(it != s.end())
        {
            if(ispunct(*it))
                it = s.erase(it);
            else
                ++ it;
        }
    }

    void stringToLower(string &s)
    {
        string::iterator it = s.begin();
        while(it != s.end())
        {
            if(isupper(*it))
                *it = tolower(*it);
            ++ it;
        }
    }
    

    bool isAllDigit(const string &s)
    {
        for(string::const_iterator it = s.begin();
            it != s.end();
            ++ it)
        {
            if(!isdigit(*it))
                return false;
        }
        return true;
    }


}

