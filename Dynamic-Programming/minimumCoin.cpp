#include <bits/stdc++.h>
using namespace std;

// In the coin problem, a natural recursive problem is as follows: what
// is the smallest number of coins required to form a sum x? You're given a set of coins

//The essential property of solve is that its values can be recursively calculated
// from its smaller values. The idea is to focus on the first coin that we choose for
// the sum.

// We recursively calculate the minimum number of coins and use memoization, select the first coin at the curr stage
// and get the minimum coin from remaining sum
// we can use a coin any number of times
int miniCoin(std::vector<int>& coins, int x,std::vector<int>&xvalues, int&calls){
    calls++;
    if(x < 0) return 1e9+7;
    if(x==0) return 0;

    if(xvalues[x] != -1) return xvalues[x];

    int mini=INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int val;
        if(x-coins[i] < 0 || xvalues[x-coins[i]] == -1){   // DP to calculate
            val = miniCoin(coins, x-coins[i], xvalues, calls);
        }else{
            val = xvalues[x-coins[i]];
        }
        mini = std::min(mini, val);
    }
    return xvalues[x] = mini+1; // this memoization makes the program billion times faster;
}

// Alternative Solution to the problem which is preferred as well is:
int miniCoin1(std::vector<int>& coins, int x, vector<int>&xvalues){
    xvalues[0] = 0;
    for(int i=1; i <= x; ++i){
        xvalues[i] = INT_MAX;
        for(auto& c:coins){
            if(i-c>=0){
                xvalues[i] = std::min(xvalues[i], xvalues[i-c]+1);
            }
        }
    }
    return xvalues[x];
}


// Here is the followup to the above problem where we'll be finding the number of solutions
// to the problem,
int num_solutions(std::vector<int>&coins, int x, std::vector<int>&xvalues){
    if(x<0) return 0;
    if(x==0) return 1;

    // if(xvalues[x] != -1) return xvalues[x];

    int solutions = 0;
    for(int i=0; i<coins.size(); ++i){
        if(x - coins[i] >=0 && xvalues[x-coins[i]] != -1){
            solutions += xvalues[x-coins[i]];
        }else{
            solutions += num_solutions(coins, x-coins[i], xvalues);
        }
    }
    return xvalues[x] = solutions;
}

// Here's the iterative approach to solve the number of solutions
int num_solutions1(std::vector<int>&coins, int x, std::vector<int>&xvalues){
    xvalues[0] = 1;
    for(int i=1; i<=x; ++i){
        xvalues[i] = 0;
        for(auto& c:coins){
            if(i-c >= 0){
                xvalues[i] += std::max(0, xvalues[i-c]);
            }
        }
    }
    return xvalues[x];
}

int main(){
    
    // int numcoins; cout<<"Numberr of coin: "; cin >> numcoins;
    int __c;
    std::vector<int> __coins = {1, 3, 4};
    // while(numcoins-->0){
    //     cin >> __c;
    //     __coins[numcoins] = __c;
    // }

    int x; cout << "Give the sum to be form: "; cin >> x;
    std::vector<int> xValues(x+1, -1);
    int calls=0;

    auto start = std::chrono::high_resolution_clock::now();
    // int reqCoins = miniCoin(__coins,x, xValues, calls);
    int reqCoins = num_solutions1(__coins, x, xValues);
    cout << "Here are the number of coins required: " << reqCoins << " \n";
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    std::cout << "time taken to execute program : " << duration << " \n";
    std::cout << "number of function calls : " <<calls << " \n";
}