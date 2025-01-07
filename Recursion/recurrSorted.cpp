#include<bits/stdc++.h>

using namespace std;

bool isSorted(int *arr, int s){
    if(s==0 | s==1) return true;

    if(arr[0] > arr[1]) return false;
    else return isSorted(arr+1, s-1);
}

int getSum(int *arr, int s){
    if(s==0) return 0;
    else return (arr[0]+getSum(arr+1, s-1));
}

bool isPresent(int * arr, int s, int &k){
    if(s == 0) return false;
    if( arr[0] == k) return true;
    else return isPresent(arr+1, s-1, k);
}

bool binary_search(int*arr, int s, int e, int& t){
    if(s > e) return false;
    int m = s + (e-s)/2;
    if(arr[m] == t) return true;
    else if(arr[m] < t){
        return binary_search(arr, m+1, e, t);
    }
    else return binary_search(arr,s, m-1, t);
        
}

string reverse(string s, int i, int j){
    if(i>j) return s;
    else{
        swap(s[i], s[j]);
        return (reverse(s,i+1, j-1));
    }
}

bool check_palindrome(string s, int i, int j){
    if(i>j) return true;
    if(s[i] != s[j]) return false;
    else{
        return (check_palindrome(s,i+1, j-1));
    }
}

// function to return pow(a,b);
long long rec_Power(int a, int b){
  
    if(a==0) return 0;
    if(b == 0) return 1;
    if(b == 1) return a;

    long long temp1 = rec_Power(a, b/2);

    if(b & 1){
        return (temp1 * temp1 * a);
    }else{
        return (temp1 * temp1);
    }
}

void bubbleSort(int * arr, int n){
    if(n ==0 | n==1 ) return ;

    for(int i{0}; i<n; i++){
        if(arr[i] > arr[n-1]) swap(arr[i], arr[n-1]);
    }
    bubbleSort(arr, n-1);
}

int main(){
    int arr[] = { 34, 89, 90, 100, 189, 800};
    int s = 6;
    int k = 9;
    int t = 18;

    if(isSorted(arr,s)) cout << "Sorted\n" ;
    else cout << "Not Sorted\n";

    cout << "Sum of the array through recurssion is: " << getSum(arr, s) << endl;

    if(isPresent(arr,s, k)) cout << k << " is present in the array. " << endl;
    else cout << k << " is not present in the array. " << endl;

    if(binary_search(arr,0, s, t)) cout << t << " is present in the array.\n";
    else cout << t << " is not present in the array.\n";

    string str = "abrakadabrashakalakaboomboom";
    int i{0}, j = str.length()-1;

    cout << "Reverse of the given string is: " << reverse(str,i, j) << endl;

    string palind = "abcdedcba";
    j = palind.length()-1;
    if(check_palindrome(palind, i, j)) cout <<palind<<" is a palindrome. " << endl;
    else cout <<palind<< " is not a palindrome " << endl; 

    cout << "3 power 20 is " << rec_Power(3, 20) << endl;

    int temp[] = {89, 234, 19, 182, 38, 1478, 19, 89, 474, 1721, 52, 67, 90, 99, 45};
    int n = sizeof(temp)/sizeof(temp[0]);
    bubbleSort(temp, n);
    for(int i{0}; i<n; i++){
        cout << temp[i] << " " ;
    }
    cout << endl;
}