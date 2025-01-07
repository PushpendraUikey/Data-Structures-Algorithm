#include<bits/stdc++.h>
using namespace std;

/*
Algorithm of merge-sort:    Divide and Conquer
*/

void print(int A[], int n){        
        for(int i=0; i < n; i++){
            cout<<A[i]<<' ';
        }
        cout << endl;
}

void merge(int arr[], int U[], int p, int V[], int q){
    // cout << "-------------------------------------------" << endl;
    // cout << "p : " << p <<endl;
    // print(U,p);
    // cout << "q : " << q << endl;
    // print(V,q);
    int Su = 0, Sv=0;
    for(int i{0}; i < p+q; i++){
        if(Su<p && Sv<q){
            if(U[Su] < V[Sv]){
                arr[i] = U[Su]; Su++;
            }else{
                arr[i] = V[Sv]; Sv++;
            }
        }else if( Su < p){
            arr[i] = U[Su]; Su++;
        }else {
            arr[i] = V[Sv]; Sv++;
        }
    }
}

void mergeSort(int arr[], int n){
    // cout << "-------------------------------------------" << endl;
    // cout << "n : "<< n << endl;
    if( n <= 1) return; // base case
   
    int p = n/2, q = n - n/2;
    int U[p], V[q];

    for(int i{0}; i<p; i++){
        U[i] = arr[i];
    }
    for(int i{0}; i<q; i++){
        V[i] = arr[i+p];
    }

    // left mergesort
    mergeSort(U, p);
    // right mergesort
    mergeSort(V, q);

    merge(arr,U,p, V,q);
}

int main(){
    int temp[] = {89, 234, 19, 182, 38, 1478, 19, 89, 474, 1721, 52, 67, 90, 99, 45};
    int n = sizeof(temp)/sizeof(temp[0]);
    mergeSort(temp, n);
    for(int i{0}; i<n; i++){
        cout << temp[i] << " " ;
    }
    cout << endl;

    // int tem[] = {3,2,1};
    // mergeSort(tem, 3);
}