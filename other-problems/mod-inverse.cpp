

// if a and m are two numbers, then a number b is modular inverse of a if (a*b)%m == 1;
class Solution {
  public:
    // Complete this function
    int modInverse(int a, int m) {
        // Your code here
        if(a%m == 1) return 1;
        if(a%m == 0) return -1;
        
        for(int i=2; i<m; i++){
            if(((a%m)*i ) % m == 1) return i;
        }
        return -1;
    }
};