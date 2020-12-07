#ifndef COPTERFIX_SORT_BUBBLESORT_H
#define COPTERFIX_SORT_BUBBLESORT_H
#include "SortAlgo.h"
#include <vector>
#include <string>
using namespace std;

class BubbleSort : public SortAlgo {
public:
    BubbleSort();
    BubbleSort(string path);
    virtual ~BubbleSort();
    virtual void Sort();
private:
    void swapWithNext(unsigned int i);
};


#endif //COPTERFIX_SORT_BUBBLESORT_H
