#include <bits/stdc++.h>
using namespace std;

/* 
We've to solve a problem in which to find the subarray whose sum gives the required sum
Return: an array containing the initial and final position of subarray
if not present then return -1;
*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ans;
        
        long long sum{0};
        int i{0}, f{0};
        
        if(s==0){
            // int a{-1}, b;
            while(f<n){
                if( arr[f] == 0 ){
                    // a = i+1;
                    // b = (f++)+1;
                    // if(arr[f] != 0 ) break;
                    // continue;
                    ans.push_back(i+1); ans.push_back(f+1);
                    return ans;
                }
                i++;
                f++;
            }
            ans.push_back(-1);
            return ans;
            // if( a != -1){
            //     ans.push_back(a); ans.push_back(b);
            //     return ans;
            // }else{
            //     ans.push_back(a);
            //     return ans;
            // }
        }
        
        sum += arr[0];
        
        while(f<n){
            if(sum == s){
                ans.push_back(i+1);
                ans.push_back(f+1);
                return ans;
            }
            f++;
            if(sum > s){
                sum -= arr[i];
                i++;
                f--;
                continue;       // don't add next element or arr[f] again.
            }
            sum += arr[f];      // add next element
        }
        
        ans.push_back(-1);      // Nothing matched
        return ans;
    }
};



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}