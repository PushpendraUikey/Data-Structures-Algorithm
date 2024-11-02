#include<bits/stdc++.h>
using namespace std;

// Intuition:
// The problem asks us to find the smallest substring in s that contains all characters of p, including duplicates. This suggests that we need to:
// 1. Keep track of the characters we need (from p)
// 2. Scan through s to find these characters
// 3. Minimize the window size that contains all required characters

// The sliding window technique is ideal for this type of problem, as it allows us to efficiently expand and contract our search area in s.

// Approach:
// 1. Character Frequency Map:
//    We use a vector `map` to store the frequency of characters in p. This serves two purposes:
//    - It tells us which characters we need to find
//    - It keeps track of how many of each character we still need

// 2. Sliding Window:
//    We use two pointers, `start` and `end`, to define our current window in s.

// 3. Counter:
//    We use a `counter` variable to keep track of how many characters we still need to find. It's initially set to p.size().

// 4. Window Expansion:
//    We move the `end` pointer to the right, including more characters in our window:
//    - If we find a needed character (map[s[end]] > 0), we decrement the counter
//    - We always decrement the frequency of the current character in our map

// 5. Window Contraction:
//    When we've found all needed characters (counter == 0), we try to minimize the window:
//    - We update our answer if the current window is smaller than the previous best
//    - We move the `start` pointer to the right, removing characters from our window
//    - If we remove a needed character (map[s[start]] becomes > 0), we increment the counter

// 6. Repeat:
//    We continue this process of expanding and contracting until we've scanned all of s

// Time Complexity: O(|s|)
// - We scan the string s only once with our two pointers
// - Each character is added to the window once and removed from the window at most once
// - All operations inside the loops are O(1)

// Space Complexity: O(1)
// - We use a fixed-size vector `map` of 128 elements (for ASCII characters)
// - The space used does not grow with the input size
// - We only use a few additional integer variables

// Additional Notes:
// - This solution is highly efficient as it makes a single pass through the string s
// - The use of a fixed-size frequency array allows for O(1) lookups and updates
// - The sliding window technique ensures we don't need to rescan parts of s we've already seen

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.(along with frequency)
    string smallestWindow (string s, string p)
    {
        vector<int> map(128,0);
        for(char c : p) map[c]++;
        
        int start = 0, end = 0, minStart = 0, minLen = INT_MAX, counter = p.size();
        
        while(end < s.size()){
            if(map[s[end]] > 0) // if occurnace of the char exist
                counter--;
            map[s[end]]--;  // decrease the frequency of occurrence
            end++;
            
            while(counter == 0){
                if(end - start < minLen){
                    minStart = start;
                    minLen = end - start;
                }
                
                map[s[start]]++;
                if(map[s[start]] > 0)
                    counter++;
                
                start++;
            }
        }
        
        return minLen == INT_MAX ? "-1" : s.substr(minStart, minLen);
    }
};