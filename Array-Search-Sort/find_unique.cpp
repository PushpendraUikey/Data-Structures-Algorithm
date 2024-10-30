#include<iostream>
using namespace std;

/*
 from array of size 2m+1, you have to find one element which is unique, others m being twice in the list.
*/

// bool notfound(int *arr, int size, int i,int num){
//     for(int k{0}; k<size; k++){
//         if(k==i) continue;
//         if(arr[k]==num) return false;
//     }
//     return true;
// }
// int findUnique(int* arr, int size){
//     for(int k{0}; k<size; k++){
//         if(notfound(arr,size,k,arr[k]))
//             return arr[k];
//     }
//     return 0;
// }



// Much more optimized solution, Using XOR(^) operation
int findUnique(int* arr, int size){
    int ans = 0;
    for(int k{0}; k<size; k++){
        ans = ans^arr[k];       // a^a cancels out each other and a^0 = a, so if we do XOR of all elements then we'll find out the unique one
    }
    return ans;
}

int main(){
    int l; cin >> l;
    int arr[l]; 
    for(int k{0}; k<l; k++) cin >> arr[k];
    cout << findUnique(arr,l) << endl;
}