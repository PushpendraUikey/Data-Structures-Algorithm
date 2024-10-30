#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers where each element represents the number of pages in a book, and a number 𝑚
representing the number of students, the task is to allocate books to students such that:

1) Each student gets a contiguous block of books.
2) The maximum number of pages assigned to any student is minimized.


Answer:
    The lowest feasible "maximum pages" from the binary search is the answer.

Note: here the array is sorted in non-decreasing order
*/

bool isPossible(vector<int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum  = 0;

    for(int i{0}; i < n; i++){
        if( pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }else{
            studentCount++;
            if(studentCount > m || arr[i] > mid ){  // Yadi mid se arr[i] bada ho gya to right side me allocation to possible hi nhi hai and m logo ko hi allot krna hai
                return false;
            }
            pageSum = arr[i];  // started allocating page's to nextstudent
        }
    }
    return true;            // Everyone got allocated a book and hence it is a possible solution.(we want optimum distribution)
}

int allocateBooks(vector<int> arr, int n, int m){
    int sum{0};

    for(int i{0}; i<n; i++) sum += arr[i];

    int s = 0;
    int e = sum;            // starting the end from total sum.
    int mid = s + (e-s)/2;
    int ans = -1;

    while(e >= s){
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;    // since we want min number so we are going for left side.
        }else{
            s = mid + 1;    // solution not possible then increase the number of pages
        }
        mid = s + (e-s)/2;
    }
    return ans;
}