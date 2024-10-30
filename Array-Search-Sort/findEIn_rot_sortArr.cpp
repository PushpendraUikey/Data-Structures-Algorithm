#include<bits/stdc++.h>
using namespace std;


/*
Optimally find the element in rotated sorted array
So the approach is to find the pivot element/index first then apply binary search 
in respective half
*/


class Solution {
public:
    static int getPivot(vector<int>& arr, int n){
        int s=0;
        int e{n-1};
        if(arr[0] < arr[e]) return e;   // already sorted

        int mid = s + (e-s)/2;
        while(s<e){
            if(arr[mid] >= arr[0]){     // left side checking         
                s = mid+1;
            }else{
                e = mid;        
            }
            mid = s + (e-s)/2;
        }
        return s;
    }
    static int search(vector<int>& nums, int target) {

        int n = nums.size();

        int pivot = getPivot(nums, n);

        int m, e, s, ans{-1};
 
        if(nums[0] <= target){
            s = 0; 
            e = pivot;
        }
        else{
            s = pivot;
            e = n-1;
        }
        m = s + (e-s)/2;

        while(s <= e){
            if(nums[m] == target) {
                ans = m;
                break;
            }
            else if(nums[m] < target){
                s = m + 1;
            }else{
                e = m - 1;
            }
            m = s + (e-s)/2;                
        }
        return ans;
    }
};

int main(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    for( int i{0}; i< n; i++) cin >> arr[i];

    cout << Solution::search(arr, k) << endl;
}


/*
int getPivot(vector<int>& arr, int n){
        int s=0;
        int e{n-1};

        if(arr[0] <= arr[e]) return 0;

        int mid = s + (e-s)/2;
        
        while(s<e){
            if(arr[mid] >= arr[0]){             
                s = mid+1;
            }else{
                e = mid;        
            }
            mid = s + (e-s)/2;
        }
        return s;
    }


int search(vector<int>& arr, int n, int k)
{
        int pivot = getPivot(arr, n);

        int m, e, s, ans{-1};
 
        if(arr[pivot] <= k && k <= arr[n-1]){           // we want to search right half;
            s = pivot; 
            e = n-1;
        } else{
            s = 0;
            e = pivot-1;
        }

        m = s + (e-s)/2;

        while(s <= e){
            if(arr[m] == k) {
                ans = m;
                break;
            }
            else if(arr[m] < k){
                s = m + 1;
            }else{
                e = m - 1;
            }
            m = s + (e-s)/2;                
        }
        return ans;
}
*/