#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <bits/stdc++.h>

using namespace std;

void writeRandomNumbersToFile(int size);

/* insertion sort */
vector<int> selectInsertion(int size, int step);
vector<int> asymptoticInsertion(int size, int step);
long long insertionSort(vector<int> array, int size);

/* merge sort */
vector<int> selectMerge(int size, int step);
vector<int> asymptoticMerge(int size, int step);
void merge(vector<int>array, int const left, int const mid, int const right);
void mergeSort(vector<int> array, int const begin, int const end);

/* heap sort */
vector<int> selectHeap(int size, int step);
vector<int> asymptoticHeap(int size, int step);
void MaxHeapify(vector<int>arr, int n, int i);
void heapSort(vector<int>arr, int n);

/* quick sort */
vector<int> selectQuick(int size, int step);
vector<int> asymptoticQuick(int size, int step);
int partition (vector<int>arr, int low, int high);
void quickSort(vector<int>arr, int low, int high);

/* counting sort */
vector<int> selectCounting(int size, int step);
vector<int> asymptoticCounting(int size, int step);
int getMax(vector<int>array, int size);
void countSort(vector<int>&array, int size);

/* radix sort */
vector<int> selectRadix(int size, int step);
vector<int> asymptoticRadix(int size, int step);
void Radix_countSort(vector<int>&arr, int n, int exp);
void radixSort(vector<int>&arr, int n);

#endif // ALGORITHMS_H
