#include "../include/MergeSort.h"

MergeSort::MergeSort() : SortAlgo() {}

MergeSort::MergeSort(string path) : SortAlgo(path) {}

MergeSort::~MergeSort() = default;

/**
 * function merges 2 sorted vectors into 1 sorted vector
 * @param v1 - ref to the first vector
 * @param v2  - ref to the second vector
 * @param output - ref to the vector that will store the result
 * @return merged vector
 */
void MergeSort::Merge(vector<int>& v1, vector<int>& v2, vector<int>& output) {
    unsigned int i = 0;
    auto iter1 = v1.begin();
    auto iter2 = v2.begin();
    while((iter1 != v1.end()) && (iter2 != v2.end())) {
        if (*iter1 <= *iter2) {
            output[i] = *iter1;
            iter1++;
            i++;
        }
        else {
            output[i] = *iter2;
            iter2++;
            i++;
        }
    }
    while (iter1 != v1.end()) { //if v2 finished faster
        output[i] = *iter1;
        iter1++;
        i++;
    }
    while (iter2 != v2.end()) { //if v1 finished faster
        output[i] = *iter2;
        iter2++;
        i++;
    }
}

void MergeSort::MergeSortImp(vector<int> &toSort) {
    unsigned int size = toSort.size();
    if(size==1)
        return;
    else if(size==2) {
        if(toSort[0]<=toSort[1])
            return;
        else {
            int temp = toSort[0];
            toSort[0] = toSort[1];
            toSort[1] = temp;
            return;
        }
    }
    // else: size if bigger than 2
    unsigned int middle = toSort.size()/2;
    // cut in half
    vector<int>* leftHalf= new vector<int>(toSort.begin(), toSort.begin()+middle);
    vector<int>* rightHalf= new vector<int>(toSort.begin()+middle, toSort.end());
    // sort each half
    MergeSortImp(*leftHalf);
    MergeSortImp(*rightHalf);
    // merge
    Merge(*leftHalf,*rightHalf, toSort);
    // release no longer needed memory
    delete leftHalf;
    delete rightHalf;
}


void MergeSort::Sort() {
    MergeSortImp(this->data);
}