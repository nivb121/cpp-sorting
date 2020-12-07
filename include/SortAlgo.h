#ifndef COPTERFIX_SORT_SORT_H
#define COPTERFIX_SORT_SORT_H
#include <vector>
#include <string>

using namespace std;

class SortAlgo{
public:
    SortAlgo(); //initiate an empty instance
    SortAlgo(string path); //initiate with file input
    virtual ~SortAlgo();
    void LoadInput(vector<int> in); // loads input from a vector
    bool LoadInputFile(string path); //loads input from file
    virtual void Sort();
    void WriteOutput(string path);
    //Debug only
    void PrintData();

protected:
    vector<int> data;
};

#endif //COPTERFIX_SORT_SORT_H
