#include <bits/stdc++.h>
using namespace std;

// Following is the solution to the problem "Tower of Hanoi!"
void TOH(int n, char first, char middle, char destination){
    if(n<=0){
        cout << "Error!" << endl;
        return;
    }else if(n==1){
        cout << "Move 1 from " << first << " to " << destination << endl;
        return; 
    }
    TOH(n-1, first, destination, middle);
    cout << "move " << n << " from " << first << " to " << destination << endl;
    TOH(n-1, middle, first, destination);
}

int main(){
    int n; cout << "Number of disk you have in tower A: "; cin >> n;
    cout << "This is how TOH will be solved!\n";

    TOH(n, 'A', 'B', 'C');
}