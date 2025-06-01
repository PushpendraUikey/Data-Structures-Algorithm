#include<bits/stdc++.h>
using namespace std;

/*
In this problem we've to find the count of subarray whose sum is given as 'k' here
*/

// This solution contains brute force algorithm for array containing elements both positive and negative.

class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sumTotal;
        int n = nums.size();
        int count {0};

        for(int i{0}; i<n; i++){
            sumTotal = nums[i];
            for(int j{i+1}; j < n; j++){
                if(sumTotal == k){
                    count++;
                }
                sumTotal += nums[j];
            }
            if(sumTotal == k) count++;  // last condition check
        }
        return count;
    }
};

// Here we're taking benefit of the subarray condn(it has to be contiguous)
// Solution for the array containing only non-negative elements
// This is two pointer approach, most optimal solution for this problem.
// It has worst case time complexity of O(2n);

class Solution2 {
    public:
        int subarraySum(vector<int> & nums, int k){
            int i = 1, j = 0;
            int n = nums.size();
            int totalSum = nums[0];
            int count = 0;
            int longestSubArrlen = 0;

            while (i <= n)      // '=' is important because, last element can be equal to k, which will be a solution.
            {
                if(totalSum == k){
                    if(i-j > longestSubArrlen) longestSubArrlen = i-j;
                     count++;
                     totalSum = totalSum + nums[i] - nums[j];
                     j++;
                     i++;
                }
                else if(totalSum < k){
                    totalSum += nums[i];  // keep Adding in totalsum using fast pointer
                    i++;
                }else{
                    totalSum -= nums[j];  // removing from totalSum using the slow pointer(As totalsum has exceeded requirements)
                    j++;
                }
            }
            cout <<" Length of longest subarray is: " << longestSubArrlen << endl;
            return count;
    }
};

// This is the better solution to the cases where array has positive and negative elements
// It can lead to the O(n^2) complexity in worst case.
class Solution3 {
    public:
        int getLongestSubarray(vector<int>& nums, int k){
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;

        for (int i{0}; i<nums.size(); i++){
            sum+=nums[i];
            if(sum == k){
                maxLen = max(maxLen, i+1);
            }
            int rem = sum - k;
            if(preSumMap.find(rem) != preSumMap.end()){ // find uses iterator to find element, if not present then it comes to the end
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }
            if(preSumMap.find(sum) == preSumMap.end()){ // for the cases like 2, 0, 0, 3 and k = 3;
                preSumMap[sum] = i;
            }
        }
        return maxLen;
    }
};

int main(){
    int n; cin >> n;
    int k ; cin >> k;
    vector<int> arr;
    for(int i{0}; i<n; i++){
        int a; cin >> a;
        arr.push_back(a);
    }
    Solution2 sb;
    int ans = sb.subarraySum(arr,k);
    cout << "Ans is : " << ans << endl;
}