#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Bora Ikizoglu

void printVector(vector<int> vector1){
    
    for(int i=0; i<vector1.size(); i++){
        cout << vector1[i] << endl;
    }
}

///----------------- Quick Sort -----------------

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
int partition (vector<int> &arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low  --> Starting index,
 high  --> Ending index */
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

///----------------- Shell Sort -----------------

void shellSort(vector<int> &arr, int n)
{
    double start_s=clock();
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i++)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    double stop_s=clock();
    cout << "Shell sort time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
    
}

///----------------- Merge Sort -----------------

void merge(vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right){
    
    if (left < right)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int middle = left+(right-left)/2;
        
        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        
        merge(arr, left, middle, right);
    }
}

///----------------- Selection Sort -----------------

void selectionSort(vector<int> &a){
    
    double start_s=clock();
    for(int i=0; i<a.size(); i++){
        int currentElement = a[i];
        
        //finds the smallest element's index on right side of the array
        int indexOfSmallestInTheRight = i;
        for(int j = i; j<a.size(); j++){
            if(a[indexOfSmallestInTheRight] > a[j]){
                indexOfSmallestInTheRight = j;
            }
        }
        
        a[i] = a[indexOfSmallestInTheRight];
        a[indexOfSmallestInTheRight] = currentElement;
    }
    
    double stop_s=clock();
    cout << "Selection sort time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
}

///----------------- Insertion Sort -----------------

////Another implementation of insertion sort, other one is 2-10ms better
//void insertionSort(vector<int> &a){
//
//    double start_s=clock();
//    int j;
//    // loop over the passes
//    for (int p = 1;  p < a.size(); p++){
//        int tmp = a[p];
//        // loop over the elements
//        for (j = p; j > 0 &&  tmp < a[j-1]; j --){
//            a[j] = a[j-1];
//        }
//        a[j] = tmp;
//    }
//
//    double stop_s=clock();
//    cout << "Insertion sort time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
//}

void insertionSort(vector<int> &a){
    
    double start_s=clock();
    
    int holePosition, valueToInsert;
    for(int i=1; i<a.size(); i++){
        
        valueToInsert = a[i];
        holePosition = i;
        while(holePosition > 0 && a[holePosition-1] > valueToInsert){
            a[holePosition] = a[holePosition-1];
            holePosition--;
        }
        a[holePosition] = valueToInsert;
    }
    
    double stop_s=clock();
    cout << "Insertion sort time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
}

///----------------- Bubble Sort -----------------

void bubbleSort(vector<int> &a){
    
    double start_s=clock();
    int loop = 0;
    
    //j<size - i because we are sure that last i elements are already sorted
    for(int i=0; i<a.size()-loop; i++){
        for(int j=0; j<a.size()-loop; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        loop++;
    }
    
    double stop_s=clock();
    cout << "Bubble sort time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
}

///----------------- Counting Sort -----------------

vector<int> generateResultVector(const int *countArray, const int &max){
    
    vector<int> resultVector;
    for(int i=0;i<max;i++){
        for(int j=0; j<countArray[i];j++){
            resultVector.push_back(i);
        }
    }
    return resultVector;
}

int findMax(vector<int> &a){
    int max=0;
    for(int i=0; i<a.size(); i++){
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

void countingSort(vector<int> &a){
    
    
    //Counting sort is the fastest one since it isn't a comparison based sorting algortihm. Its time complexity is O(N)
    //It is asumed that there isn't any negative numbers in the vector
    
    int max = findMax(a);
    int countArray[max];
    
    //Creates an array of 0s
    for(int i=0; i<max; i++){
        countArray[i]=0;
    }
    
    //Counts the numbers
    for(int i=0;i<a.size();i++){
        countArray[a[i]]++;
    }
    
    //generates the result vector
    vector<int> resultVector = generateResultVector(countArray,max);
}



int main(){
    
    
    //creates the vector
    vector<int> vector1, vector2, vector3, vector4, vector5, vector6, vector7;
    
    int inputSize = 10000; //determine the input size(if it is too high like 10^5, it may take too much time)
    //inserts random integers to vector
    for(int i=0; i<inputSize; i++){
        //Generates random numbers betwen 0-9999
        vector1.push_back(rand()%10000);
    }
    
    vector2 = vector1;
    vector3 = vector1;
    vector4 = vector1;
    vector5 = vector1;
    vector6 = vector1;
    vector7 = vector1;
    
    
    //bubble sort
    bubbleSort(vector1);
    
    //insertion sort
    insertionSort(vector2);
    
    //selection sort
    selectionSort(vector3);
    
    //merge sort
    double start_s=clock();
    mergeSort(vector4, 0, vector4.size()-1);
    double stop_s=clock();
    cout << "Merge sort time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << " ms" << endl;
    
    //shell sort
    shellSort(vector5, vector5.size());
    
    //Quick sort
    double start_s2=clock();
    quickSort(vector6, 0, vector6.size());
    double stop_s2=clock();
    cout << "Quick sort time: " << (stop_s2-start_s2)/double(CLOCKS_PER_SEC)*1000 << " ms"<< endl;
    
    //Counting Sort
    double start_s3=clock();
    countingSort(vector7);
    double stop_s3=clock();
    cout << "Counting sort time: " << (stop_s3-start_s3)/double(CLOCKS_PER_SEC)*1000 << " ms"<< endl;
    
    return 0;
}
