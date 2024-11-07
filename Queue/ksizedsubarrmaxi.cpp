#include <bits/stdc++.h>
using namespace std;

/*
Algorithm to find maximum in every k-sized window. Can't use priority queue here as it 
do not guarantees that elements are from the window of size-k. 
*/
/*
use deque for both side insertion and deletion 
*/

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque<int> dq(k);
        
        // first k window
        for(int i=0; i<k ;i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i=k; i<n; i++){
            ans.push_back(arr[dq.front()]);
            
            /// removal for size constraints
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            
            /// Removal to find maxi;
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //// last window consideration
        ans.push_back(arr[dq.front()]);

        return ans;
    }
    
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
