#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

/*  
///////////////////////////// Two pointer solution to reduce time complexity from M*N to M+N;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(),nums2.end());
    
        auto new_end = unique(nums1.begin(), nums1.end());
        nums1.erase(new_end, nums1.end());

        auto new_end1 = unique(nums2.begin(), nums2.end());
        nums2.erase(new_end1, nums2.end());
        int i{0}, j{0};
        vector<int> arr;
        int m = nums1.size(), n = nums2.size();
        while(i<m && j<n){
            if(nums1[i]==nums2[j]){
                arr.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i]<nums2[j]){
                i++;
            }else {
                j++;
            }
        } 
        return arr;   
    }
};
*/


void find_all_dup(int* a, int k){
    vector<int> arr;
    int i{0};
    while(i<k-1){
        int ans = a[i];
        for(int j{i+1}; j<k; j++){
            if(ans==a[j]) {
                arr.push_back(a[j]);
                break;              //// one instance of duplicate is enough
            }
        }
        i++;
    }
    for(int k{0}; k<arr.size(); k++){
        cout << arr[k] << ' ';
    }
    cout << endl;
}
int main(){
    cout << "Give the length of array followed by elements: ";
    int n; cin >> n;
    int arr[n];
    for(int k{0}; k<n; k++) cin >> arr[k];
    find_all_dup(arr, n);
}
//4,3,2,7,8,2,3,1