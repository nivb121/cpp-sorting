#ifndef COPTERFIX_SORT_QUICKSORT_H
#define COPTERFIX_SORT_QUICKSORT_H

#include "SortAlgo.h"

class QuickSort : public SortAlgo {
public:
    QuickSort();
    QuickSort(string path);
    virtual ~QuickSort();
    virtual void Sort();
private:
    void QuickSortImp(unsigned int left, unsigned int right, vector<int>& toSort);
    unsigned int Partition(vector<int>& v, unsigned int start, unsigned int end);
    unsigned int SelectPivot(unsigned int vectorSize);
    void Swap(unsigned int i, unsigned int j, vector<int>& v);
};


#endif //COPTERFIX_SORT_QUICKSORT_H
