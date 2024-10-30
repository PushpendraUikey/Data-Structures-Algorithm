#include<bits/stdc++.h>

using namespace std;

//  If all the elements of the array are twice occuring except 1

int findUnique(int *arr, int size)
{
    int unique = 0;
    for(int i=0; i<size; i++){
        unique = unique ^ arr[i];   // XOR of same elements gives  0 and XOR of 0 and ele gives element.
    }
    return unique;
    
}