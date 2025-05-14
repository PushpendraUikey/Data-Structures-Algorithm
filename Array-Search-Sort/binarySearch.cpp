#include <iostream>

// binary search for array sorted in non-decreasing order.
int binarysearch(int* array, int n, int x){
    int k = 0;
    for (int b = n/2; b >= 1; b /= 2) {
        while (k+b < n && array[k+b] <= x) k += b;
    }
    if (array[k] == x) {
        return k;
    }
    return -1;
}

// binary search for array sorted in non-decreasing order
int binarysearch2(int* array, int n, int x){
    int a = 0, b = n-1;
    while (a <= b) {
        int k = (a+b)/2;
        if (array[k] == x) {
            return k;
        }
        if (array[k] > x) b = k-1;
        else a = k+1;
    }
    return -1;
}