#include "../include/QuickSort.h"
#include <ctime>

using namespace std;

QuickSort::QuickSort(): SortAlgo() {};

QuickSort::QuickSort(string path) : SortAlgo(path) {}

QuickSort::~QuickSort() = default;

void QuickSort::Sort() {
    QuickSortImp(0,this->data.size()-1,this->data);
}

void QuickSort::QuickSortImp(unsigned int left, unsigned int right, vector<int>& toSort) {
    if(left >= right)
        return;
    else if(right == left+1) {
        if(toSort[left]<=toSort[right])
            return;
        else {
            Swap(left,right,toSort);
            return;
        }
    }
    // else: size if bigger than 2
    unsigned int pivotIndex = Partition(toSort,left,right);
    // recursive sorting according to partition
    QuickSortImp(left,pivotIndex-1,toSort);
    QuickSortImp(pivotIndex+1,right,toSort);
}

/**
 * apply the partition algorithm with a random pivot. returns the pivot's index
 * @param v - vector to apply the function to
 * @return pivot's index in the rearranged vector
 */
unsigned int QuickSort::Partition(vector<int> &v, unsigned int start, unsigned int end) {
    unsigned int size = end-start+1;
    unsigned int pivotIndex = SelectPivot(size) + start; // absolut index in the vector, not relational to the sub-vector at work
    int pivot = v[pivotIndex];
    if (pivotIndex != end)
        Swap(pivotIndex,end,v);
    int i = start-1;
    for (unsigned int j=start ; j < end ; j++) {
        if(v[j] <= pivot) {
            i++;
            if (j>start && v[j-1]>pivot)
                i>=start ? Swap(i,j,v) : Swap(start,j,v);
        }
    }
    Swap(i+1,end,v);
    return i+1;
}

/**
 * swap elements i & j inside a given vector. if i or j are invalid, nothing get's done.
 * @param i
 * @param j
 */
void QuickSort::Swap(unsigned int i, unsigned int j, vector<int>& v) {
    if (i < v.size() && i >=0 && j < v.size() && j >=0) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

/**
 * function gets vector size and returns a random pivot index
 * @param vectorSize - to serve as max index
 * @return index to use as pivot
 */
unsigned int QuickSort::SelectPivot(unsigned int vectorSize) {
    srand((unsigned) time(0));
    return (rand() % vectorSize);
}