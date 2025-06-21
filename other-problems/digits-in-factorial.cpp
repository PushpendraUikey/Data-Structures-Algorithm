// Using Stirling's approximation
// log10(n!) ≈ n * log10(n) - n * log10(e) + 0.5 * log10(2 * π * n), works for n>10^6 as well

class Solution {
  private:
    const double pi = 3.1415927;
  public:
    int digitsInFactorial(int N) {
    
        if(N==0 || N==1) return 1;
        return floor(N * log10(N) - N * log10(exp(1.0)) + 0.5 * log10(2*pi*N))+1;
    }
};