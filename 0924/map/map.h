#ifndef VEC_H
#define VEC_H 

#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>

class TEST
{
    public:
        TEST(const std::string &filename, const std::string &stopFile);

        void readStopFile();
        void readFile();
        
        void copyWord();
        void sortFile();
        void printFile() const;
    private:
        typedef std::map<std::string, int>::iterator It;
        typedef std::map<std::string, int>::const_iterator KIt;

        std::string _filename;
        std::string _stopFile;
        
        std::map<std::string, int> _words;
        std::set<std::string> _stopList;

        std::vector<std::pair<std::string, int> > _sortWords;
};
#endif  /*VEC_H*/
