#include <bits/stdc++.h> 
using namespace std;

// You are given a string 'S' containing only digits. Your task is to find all 
// possible IP addresses that can be obtained from string 'S' in lexicographical order.
// Note:
// A valid IP address consists of exactly four integers, each integer is between 0 and 255 
// separated by single dots, and cannot have leading zeros except in the case of zero itself.

bool valid(string& segment){
	if(segment.length()>1 && segment[0] == '0'){    // leading zero.
		return false;
	}
	if(segment.length()<1 || segment.length()>3 || std::stoi(segment)>255){
		return false;
	}
	return true;
}
vector<string> generateIPAddress(string s)
{
	// Write your code here
	vector<string> ans;
	int n = s.length();
	if( n < 4 ) return ans;

// exhaust all the possible segments for IP address
	for(int i=1; i<n && i<4; i++){
		for(int j=i+1; j<n && j<i+4; j++){
			for(int k=j+1; k<n && k<j+4; k++){
				string part1 = s.substr(0, i);
				string part2 = s.substr(i, j-i);
				string part3 = s.substr(j, k-j);
				string part4 = s.substr(k);	// Till the end from index k.

				if(valid(part1)&&valid(part2)&&valid(part3)&&valid(part4)){
					string result = part1+"."+part2+"."+part3+"."+part4;
					ans.push_back(result);
				}
			}
		}
	}

	return ans;
}