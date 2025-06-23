class Solution {
  public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n) {
        // Your code here
        if(m==n) return -1;
        
        int cnt=0;
        while(m || n){
            cnt++;
            if(m%2 != n%2) break;
            m >>= 1;
            n >>= 1;
        }
        return cnt;
    }
};