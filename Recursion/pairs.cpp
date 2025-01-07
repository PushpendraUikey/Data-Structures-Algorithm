#include<bits/stdc++.h>
using namespace std;

int main(){
    // .first gives first value and .second gives second value.
    pair<int, string> p;
    p = make_pair(2,"abc"); // to store pairs in a pair
    p = {3, "Pushpendra"};

    pair<int, string> &p1 = p;  // created a reference for it.
    p1 = {5, "Hello"};

    cout << p.first << " " << p.second << endl;

    int a[] = {1,2,3};
    int b[] = {2,3,4};

    uint32_t n; cin >> n;
    cout << n << endl;

    int* arr = new int[n];  // creating an array in heap, i.e. dynamic memory allocation

    for(int i{0}; i<n; i++){
        cin >> arr[i];
    }
    for(int i{0}; i<n; i++){
        cout << *(arr+i) << endl;
    }
    delete arr; // empty the memory used

}

// In static allocation, memory automatically releases by itself while in dynamic memory allocation, you have to do it by yourself.
