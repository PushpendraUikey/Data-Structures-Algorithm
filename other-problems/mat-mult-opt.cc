#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define SIZE 100
static double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], D[SIZE][SIZE];


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
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            D[i][j] = C[j][i];
        }
    }
 
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            for(int k=0; k<SIZE; k++){
                cout << 0 << ' ' << &A[i][j] << endl;
                cout << 0 << ' ' << &B[i][k] << endl;
                cout << 0 << ' ' << &D[j][k] << endl;
                A[i][j] = A[i][j] + B[i][k]*D[j][k];
                cout << 1 << ' ' << &A[i][j] << endl;
            }
        }
     }
}

// ./dineroIV -l1-usize 8k -l1-ubsize 16 -l1-uwalloc a -l1-uwback a -l1-uccc -l1-uassoc 2 -informat d < ../d4-traces/tex.din