#include<bits/stdc++.h>
#define PI 3.14 // macro, donot allocate memory;

using namespace std;

int g_var = 12344; // It is a global variable, can be accessed by any fun, and updated by any fun in the file.

inline int getMax(int &a, int &b){
    return (a>b) ? a : b;
}   // If a function is of one single line, then compiler agrees to make it an inline function, i.e. no need to call the function, whenever called
    // then this inline function will replace it's code block in the place where it was called.

int main(){
    int row, col; cin >> row >> col;

    int** arr = new int*[row];
    for(int i{0}; i<row; i++){
        arr[i] = new int[col];  // Array's name in itself is a pointer.
    }

    for(int i{0}; i<row; i++){
        for(int j{0}; j < col; j++){
            cin >> arr[i][j];
        }
    }

    cout << endl;

    for(int i{0}; i<row; i++){
        for(int j{0}; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Realeasing memory

    for(int i{0}; i<row; i++){
        delete [] arr[i];
    }
    delete []arr;

    // creating a jagged array;

    int**jaggedArray = new int*[3];
    int arrsize[] = {4, 5, 3};

    for(int i{0}; i<3; i++){
        jaggedArray[i] = new int[arrsize[i]];
    }
    int value{0};
    for(int i{0}; i<3; i++){
        for(int j{0}; j<arrsize[i]; j++){
            jaggedArray[i][j] = ++value;
        }
    }

    cout << endl;
    for(int i{0}; i<3; i++){
        for(int j{0}; j<arrsize[i]; j++){
            cout << jaggedArray[i][j] << ' ';
        }
        cout << endl;
    }

    delete [] jaggedArray;

}