#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define SIZE 500
static double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];




int main(){

    for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
        A[i][j] = 0;
        if(i==j){
            B[i][j] = 2;
        }else{
            B[i][j] = 0;
        }
        if(i==0){
            C[i][j] = i;
        }else{
            C[i][j] = 0;
        }
    }
 }
//     auto start = high_resolution_clock::now();
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            for(int k=0; k<SIZE; k++){
                A[i][j] = A[i][j] + B[i][k]*C[k][j];
            }
        }
     }
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // std::cout << duration.count() << std::endl;
}