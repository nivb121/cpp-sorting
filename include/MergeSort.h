#ifndef COPTERFIX_SORT_MERGESORT_H
#define COPTERFIX_SORT_MERGESORT_H
#include "SortAlgo.h"
#include <vector>
#include <string>
using namespace std;

class MergeSort : public SortAlgo {
public:
    MergeSort();
    MergeSort(string path);
    virtual ~MergeSort();
    virtual void Sort();
private:
    void MergeSortImp(vector<int>& toSort);
    void Merge(vector<int>& v1, vector<int>& v2, vector<int>& output);
};


#endif //COPTERFIX_SORT_MERGESORT_H
