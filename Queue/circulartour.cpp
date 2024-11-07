#include<bits/stdc++.h>
using namespace std;

/*
Famous truck-petrolPump problem, in which we've to find the starting point to move truck such that 
we can cover the entire track. There are petrolPumps on the way which has some amount of petrol and 
tells the succeeding distance to move to get the next petrolPump. Assuming each unit distance causes 
one unit petrol burn find the optimal start such that all the petrolPumps are covered.
*/

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for(int i=0; i<n; i++){
           balance += p[i].petrol - p[i].distance;
           if(balance < 0){     /// initial beginning wasn't good
               deficit += balance;  /// keep accumulating the deficit
               start = i+1;     /// let's try to start from next station
               balance = 0;
           }
       }
       if(deficit + balance >= 0)   /// still petrol left or it is exhausted then start gives optimal starting point
            return start;
        else return -1; // we're not able to cover each petrol pump
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
