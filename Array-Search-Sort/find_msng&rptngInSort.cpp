#include <bits/stdc++.h>
using namespace std;

// Have to find a repeating element and a missing element in a unsorted array which have elements [1,N];

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        sort(arr.begin(),arr.end());        // sorting
        
        int miss = (arr[0] != 1 ) ? 1 : -1; // check if '1' is missng
        
        vector<int> ans;
        
        for(int i{2}; i <= n; i++){
            if(arr[i-1]!=i){            // if element is not present in i-1 & i-2 then it is not present(it might present at i but miss will be update in loop till a missing element is encountered.)
                if(arr[i-2] != i ){    // logic is silly but still worked
                     miss = i;
                }
            }
            if(arr[i-1]==arr[i-2]) ans.push_back(arr[i-1]);     // checking for consecutive elements repeating.
        }
        
        ans.push_back(miss);
        return ans;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}