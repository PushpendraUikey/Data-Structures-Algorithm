#include <bits/stdc++.h>
using namespace std;

/*
Here we are trying to find out if the array contains elements whose absoute difference is
equal to some value.*/

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


class Solution {
public:
    // Function to find if there exists a pair in arr such that
    // the absolute difference between the elements equals x.
    int findPair(int n, int x, vector<int> &arr) {
        // Create an unordered set to store the elements of arr for fast look-up
        unordered_set<int> val;
        
        for(int i{0}; i < n; i++){
            int req = abs(arr[i] - x);
            
            auto it = val.find(req);
            if(it != val.end()) {
                // If the required value is found, check conditions for a valid pair
                if(x < arr[i] || (*it) > x)
                    return 1; 
            }
            req = arr[i] + x;
            it = val.find(req);
            if(it != val.end()) return 1; 
            
            // Insert the current element into the set for future comparisons
            val.insert(arr[i]);
        }
        
        // If no valid pair is found, return -1
        return -1;
    }
};




int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}
