
// Count the number of bits to flip to convert a into b.

class Solution {
  public:
    int countBitsFlip(int a, int b) {
        // code here
        int cnt = 0;
        
        while(a || b){
            if(a%2 != b%2) cnt++;
            a >>= 1;
            b >>= 1;
        }
        
        return cnt;
    }
};