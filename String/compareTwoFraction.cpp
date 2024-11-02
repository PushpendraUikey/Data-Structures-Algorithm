#include <iostream>
#include <regex>
using namespace std;

/*
Here is the algorithm to compare two fractions which are given as 
strings
*/

class Solution {
  public:
    string compareFrac(string str) {
            int a{0} , b{0} , c{0} , d{0};
            // string p, q, r, s;
            bool a1=true, b1=false,c1=false,d1=false;
            
            string ans ="";
            
        int len = str.length();
        int i{0};
        while(i < len){
            if(a1){
                if(str[i]=='/'){
                    a1 = false;
                    b1 = true;
                    i++;
                    continue;
                }
                a = a * 10 + (str[i] - '0');
                i++;
            }
            else if(b1){
                if(str[i] == ','){
                    b1 = false;
                    c1 = true;
                    i++;
                    continue;
                }
                b = b * 10 + (str[i]- '0');
                i++;
            }
            else if(c1){
                if(str[i]==' '){
                    i++;
                    continue;
                }
                if(str[i] == '/'){
                    c1 = false;
                    d1 = true;
                    i++;
                    continue;
                }
                c = c * 10 + (str[i] - '0');
                i++;
            }
            else if(d1){
                d = d * 10 + (str[i] - '0');
                i++;
            }
        }
        
        if(( 1.0*a/b) ==(1.0*c/d)) ans = "equal";
        else if((1.0 * a/b) > (1.0 * c/d)) ans = ans + to_string(a) + '/' + to_string(b);
        else ans = ans + to_string(c) + '/' + to_string(d);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends