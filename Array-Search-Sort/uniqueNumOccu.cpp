#include<iostream>
using namespace std;

// tell if the occurrence of each no. in the array is unique.(Two elements can't have the same no of occurances)

bool hasAppeared(int* arr,int* o,int s, int e){
    for(int i{0}; i<s; i++){
        if(arr[i]==e) {
            o[i]++;
            return true;
        }
    }
    return false;
}

bool UniqueOccurrance(int* arr, int size){
    int occur[size];
    for(int i{0};i<size; i++){
        occur[i] = 0;
    }
    for(int k{0}; k < size; k++){
        if(hasAppeared(arr,occur,k,arr[k])) continue;
        else{
            occur[k]++;
        }
    }

    int j{0};
    while(j<(size-1)){
        int ans{occur[j]};
        for(int i{j+1}; i<size; i++){
            if(occur[i]==0) continue;
            int t = ans^occur[i];
            if(t==0) return false;
        }
        j++;
    }

    // int i{0};
    // while(true){
    //     if(i==(size-1)) return true;
    //     if(occur[i]==0) continue;
    //     int E = occur[i];
    //     for(int j{0}; j<size; j++){
    //         if(j==i) continue;
    //         if(occur[j] == E) return false;
    //     }  
    //     i++;
    // }
    return 1;
}

int main(){
    int l; cin >> l;
    int arr[l];
    for(int i{0}; i<l; i++) cin >> arr[i];
    if(UniqueOccurrance(arr,l)) cout << "Indeed the elements of the arrays are of unique occurrance." << endl;
    else cout << "Elements of the array are not of unique occurrance." << endl;

}



// Learning of the question is that, you had to find out the occurrances of letters and perform XOR 