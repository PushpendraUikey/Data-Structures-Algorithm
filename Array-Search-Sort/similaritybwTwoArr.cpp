#include <bits/stdc++.h>
using namespace std;
//You have been given two arrays/list ‘ARR1’ and ‘ARR2’ consisting of ‘N’ and ‘M’ integers respectively. 
// Your task is to return the number of 
// elements common to ‘ARR1’ and ‘ARR2’ and the number of elements in the union of ‘ARR1’ and ‘ARR2’.

#include <bits/stdc++.h> 
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	std::set<int> s1, s2;
	// std::pair<int, int> ans;
	int common=0;
	for(auto& x:arr1){
		s1.insert(x);
	}

	for(auto& y:arr2){
		if(s1.count(y)){
			common++;
		}else{
			s2.insert(y);
		}
	}

	return {common, s1.size()+s2.size()};

}