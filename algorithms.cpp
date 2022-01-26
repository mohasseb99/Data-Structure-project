#include "algorithms.h"

/* merge sort */
long long mMerge = 0;

/* heap sort */
long long mHeap = 0;

/* quick sort */
long long mQuick = 0;

/* counting sort */
long long mCounting = 0;

/* radix sort */
long long mRadix = 0;

/* writing random numbers in file */
void writeRandomNumbersToFile(int size){
    ofstream myfile;
    myfile.open("randomNumbers.txt");

    for(int i = 0; i < size; i++){
        myfile << rand() % size << "\n";
    }
    myfile.close();
}

/* insertion sort*/
/* reading random numbers from randomNumbers.txt file and put them in nums vector
 * then iterate from 1 to size step: step and sort these numbers using insertion and put m in vector called y
 * and return it
*/
vector<int> selectInsertion(int size, int step){
    /* reading random numbers from file and put them in vector */
    vector<int> y;
    for(int i = 1; i <= size; i+=step) {
        vector<int> nums(i);
        ifstream infile;
        infile.open("randomNumbers.txt");
        if (infile.is_open()) {
            for (int j = 0; j < i; j++) {
                infile >> nums[j];
            }
            long long m = insertionSort(nums, i);
            y.push_back(m);
            infile.close();
        }
    }
    return  y;
}
vector<int> asymptoticInsertion(int size, int step){
    vector<int> y;
    for(int i = 1; i <= size; i+=step){
        y.push_back(i * i);
    }
    return y;
}
/* it take vector of int numbers and size to sort numbers and return steps(m) needed to sort vector */
long long insertionSort(vector<int> array, int size) {
    long long m = 0;

    m += 1;
    for (int step = 1; step < size; step++) {
        m += 2;
        int key = array[step];
        m++;
        int j = step - 1;
        m++;
        while (key < array[j] && j >= 0) {
            m++;
            array[j + 1] = array[j];
            m++;
            --j;
            m++;
        }
        m++;
        array[j + 1] = key;
        m++;
    }
    return m;
}

/* merge sort */
/* reading random numbers from randomNumbers.txt file and put them in nums vector
 * then iterate from 1 to size step: step and sort these numbers using merge sort and put m in vector called y
 * and return it
*/
vector<int> selectMerge(int size, int step){
    /* reading random numbers from file and put them in vector */
    vector<int> y;
    for(int i = 1; i <= size; i+=step) {
        vector<int> nums(i);
        ifstream infile;
        infile.open("randomNumbers.txt");
        if (infile.is_open()) {
            for (int j = 0; j < i; j++) {
                infile >> nums[j];
            }
            mMerge = 0;
            mergeSort(nums, 0, i - 1);
            y.push_back(mMerge);
            infile.close();
        }
    }
    return  y;
}
vector<int> asymptoticMerge(int size, int step){
    vector<int> y;
    for(int i = 1; i <= size; i+=step){
        y.push_back(log2(i) * i);
    }
    return y;
}
/* function to sort numbers using merge sort */
void merge(vector<int>array, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    mMerge += 2;
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];
    mMerge += 2;
    // Copy data to temp arrays leftArray[] and rightArray[]
    mMerge += 1;
    for (auto i = 0; i < subArrayOne; i++) {
        mMerge += 2;
        leftArray[i] = array[left + i];
        mMerge += 1;
    }
    mMerge += 1;

    for (auto j = 0; j < subArrayTwo; j++) {
        mMerge += 2;
        rightArray[j] = array[mid + 1 + j];
        mMerge += 1;
    }
    mMerge += 1;

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
    indexOfSubArrayTwo = 0; // Initial index of second sub-array
    mMerge += 2;
    int indexOfMergedArray = left; // Initial index of merged array
    mMerge += 1;
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        mMerge += 1;
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            mMerge += 1;
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            mMerge += 2;
        }
        else {
            mMerge += 1;
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            mMerge += 2;
        }
        indexOfMergedArray++;
        mMerge += 1;
    }
    mMerge += 1;
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        mMerge += 1;
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        mMerge += 3;
    }
    mMerge += 1;
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        mMerge += 1;
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        mMerge += 3;
    }
    mMerge += 1;
}
/* begin is for left index and end is
 right index of the sub-array
 of arr to be sorted */
