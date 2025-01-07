#include<bits/stdc++.h>

using namespace std;

void print(int A[], int n){        
        for(int i=0; i < n; i++){
            cout<<A[i]<<' ';
        }
        cout << endl;
}

int partition( int arr[], int s, int e){
    int pivot = arr[s];
    int cnt {0};
    for(int i{s+1}; i <= e; i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while ( i < pivotIndex && j > pivotIndex ){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if( i < pivotIndex && j > pivotIndex) swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void QuickSort(int * arr, int s, int e){

    if( s >= e ) return;

    int p = partition(arr, s, e);// we partition elements in two side acc to given pivot

    // Left Part sort
    QuickSort(arr, s, p-1);

    // Right part sort
    QuickSort(arr, p+1, e);
}

int main(){
    int temp[] = {89, 234, 19, 182, 38, 1478, 19, 89, 474, 1721, 52, 67, 90, 99, 45};
    int n = sizeof(temp)/sizeof(temp[0]);
    QuickSort(temp, 0, n-1);
    for(int i{0}; i<n; i++){
        cout << temp[i] << " " ;
    }
    cout << endl;

    // int tem[] = {3,2,1};
    // QuickSort(tem, 0, 2);

    // print(tem, 3);
}