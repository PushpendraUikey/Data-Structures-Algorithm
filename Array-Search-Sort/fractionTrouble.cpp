

/*
You are given a reduced fraction in the form n/d, where gcd(n, d) = 1 and n ≤ d. You have to 
find the largest possible fraction that is strictly less than n/d, also in reduced form (i.e., 
the numerator and denominator must be coprime), and where the numerator is less than or 
equal to the denominator.  In case multiple such fractions exist, the one with the highest 
possible fraction value (just below n/d) should be returned.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<int>LargestFraction(int n, int d){
	    double value=(double)n/(double)d;
	    double current_diff;
	    double overall_diff=(double)INT_MAX;
	    vector<int> frac;
	    int first,second;
	    
	    for(int i=1;i<=10000;i++){
	        int num=(int)(i*value);
	       // cout<<num<<endl;
	        if((double)num/(double)i==value) num--;
	        current_diff=value-(double)num/(double)i;
	        if(overall_diff>current_diff){
	            overall_diff=current_diff;
	            first=num;
	            second=i;
	        }
	        
	    }
	    frac.push_back(first);
	    frac.push_back(second);
	    
	    return frac;
	}
};