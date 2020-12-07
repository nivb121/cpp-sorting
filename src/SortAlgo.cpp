#include <cstdio>
#include <iostream>
#include <fstream>
#include "../include/SortAlgo.h"

SortAlgo::SortAlgo(): data() {}

SortAlgo::SortAlgo(string path): data() {
    LoadInputFile(path);
}

SortAlgo::~SortAlgo() {};

void SortAlgo::LoadInput(vector<int> in) {
    auto inputIterator = in.begin();
    while(inputIterator != in.end()) {
        this->data.push_back(*inputIterator);
        inputIterator++;
    }
}

void SortAlgo::PrintData() {
    auto iter = this->data.begin();
    while(iter != this->data.end()) {
        printf("%d\n",*iter);
        iter++;
    }
}

bool SortAlgo::LoadInputFile(string path) {
    string line;
    ifstream input(path);
    if(input.is_open()) {
        while( getline(input,line) ) {
            this->data.push_back(stoi(line));
        }
        input.close();
        return true;
    }
    return false;
}

void SortAlgo::Sort() {}

void SortAlgo::WriteOutput(string path) {
    ofstream output(path);
    if(output.is_open()) {
        auto iter = this->data.begin();
        while(iter != this->data.end()) {
            output << *iter << "\n";
            iter++;
        }
        output.close();
    }
}



