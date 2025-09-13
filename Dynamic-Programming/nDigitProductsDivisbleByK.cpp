/*
Anya loves playing with digits. One day, she challenges Theo:
 “Can you count how many -digit numbers can be formed using the digits 0–9 such that the product
 of all digits is divisible by ?”
 Theo wants to impress Anya, but the task isn’t easy. Can you help him solve it?
 Problem Details
 An -digit number is a number that has exactly  digits in decimal representation.
 For example:
 1. If , valid numbers are from 10 to 99.
 2. If , valid numbers are from 100 to 999.
 Note: Leading zeros are not allowed, so 07 is not considered a 2-digit number.
 You must check the product of digits of each valid number.
 Example: For the number 243, the product of digits is 2 × 4 × 3 = 24.
 The task is to count how many of these numbers have a digit product that is divisible by .
 Because the number of valid numbers can be huge, return the result modulo 10e9 + 7.
 Input Format
 The first line contains an integer .
 The second line contains an integer .
 Constraints
 1<= n <= 1e9
 1<= k <= 43
 */


// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// #define ll long long

// using namespace std;
// const int mod = 1000000007;
// int cnt=0;
// ll nCk(int n, int k, vector<vector<ll>>&val){      // programmer's responsibility to ensure n>=k
//     cnt++;
//     // here comes the base case
//     if(n==k || k==0) return 1;  // nCn & nC0 both are equal to 1.
//     if(val[n][k] != -1) return val[n][k];

//     return val[n][k] = (nCk(n-1, k-1, val) + nCk(n-1, k, val)) % mod;
// }

// void solve(int n, int k, long long& ans){
//     int i=1;
//     while(n-1>=i){
//         vector<vector<ll>> val(n, vector<ll>(i+1, -1));
//         ll temp = nCk(n-1, i, val);
//         for(int j=0; j<n-i; j++){
//             temp = (temp*9)%mod;
//         }
//         ans = (ans + temp)%mod;
//         i++;
//     }
//     // ans = (ans*9)%mod;
// }

// int powerofPrimeinN(int, int, vector<int>&);
// // n > 0
// vector<int> prime_factors(int n){
//     vector<int> ans;
//     if(n == 1){
//         ans.push_back(1);
//         return ans;
//     }
//     int v;
//     if(n%2==0){
//         v = powerofPrimeinN(n, 2, ans);
//         n /= pow(2, v);
//     }
//     if(n%3==0){
//         v = powerofPrimeinN(n, 3, ans);
//         n /= pow(3,v);
//     }

//     int i;
//     int N = n;
//     for(i=5; i*i<=N; i+=6){
//         if(n%i == 0){
//             v = powerofPrimeinN(n, i, ans);
//             n /= pow(i, v);
//         }
//         if(n%(i+2) == 0){
//             v = powerofPrimeinN(n, i+2, ans);
//             n /= pow(i+2, v);
//         }
//     }
//     if(n>1) ans.push_back(n);

//     return ans;
// }

// int powerofPrimeinN(int n, int k, vector<int>&ans){
//     int r=0;
//     while(n>0){
//         if(n%k==0){
//             r++;
//             n /= k;
//         }else{
//             break;
//         }
//     }
//     int c = r;
//     while(r-->0){
//         ans.push_back(k);
//     }
//     return c;
// }

// bool isPrime(int N) {
//         // Your code here
//         if(N<=1) return false;
        
//         if(N==2 || N==3) return true;
        
//         if(N%2==0 || N%3==0) return false;
        
//         int i;
//         for(i=5; i*i<=N; i+=6){     // 6K+1, 6K-1, are prime > 3, start with 5, beause condition check may miss some numbers if compared with square of large num
//             if(N%i == 0 || N%(i+2) == 0) return false;
//         }
        
//         return true;
// }
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, k;
//     cin >> n >> k;
//     long long ans=0;
    
//     if(k==1){
//         ll temp = 1;
//         for(int i=0; i<n; i++){
//             ans = temp;
//             temp = (temp*10)%mod;
//         }
//         // ans = temp;
//         // temp = (temp*9)%mod;
//         cout << (temp-ans)%mod <<"\n";
//         return 0;
//     }
//     solve(n, k, ans);   // for divisibility from 0
//     if(isPrime(k) && k > 9){
//         cout << ans << "\n";
//         return 0;
//     }
    
//     vector<int> factors = prime_factors(k);
//     int sizef = factors.size();
//     if(sizef > n){
//         cout << ans << "\n";
//         return 0;
//     }
//     int num2=0, num3=0, num5=0, num7=0;
//     bool excd=false;
//     for(int i=0; i<sizef; i++){
//         if(factors[i]==2)num2++;
//         else if(factors[i]==3) num3++;
//         else if(factors[i]==5) num5++;
//         else if(factors[i]==7) num7++;
//         else excd = true;
//     }
//     if(excd){
//         cout << ans << "\n";
//         return 0;
//     }
//     vector<vector<ll>> val(n+1, vector<ll>(sizef, -1));
    
