#include <bits/stdc++.h> 
using namespace std;

//You are given an array/list ARR consisting of N integers. Your task is to find 
//all the distinct triplets present in the array which adds up to a given number K.
// elements need not be distinct

//An array is said to have a triplet {ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three 
// indices i, j and k such that i!=j, j!=k and i!=j and ARR[i] + ARR[j] + ARR[k] = 'K'.

//Time complexity is O(n^2);
vector<vector<int>> findTriplets(vector<int>arr, int n, 
	int K) {
	std::sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	std::set<tuple<int, int, int>> st;

	for(int i=0; i<n-2; ++i){
		int f = i+1, l=n-1;

		while(f<l){
			int sum = arr[i]+arr[f]+arr[l];
			if(sum==K){
				st.insert(make_tuple(arr[i], arr[f], arr[l]));
				l--;
				f++;
			}
			else if(sum > K) l--;
			else f++;
		}
	}
	// int first=0, last = n-1;
	// while(first < last){
	// 	int sum = arr[first]+arr[last];
	// 	for(int it=first+1; it<last; ++it){
	// 		if(sum+arr[it] == K){
    //            	st.insert(std::make_tuple(arr[first], arr[it], arr[last]));
    //         }
	// 	}
	//   last--;
	// }
	
	for(auto& e:st){
          ans.push_back({std::get<0>(e),std::get<1>(e),std::get<2>(e)});
        }
	// st.clear();
	return ans;
}