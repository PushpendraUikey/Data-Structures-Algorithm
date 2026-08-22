#include <bits/stdc++.h>
using namespace std;

class Solution {
    string addstring(string&n1, string&n2, int shift) {
        if(n1.empty()) return n2;
        string ans = "";
        ans.reserve(n1.size()+1);

        ans = n1.substr(n1.size()-shift);
        int i=n1.size()-1-shift;
        int j=n2.size()-1;
        int rem = 0;

        while(i>=0 && j>=0) {
            int v1 = (n1[i]-'0');
            int v2 = (n2[j]-'0');
            i--; j--;
            int res = v1 + v2 + rem;
            rem = res/10;
            res = res%10;
            ans = to_string(res) + ans;
        }

        while(i>=0) {
            int v1 = (n1[i]-'0');
            int res = v1 + rem;
            rem = res/10;
            res = res%10;
            ans = to_string(res) + ans;
            i--;
        }

        while(j>=0) {
            int v2 = (n2[j]-'0');
            int res = v2 + rem;
            rem = res/10;
            res = res%10;
            ans = to_string(res) + ans;
            j--;
        }
        if(rem>0) ans = to_string(rem) + ans;
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        string ans = "";
        int n1 = num1.length();
        int n2 = num2.length();
        ans.reserve(n1*n2);

        for(int i=n1-1; i>=0; i--) {
            string curr = "";
            curr.reserve(n2+1);
            int v1 = (num1[i] - '0');
            int rem = 0;
            for(int j=n2-1; j>=0; j--) {
                int v2 = (num2[j] - '0');
                int res = v1 * v2 + rem;
                rem = res / 10;
                int val = res%10;
                curr = to_string(val) + curr;
            }
            if(rem > 0) curr = to_string(rem) + curr;
            ans = addstring(ans, curr, n1-i-1);
        }

        return ans;
    }
};


class Solution {
    // We remove 'shift' because we will handle zeroes before calling this.
    string addstring(string& n1, string& n2) {
        if(n1.empty()) return n2;
        
        string ans = "";
        int i = n1.size() - 1;
        int j = n2.size() - 1;
        int rem = 0;

        // Using push_back for O(1) appending
        while (i >= 0 || j >= 0 || rem > 0) {
            int v1 = (i >= 0) ? (n1[i] - '0') : 0;
            int v2 = (j >= 0) ? (n2[j] - '0') : 0;
            
            int res = v1 + v2 + rem;
            rem = res / 10;
            res = res % 10;
            
            ans.push_back(res + '0'); // Fast char conversion
            i--; j--;
        }

        // Because we appended, the string is backwards. Reverse it.
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
    
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        string ans = "";
        int n1 = num1.length();
        int n2 = num2.length();

        for (int i = n1 - 1; i >= 0; i--) {
            string curr = "";
            int v1 = (num1[i] - '0');
            int rem = 0;
            
            for (int j = n2 - 1; j >= 0; j--) {
                int v2 = (num2[j] - '0');
                int res = v1 * v2 + rem;
                rem = res / 10;
                int val = res % 10;
                curr.push_back(val + '0');
            }
            if (rem > 0) curr.push_back(rem + '0');
            
            // Reverse current row before padding with zeroes
            std::reverse(curr.begin(), curr.end());
            
            // Manually pad zeroes based on the tens position (shift)
            int shift = (n1 - 1) - i;
            for (int k = 0; k < shift; k++) {
                curr.push_back('0');
            }
            
            ans = addstring(ans, curr);
        }

        return ans;
    }
};


class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size();
        int n2 = num2.size();
        
        // The maximum length of the product is n1 + n2
        vector<int> pos(n1 + n2, 0); 
        
        // Multiply each digit and accumulate the results directly into pos array
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                // The indices where this multiplication belongs
                int p1 = i + j;       // Tens place (Carry)
                int p2 = i + j + 1;   // Units place
                
                // Add the new multiplication to whatever was already at the units place
                int sum = mul + pos[p2]; 
                
                // Place the unit digit
                pos[p2] = sum % 10;
                
                // Add the carry to the tens place
                pos[p1] += sum / 10; 
            }
        }
        
        // Convert the pos array back into a string
        string ans = "";
        for (int p : pos) {
            // Skip leading zeroes (the first element might be 0 if there was no final carry)
            if (!(ans.length() == 0 && p == 0)) {
                ans.push_back(p + '0');
            }
        }
        
        return ans;
    }
};