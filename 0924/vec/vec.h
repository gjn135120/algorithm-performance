#ifndef VEC_H
#define VEC_H 

#include <vector>
#include <string>
#include <utility>

class TEST
{
    public:
        TEST(const std::string &filename, const std::string &stopFile);

        void readStopFile();
        void readFile();

        void sortFile();
        void printFile() const;
    private:
        void addWord(const std::string &word);
        bool isStop(const std::string &word) const;

        typedef std::vector<std::pair<std::string, int> >::iterator It;
        typedef std::vector<std::pair<std::string, int> >::const_iterator KIt;

        std::string _filename;
        std::string _stopFile;

        std::vector<std::pair<std::string, int> > _words;
        std::vector<std::string> _stopList;
};
#endif  /*VEC_H*/
