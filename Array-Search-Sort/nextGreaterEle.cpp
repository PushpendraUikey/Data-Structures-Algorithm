#include<bits/stdc++.h>
using namespace std;

// A good usecase of stacks


class Solution
{
    public:
    
    //Function to find the next greater element for each element of the array. (The greater element we want is the first from the given element)

    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> ans;
        ans.push(-1);
        
        for(int i=(n-1); i>= 0; i--){
            while(ans.size() != 1 ){
                if(arr[i] < ans.top()){
                    break;
                }
                ans.pop();  // Remove the top element as it is not the greatest element.
            }
            long long t = arr[i];
            arr[i] = ans.top();
            ans.push(t);
        }
        return arr;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}