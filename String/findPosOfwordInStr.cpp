#include <bits/stdc++.h>
using namespace std;

/// @brief          to find the indices of word in the diary in the given booklet
/// @param booklet  this the book where you've to check for words
/// @param diary    this contains words whose indices to find(We've to find all the indices of word in 'booklet')
/// @return         indices found in sorted orderd

vector<int> searchWords(string booklet, vector<string> &diary) {
  vector<int> ans;

  for (int i = 0; i < diary.size(); i++){
	  int ind = booklet.find(diary[i]);

	  while(ind != std::string::npos){

		  ans.push_back(ind);

		  ind = booklet.find(diary[i], ind+1);
	  }
  }
  sort(ans.begin(), ans.end());

  return ans;
}
