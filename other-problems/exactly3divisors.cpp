
// The numbers which have only three unique divisors are the square numbers whose square root is a prime
// so three divsors become 1, squareroot of that number and the number itself.
class Solution {
    bool isPrime(int n){
        for(int i=5; i*i<=n; i+=6){
            if(n%i==0) return false;
            if(n%(i+2)==0) return false;
        }
        return true;
    }
  public:
    int exactly3Divisors(int n) {
        // Your code here
        if(n<=3) return 0;
        if (n <= 8) return 1;
        if( n <= 24) return 2;
        int cnt = 2;
        int i;
        
        for(i=5; i*i<=n; i+=6){
            if(isPrime(i)){
                cnt++;
            }
            if((i+2)*(i+2)<=n && isPrime(i+2)){
                cnt++;
            }
        }
        
        return cnt;
    }
};