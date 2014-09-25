#include "vec.h"
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
        _stopList.push_back(s);
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
        if(!isStop(s))
            addWord(s);
    }

    in.close();
}

void TEST::addWord(const string &word)
{
    It it = _words.begin();
    while(it != _words.end())
    {
        if(word == it->first)
        {
            ++ it->second;
            break;
        }
        ++ it;
    }

    if(it == _words.end())
        _words.push_back(make_pair(word, 1));
}



void TEST::sortFile()
{
    sort(_words.begin(), _words.end(), util::cmp);
}


void TEST::printFile() const
{
    KIt it = _words.begin();
    while(it != _words.end())
    {
        printf("%s : %d\n", it->first.c_str(), it->second);
        ++ it;
    }
}


bool TEST::isStop(const string &word) const
{
    vector<string>::const_iterator it =
        find(_stopList.begin(), _stopList.end(), word);
    return (it != _stopList.end());
}
