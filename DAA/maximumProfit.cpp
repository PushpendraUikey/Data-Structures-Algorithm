#include <bits/stdc++.h>
using namespace std;

// You've been given an array with price of stock at each day, you've to maximize the profit
// you can sell only after you buy the share!

int maxProfit(std::vector<int>& price){
    int n = price.size();
    std::vector<int> diff(n, 0);
    for(int i=1; i<n; i++){
        diff[i] = price[i] - price[i-1];
    }

    // now problem reduces to find the maximum subarray sum to find the maximum profit
    int sum =0, best = 0;
    for(int i=1; i<n; i++){
        sum = std::max(diff[i], sum + diff[i]);
        best = std::max(best, sum);
    }

    return best;
}

// Here's the better greedy algorithm to calculate max profit.  [It is actually a better solution.]

int maxProfit_Greed(std::vector<int>&price){
    int n = price.size();

    int maxProfit = 0;
    int minPrice = price[0];

    for(int i=0; i<n; i++){
        maxProfit = std::max(maxProfit, price[i]-minPrice); // efficiently keep checking the maxProfict change.
        minPrice = std::min(minPrice, price[i]);    // Keep track of minimum Price.
    }

    return maxProfit;
}

int main(int argc, char *argv[]){

    std:: cout << " Enter the nubmer of days and price of each day \n";
    int n; cin >> n;

    std::vector<int> stock(n,0);
    int va;
    for(int i=0; i<n; i++){
        cin >> va;
        stock[i] = va;
    }
    std::cout << "Maximum profit that can be earned is : " << maxProfit(stock) << std::endl;
    std::cout << "Maximum profit that can be earned is : " << maxProfit_Greed(stock) << std::endl;
}