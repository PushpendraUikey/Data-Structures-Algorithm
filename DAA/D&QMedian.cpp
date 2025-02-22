#include <bits/stdc++.h>
using namespace std;


// Here trying to find the median of an array using divide and conquer technique.

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];          // Random selection like quick sort.
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

int findMedian(std::vector<int>&arr, int low, int high, int median){

    if(low==high) return arr[low];

    int pi = partition(arr, low, high);
    int rank = pi - low;

    if(rank == median) return arr[pi];
    else if(median < rank){
        return findMedian(arr, low, pi-1, median);
    }else {
        return findMedian(arr, pi+1, high, median-rank-1);
    }
}

int main() {
    std::vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    int n = arr.size();
    
    // For median in an odd-length array, k = n/2 (0-indexed)
    int median = findMedian(arr, 0, n - 1, n / 2);
    std::cout << "Median: " << median << std::endl;
    
    // For even-length arrays, you might average the two middle values:
    // int m1 = quickSelect(arr, 0, n - 1, n/2 - 1);
    // int m2 = quickSelect(arr, 0, n - 1, n/2);
    // double medianEven = (m1 + m2) / 2.0;
    // std::cout << "Median: " << medianEven << std::endl;

    return 0;
}