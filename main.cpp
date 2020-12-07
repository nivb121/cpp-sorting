#include <iostream>
#include <chrono>
#include <fstream>
#include "include/SortAlgo.h"
#include "include/BubbleSort.h"
#include "include/MergeSort.h"
#include "include/QuickSort.h"

using namespace std;

double SortAndTime(SortAlgo& sa, string outPath) {
    auto start = chrono::high_resolution_clock::now();
    sa.Sort();
    auto finish = chrono::high_resolution_clock::now();
    sa.WriteOutput(outPath);
    chrono::duration<double> elapsed = (finish - start)*1000.0;
    return elapsed.count();
}

int main() {
    string inPath;
    string outPath;
    cout << "Please enter full path for input:";
    cin >> inPath;
    cout << "Please enter full path for output *folder* :";
    cin >> outPath;
    QuickSort qs(inPath);
    MergeSort ms(inPath);
    BubbleSort bs(inPath);
    cout << "Sorting... \n";
    string quickSortRes = "QuickSort performance: " + to_string(SortAndTime(qs,outPath+"\\QuickSortOutput.txt")) + " milliseconds\n";
    string mergeSortRes = "MergeSort performance: " + to_string(SortAndTime(ms,outPath+"\\MergeSortOutput.txt")) + " milliseconds\n";
    string bubbleSortRes = "BubbleSort performance: " + to_string(SortAndTime(bs,outPath+"\\BubbleSortOutput.txt")) + " milliseconds\n";

    ofstream executionTimeFile(outPath+"\\ExecutionTimeOutput.txt");
    if(executionTimeFile.is_open()) {
        executionTimeFile << quickSortRes;
        executionTimeFile << mergeSortRes;
        executionTimeFile << bubbleSortRes;
        executionTimeFile.close();
    }
    return 0;
}