void mergeSort(vector<int> array, int const begin, int const end)
{
    mMerge += 1;
    if (begin >= end) {
        mMerge++;
        return; // Returns recursively
    }
    auto mid = begin + (end - begin) / 2;
    mMerge += 1;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

/* heap sort */
/* reading random numbers from randomNumbers.txt file and put them in nums vector
 * then iterate from 1 to size step: step and sort these numbers using heap sort and put m in vector called y
 * and return it
*/
vector<int> selectHeap(int size, int step){
    /* reading random numbers from file and put them in vector */
    vector<int> y;
    for(int i = 1; i <= size; i+=step) {
        vector<int> nums(i);
        ifstream infile;
        infile.open("randomNumbers.txt");
        if (infile.is_open()) {
            for (int j = 0; j < i; j++) {
                infile >> nums[j];
            }
            mHeap = 0;
            heapSort(nums, i);
            y.push_back(mHeap);
            infile.close();
        }
    }
    return  y;
}
vector<int> asymptoticHeap(int size, int step){
    vector<int> y;
    for(int i = 1; i <= size; i+=step){
        y.push_back(log2(i) * i);
    }
    return y;
}
/* function to sort numbers using heap sort */
void MaxHeapify(vector<int>arr, int n, int i)
{
    int largest = i;
    mHeap++;
    int l = 2 * i + 1;
    mHeap++;
    int r = 2 * i + 2;
    mHeap++;

    if (l < n && arr[l] > arr[largest]) {
        mHeap += 2;
        largest = l;
    }
    mHeap += 1;

    if (r < n && arr[r] > arr[largest]) {
        mHeap += 2;
        largest = r;
    }
    mHeap += 1;

    if (largest != i) {
        mHeap += 3;
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, n, largest);
    }
    mHeap += 1;
}
void heapSort(vector<int>arr, int n) {
    mHeap += 1;
    for (int i = n / 2 - 1; i >= 0; i--){
        mHeap += 3;
        MaxHeapify(arr, n, i);
    }
    mHeap += 1;

    mHeap += 1;
    for (int i = n - 1; i > 0; i--){
        mHeap += 4;
        swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
    mHeap += 1;
}

/* Quick sort */
/* reading random numbers from randomNumbers.txt file and put them in nums vector
 * then iterate from 1 to size step: step and sort these numbers using Quick sort and put m in vector called y
 * and return it
*/
vector<int> selectQuick(int size, int step){
    /* reading random numbers from file and put them in vector */
    vector<int> y;
    for(int i = 1; i <= size; i+=step) {
        vector<int> nums(i);
        ifstream infile;
        infile.open("randomNumbers.txt");
        if (infile.is_open()) {
            for (int j = 0; j < i; j++) {
                infile >> nums[j];
            }
            mQuick = 0;
            quickSort(nums, 0, i-1);
            y.push_back(mQuick);
            infile.close();
        }
    }
    return  y;
}
vector<int> asymptoticQuick(int size, int step){
    vector<int> y;
    for(int i = 1; i <= size; i+=step){
        y.push_back(i * i);
    }
    return y;
}
/* function to sort numbers using quick sort */
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (vector<int>arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    mQuick += 3;
    for (int j = low; j <= high - 1; j++)
    {
        mQuick += 2;
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            mQuick += 5;
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
        mQuick += 1;
    }
    mQuick += 4;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(vector<int>arr, int low, int high)
{
    if (low < high)
    {
        mQuick += 4;
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    mQuick += 1;
}

/* counting sort */
/* reading random numbers from randomNumbers.txt file and put them in nums vector
 * then iterate from 1 to size step: step and sort these numbers using Counting sort and put m in vector called y
 * and return it
*/
vector<int> selectCounting(int size, int step){
    /* reading random numbers from file and put them in vector */
    vector<int> y;
    for(int i = 1; i <= size; i+=step) {
        vector<int> nums(i+1);
        ifstream infile;
        infile.open("randomNumbers.txt");
        if (infile.is_open()) {
            for (int j = 1; j <= i; j++) {
                infile >> nums[j];
            }
            mCounting = 0;
            countSort(nums, i);
            y.push_back(mCounting);
            infile.close();
        }
    }
    return  y;
}
vector<int> asymptoticCounting(int size, int step){
    vector<int> y;
    for(int i = 1; i <= size; i+=step){
        y.push_back(i+size);
    }
    return y;
}
/* function to sort numbers using counting sort */
int getMax(vector<int>array, int size) {
    int max = array[1];
    mCounting += 2;
    for(int i = 2; i<=size; i++) {
        mCounting += 2;
        if(array[i] > max) {
            mCounting += 2;
            max = array[i];
        }
        mCounting += 1;
    }
    mCounting += 1;
    return max; //the max element from the array
}
void countSort(vector<int>&array, int size) {
    vector<int>output(size+1);
    int max = getMax(array, size);
    vector<int>count(max+1, 0);     //create count array (max+1 number of elements)
    mCounting += 4;
    for(int i = 1; i <=size; i++) {
        mCounting += 3;
        count[array[i]]++;     //increase number count in count array.
    }
    mCounting += 2;
    for(int i = 1; i<=max; i++) {
        mCounting += 3;
        count[i] += count[i - 1];     //find cumulative frequency
    }
    mCounting += 2;
    for(int i = size; i>=1; i--) {
        mCounting += 4;
        output[count[array[i]]] = array[i];
        count[array[i]] -= 1; //decrease count for same numbers
    }
    mCounting += 2;
    for(int i = 1; i<=size; i++) {
        mCounting += 3;
        array[i] = output[i]; //store output array to main array
    }
    mCounting += 1;
}

/* radix sort */
/* reading random numbers from randomNumbers.txt file and put them in nums vector
 * then iterate from 1 to size step: step and sort these numbers using Radix sort and put m in vector called y
 * and return it
*/
vector<int> selectRadix(int size, int step){
    /* reading random numbers from file and put them in vector */
    vector<int> y;
    for(int i = 1; i <= size; i+=step) {
        vector<int> nums(i);
        ifstream infile;
        infile.open("randomNumbers.txt");
        if (infile.is_open()) {
            for (int j = 0; j < i; j++) {
                infile >> nums[j];
            }
            mRadix = 0;
            radixSort(nums, i);
            y.push_back(mRadix);
            infile.close();
        }
    }
    return  y;
}
vector<int> asymptoticRadix(int size, int step){
    vector<int> y;
    for(int i = 1; i <= size; i+=step){
        if(size <= 10){
            y.push_back(i+9);
        } else if(size <= 100){
            y.push_back( 2*(i+9) );
        } else if(size <= 1000){
            y.push_back( 3*(i+9) );
        } else if(size <= 10000){
            y.push_back( 4*(i+9) );
        } else if(size <= 100000){
            y.push_back( 5*(i+9) );
        }
    }
    return y;
}
/* function to sort numbers using counting sort */
int Radix_getMax(vector<int>arr, int n)
{
    int mx = arr[0];
    mRadix += 2;
    for (int i = 1; i < n; i++){
        mRadix += 2;
        if(arr[i] > mx){
            mRadix += 2;
            mx = arr[i];
        }
        mRadix += 1;
    }
    mRadix += 1;
    return mx;
}
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void Radix_countSort(vector<int>&arr, int n, int exp)
{
    vector<int>output(n); // output array
    int i;
    vector<int>count(10, 0);
    mRadix += 4;
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++) {
        mRadix += 3;
        count[(arr[i] / exp) % 10]++;
    }
    mRadix += 1;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    mRadix += 1;
    for (i = 1; i < 10; i++) {
        mRadix += 3;
        count[i] += count[i - 1];
    }
    mRadix += 1;

    // Build the output array
    mRadix += 1;
    for (i = n - 1; i >= 0; i--) {
        mRadix += 4;
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    mRadix += 1;

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    mRadix += 2;
    for (i = 0; i < n; i++) {
        mRadix += 3;
        arr[i] = output[i];
    }
}
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(vector<int>&arr, int n)
{
    // Find the maximum number to know number of digits
    int m = Radix_getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    mRadix += 3;
    for (int exp = 1; m / exp > 0; exp *= 10) {
        mRadix += 3;
        Radix_countSort(arr, n, exp);
    }
}
