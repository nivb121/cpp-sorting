# cpp-sorting
This project includes implementation of 3 sorting algorithms in C++

# Main
Asks for a full path for the input file, and a full path for the output file.
The main function builds 1 object of each sorting algorithm, activates it, measures the runtime and prints it.

# Sort Algo
General data type designed to implement the basic and shared functions such as:
- Empty initializing
- Initializing from file
- Loading data from a second vector
- Loading an input file
- Output writing to file
- Sort - virtual function to activate the sorting algorithm

# Bubble Sort
Algorithm is in-place and works at O(n^2).

# Merge Sort
Algorithm is stable and works at O(n * log n).

at each iteration of the algorithm a vector is alocated on the heap, sorted, merged, and cleaned from the heap.

# Quick Sort
Algorithm is in-place and is estimated to O(n * log n) expected.

For each iteration the pivot is chosen randomly, assuring the probabilistic runtime analysis.
