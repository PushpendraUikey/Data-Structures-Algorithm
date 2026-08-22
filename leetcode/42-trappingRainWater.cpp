#include <bits/stdc++.h>
using namespace std;

// We're using the monotonic stack approach to find the left and right maximum heights for each index.
// The assymetric <= and < in the leftMax and rightMax are used to avoid double counting 
// on the flat surface same height ex: 4 2 2 4.
class Solution {
    vector<int> leftMax(vector<int>& height) {
        int n = height.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty()) {
                int idx = st.top();
                if(height[i] >= height[idx]){
                    st.pop();
                }else{
                    ans[i] = idx;
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> rightMax(vector<int>& height) {
        int n = height.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty()) {
                int idx = st.top(); 
                if(height[i] > height[idx]) {
                    st.pop();
                }else{
                    ans[i] = idx;
                    break;
                }
            }
            st.push(i);
        }
        return ans;
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftH = leftMax(height);
        vector<int> rightH = rightMax(height);

        int lh=-1,
            rh=-1;
        long long water = 0;
        for(int i=0; i<n; i++) {
            lh = leftH[i];
            rh = rightH[i];
            if(lh == -1 || rh == -1) continue;
            int ht = std::min(height[lh], height[rh]) - height[i];
            int wt = rh - lh - 1;
            water += (wt*ht);
        }
        return water;
    }
};

// Another approach
class Solution {
public:
    int trap(vector<int>& height) {
        long long water = 0;
        int left = 0;
        int right = 1;
        int i = 1;
        int n = height.size();

        while(right < n) {
            while(right < n && height[right] < height[left]) right++;
            if(right==n) break;
            for(int i=left+1; i<right; i++) {
                water += (height[left] - height[i]);
            }
            left = right;
            right += 1;
        }

        right = n-1; left = n-1;
        while(left >= 0) {
            while(left >= 0 && height[left] <= height[right]) left--;
            if(left < 0) break;
            for(int i=right-1; i>left; i--){
                water += (height[right] - height[i]);
            }
            right = left;
        }

        return water;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int maxLeft = 0;
        int maxRight = 0;
        long long water = 0;
        
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left]; // Update the left wall
                } else {
                    water += maxLeft - height[left]; // Trap water
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right]; // Update the right wall
                } else {
                    water += maxRight - height[right]; // Trap water
                }
                right--;
            }
        }
        
        return water;
    }
};