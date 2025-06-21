class Solution {
  public:
    bool isPrime(int N) {
        // Your code here
        if(N<=1) return false;
        
        if(N==2 || N==3) return true;
        
        if(N%2==0 || N%3==0) return false;
        
        int i;
        for(i=5; i*i<=N; i+=6){     // 6K+1, 6K-1, are prime > 3, start with 5, beause condition check may miss some numbers if compared with square of large num
            if(N%i == 0 || N%(i+2) == 0) return false;
        }
        
        return true;
    }
};
