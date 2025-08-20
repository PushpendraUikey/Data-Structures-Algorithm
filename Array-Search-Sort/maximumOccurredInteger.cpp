/*
You are given two integer arrays L[] and R[], where each L[i] and R[i] define the start and 
end of a range respectively. The goal is to find the integer that appears in the most number 
of these ranges. If multiple integers occur in the same maximum number of ranges, then return 
the smallest integer among them. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOccured(vector<int>& L, const vector<int>& R) {
        vector<pair<int,int>> vec;
        for(const auto& e: L){
            vec.push_back({e, 1});
        }
        for(const auto&e: R){
            vec.push_back({e, -1});
        }
        
        sort(vec.begin(), vec.end(), [&](auto a, auto b){
            if(a.first == b.first) return a.second > b.second;  // We want to keep starting points first
            return a.first < b.first;
        });
        
        int e = vec[0].first;
        int cnt = 1;
        int maxcnt = 1;
        for(int i=1; i<vec.size(); i++){
            if(vec[i].second < 0){
                cnt--;
            }else{
                cnt++;
                if(cnt > maxcnt){ // leftmost max element shall be given the preference
                    maxcnt = cnt;
                    e = vec[i].first;
                }
            }
        }
        
        return e;
    }
};



class Solution{
    public:
    // L and R are input array
    // maxx : maximum in R[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in L[] and R[]
    //Function to find the maximum occurred integer in all ranges.
    int maxOccured(int L[], int R[], int n, int maxx){
    
        // Your code here
        int arr[maxx+1];
        for(int i=0; i<=maxx; i++){
            arr[i]=0;
        }
        
        // This is the idea of Prefix sum usage in a tricky way
        for(int i=0; i<n; i++){
            arr[L[i]]++;
            arr[R[i]+1]--;
        }
        
        int sum=0;
        int maxSum=sum;
        int maxNum = L[0];
        for(int i=0; i<=maxx; i++){
            sum+=arr[i];
            if(sum>maxSum){
                maxSum = sum;
                maxNum = i;
            }
        }
        
        return maxNum;
    }
};