//     ll temp = nCk(n, sizef, val);
//     for(int i=0; i<n-sizef; i++){
//         temp = (temp*9)%mod;
//     }
//     ans = (ans+temp)%mod;
// //     while(num2>1){
        
// //     }
    
//     cout << ans << "\n";

//     return 0;
// }



// This solution is ChatGPTed!!!
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

// fast power
ll modpow(ll a, ll e){
    ll r=1;
    while(e){
        if(e&1) r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}

// matrix utilities
using Mat = vector<vector<ll>>;

Mat mul(const Mat &A, const Mat &B){
    int n=A.size(); int m=B[0].size(); int p=B.size();
    Mat C(n, vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int k=0;k<p;k++) if(A[i][k]){
            ll av=A[i][k];
            for(int j=0;j<m;j++){
                C[i][j]=(C[i][j]+av*B[k][j])%MOD;
            }
        }
    }
    return C;
}

Mat matPow(Mat base, long long exp){
    int n=base.size();
    Mat res(n, vector<ll>(n,0));
    for(int i=0;i<n;i++) res[i][i]=1;
    while(exp){
        if(exp&1) res=mul(res,base);
        base=mul(base,base);
        exp>>=1;
    }
    return res;
}

// main solve
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; int k;
    cin>>n>>k;

    if(k==1){
        cout << (9*modpow(10,n-1))%MOD << "\n";
        return 0;
    }

    // count numbers with at least one zero
    ll total = 9*modpow(10,n-1)%MOD;
    ll nozero = 9*modpow(9,n-1)%MOD;
    ll atleastOneZero = (total-nozero+MOD)%MOD;

    // factorize k into 2,3,5,7 only
    vector<int> primes={2,3,5,7};
    map<int,int> need;
    int tmp=k;
    for(int p:primes){
        while(tmp%p==0){
            need[p]++;
            tmp/=p;
        }
    }
    if(tmp!=1){
        // has a prime factor >7 --> only numbers with 0 work
        cout<<atleastOneZero<<"\n";
        return 0;
    }

    // build state space
    vector<int> bases;
    vector<int> plist;
    for(int p:primes) if(need[p]>0){
        plist.push_back(p);
        bases.push_back(need[p]+1);
    }
    int dims=bases.size();
    int S=1;
    for(int b:bases) S*=b;

    auto idx_of=[&](const vector<int>&v){
        int idx=0, mul=1;
        for(int i=0;i<dims;i++){
            idx+=v[i]*mul;
            mul*=bases[i];
        }
        return idx;
    };

    // prime factor contribution of digits 1to9
    array<array<int,4>,10> contrib{};
    for(int d=2;d<=9;d++){
        int x=d;
        array<int,4> cnt={0,0,0,0};
        int temp=x;
        while(temp%2==0){cnt[0]++; temp/=2;}
        while(temp%3==0){cnt[1]++; temp/=3;}
        while(temp%5==0){cnt[2]++; temp/=5;}
        while(temp%7==0){cnt[3]++; temp/=7;}
        contrib[d]=cnt;
    }

    // transition matrix
    Mat T(S, vector<ll>(S,0));
    for(int s=0;s<S;s++){
        vector<int> cur(dims);
        int tmp=s;
        for(int i=0;i<dims;i++){cur[i]=tmp%bases[i]; tmp/=bases[i];}
        for(int d=1;d<=9;d++){
            vector<int> nxt=cur;
            for(int i=0;i<dims;i++){
                int p=plist[i];
                int add=0;
                if(p==2) add=contrib[d][0];
                else if(p==3) add=contrib[d][1];
                else if(p==5) add=contrib[d][2];
                else if(p==7) add=contrib[d][3];
                nxt[i]=min(bases[i]-1, cur[i]+add);
            }
            int t=idx_of(nxt);
            T[s][t]=(T[s][t]+1)%MOD;
        }
    }

    // initial vector after first digit (no zero)
    vector<ll> v0(S,0);
    for(int d=1;d<=9;d++){
        vector<int> st(dims,0);
        for(int i=0;i<dims;i++){
            int p=plist[i];
            int add=0;
            if(p==2) add=contrib[d][0];
            else if(p==3) add=contrib[d][1];
            else if(p==5) add=contrib[d][2];
            else if(p==7) add=contrib[d][3];
            st[i]=min(bases[i]-1, add);
        }
        v0[idx_of(st)]++;
    }

    // exponentiate
    Mat Texp=matPow(T,n-1);
    vector<ll> v(S,0);
    for(int j=0;j<S;j++){
        ll sum=0;
        for(int i=0;i<S;i++){
            sum=(sum+v0[i]*Texp[i][j])%MOD;
        }
        v[j]=sum;
    }

    // goal state
    vector<int> goal(dims);
    for(int i=0;i<dims;i++) goal[i]=bases[i]-1;
    int g=idx_of(goal);
    ll noZeroAnswer=v[g];

    ll ans=(atleastOneZero+noZeroAnswer)%MOD;
    cout<<ans<<"\n";
}
