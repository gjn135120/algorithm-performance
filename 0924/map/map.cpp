#include "map.h"
#include "str.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

using namespace std;
using namespace stringutil;

namespace util
{
    bool cmp(const pair<string, int> &a,
             const pair<string, int> &b)
    {
        return a.second > b.second;
    }
}

TEST::TEST(const string &filename,
           const string &stopFile)
    :_filename(filename),
     _stopFile(stopFile)
{   }

void TEST::readStopFile()
{
    ifstream in(_stopFile.c_str());
    if(!in)
        throw runtime_error("stopFile打开失败!!");
    string s;
    while(in >> s)
        _stopList.insert(s);
    in.close();
}

void TEST::readFile()
{
    ifstream in(_filename.c_str());
    if(!in)
        throw runtime_error("stopFile打开失败!!");
    
    string s;
    while(in >> s)
    {
        erasePunct(s);
        if(isAllDigit(s))
            continue;
        stringToLower(s);
        if(_stopList.count(s) == 0)
            ++ _words[s];
    }

    in.close();
}

void TEST::copyWord()
{
    _sortWords.clear();
    copy(_words.begin(), _words.end(), back_inserter(_sortWords));

}


void TEST::sortFile()
{
    sort(_sortWords.begin(), _sortWords.end(), util::cmp);
}


void TEST::printFile() const
{
    vector<pair<string, int> >::const_iterator it = _sortWords.begin();
    while(it != _sortWords.end())
    {
        printf("%s : %d\n", it->first.c_str(), it->second);
        ++ it;
    }
}


