#include <bits/stdc++.h>
using namespace std;

// following solution solves the mathematical puzzle: Josephus problem
// n people are sitting in circle and starting with 0th person, everyone kills k'th person
// from his term,


int josephus1(int n, int k){
    if(n==1) return 0;
    return ( josephus1(n-1, k)+k ) % n;  //This is for zero based indexing
}


#include <stdio.h>
int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) 
       is adjusted because the recursive call 
       josephus(n - 1, k) considers the original 
       position k%n + 1 as position 1 */
    return (josephus(n - 1, k) + k-1) % n + 1;  // This is for 1 based indexing
}

int main()
{
  int n = 14;
  int k = 2;
  printf("The chosen place is %d\n", 
                 josephus(n, k));
  return 0;
}

int main(){
    int n; cout << "How many people are there: "; cin >> n;
    int k; cout << "Which indexed position from himself a person has to kill: "; cin >> k;
    cout << "Survival of the puzzle is: " << josephus1(n, k) << endl;
}