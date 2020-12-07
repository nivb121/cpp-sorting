#include "../include/BubbleSort.h"

BubbleSort::BubbleSort(): SortAlgo() {}

BubbleSort::BubbleSort(string path) : SortAlgo(path) {}

BubbleSort::~BubbleSort() = default;

/**
 * @param i first index
 * function swaps data[i] with data[i+1]
 * if i is the last element of the vector or larger- function does nothing
 */
void BubbleSort::swapWithNext(unsigned int i) {
    if( i < this->data.size()-1) {
        int temp = this->data[i];
        this->data[i] = this->data[i + 1];
        this->data[i + 1] = temp;
    }
}


void BubbleSort::Sort() {
    unsigned int size = this->data.size();
    for (unsigned int i=0; i < size-1 ; i++) {
        for (unsigned int j = 0 ; j < size-i-1 ; j++) {
            if(this->data[j] > this->data[j+1])
                swapWithNext(j);
        }
    }
}