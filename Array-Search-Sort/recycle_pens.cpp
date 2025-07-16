#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You have 'N' empty pens whose refills have been used up. You have 'R' rupees in your pocket. You have two choices of operations that you can perform each time.

1) Recycle 1 empty pen and get 'K' rupees as a reward.

2) Buy 1 refill for 'C' rupees and combine it with 1 empty pen to make one usable pen.

Your task is to find the maximum number of usable pens that you can get.

For example if you have 'N' = 5 , 'R' = 10 , 'K' = 2 , 'C' = 3. You can recycle one pen and get 2 rupees as a reward so you will have a total of 12 rupees. Now you can buy 4 refills and combine it with 4 pens to make it usable. So your answer is 4.
*/

int recyclePens(int n, int r, int k, int c ){

	long long maxi = 0;
	long long recy = 0;
	long long money = 0;
	long long refills = 0;
	long long leftpens = 0;
	long long i = 0, j = n;
	while( i <= j )
	{
		recy = i + (j-i)/2;
		money = r + (long long)recy * k;
		refills = money/c;
		leftpens = n - recy;

		long long usable = min(leftpens, refills);
		maxi = max(maxi, usable);

		if(refills <= leftpens){
			i = recy + 1;
		}else{
			j = recy - 1;
		}
		
	}

	return maxi;
}