#include<bits/stdc++.h>
using namespace std;

/*
an element is present in the array more than SIZE/2 times, we've to find that element
*/

class Solution{
  public:
    //   Function to find majority element in the array
    //   a: input array
    //   size: size of input array

    //////////////////////////////// Boyer Moore Algorithm for majority elements ///////////////////////////////////

    int majorityElement(int a[], int size)
    {   
        int candidate = -1;
        int count = 0;
        
        for(int i{0}; i<size; i++){
            if(count == 0){
                candidate = a[i];
                count++;
            }else if( a[i] == candidate ){
                count++;
            }else{
                count--;
            }
        }

        count = 0;
        for(int i{0}; i< size; i++){
            if(a[i] == candidate) count++;
        }
        
        if( count > size/2 ){
            return candidate;
        }else{
            return -1;
        }
    }
};

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
