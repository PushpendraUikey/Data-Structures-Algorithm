#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int size = arr.size();

        int lastval = arr[0];
        int cnt = 1;
        int removed = 0;
        for(int i=1; i<size; i++) {
            if(arr[i] == lastval){
                cnt++;
                if(cnt > 2) {
                    arr[i] = INT_MIN;
                    removed++;
                }
            } else {
                cnt = 1;
                lastval = arr[i];
            }
        }
        
        if(removed > 0){
            int left = 0, right = 1;
            while(right < size) {
                if(arr[left] == INT_MIN) {
                    while(right < size){
                        if(arr[right] != INT_MIN) break;
                        right++;
                    }
                    if(right == size) break;
                    swap(arr[left], arr[right]);
                }
                left++; right++;
            }
        }
        return size-removed;
    }
};

// alternate less complex solution
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.size() <= 2) return arr.size();

        int j = 2;
        for (int i = 2; i < arr.size(); i++) {
            if(arr[i] != arr[j-2]) {
                arr[j] = arr[i];
                j++;
            }
        }
        return j;
    }
};