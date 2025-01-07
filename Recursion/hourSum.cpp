#include<bits/stdc++.h>
using namespace std;

// given array is of 6 * 6 

int hourglassSum(vector<vector<int>> arr) {
    int sum = -10000;
    
    /* Hourglass looks like and H in matrix like the following */
    /*
    a b c
      d
    e f g
    */
    for(int i = 0; i<4; i++){
        int temp = 0;
        for(int k=0; k<4; k++){
            temp = 0;
            for(int j=k; j<k+3; j++){
                temp += arr[i][j];
                temp += arr[i+2][j];
            }
            temp += arr[i+1][k+1];
        
            if(temp>sum) sum = temp;
        }
    }
    return sum;
}