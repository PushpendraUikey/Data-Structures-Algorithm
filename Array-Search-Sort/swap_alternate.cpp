#include<iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void swap_alternate(int a[],int n){
    int j{0};
    for(int i{0}; i<n && j<n/2; i+=2, j++){
        swap(a[i],a[i+1]);
    }
}
int main(){
    int length; cin >> length;
    int arr[length];
    for(int i{0}; i<length; i++) cin >> arr[i];
    swap_alternate(arr,length);
    for(int k{0}; k < length; k++){
        cout << arr[k] << ' ';
    }
    cout << "\n";
}