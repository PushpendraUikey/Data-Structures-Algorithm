#include <bits/stdc++.h>
using namespace std;

// Traceback to the actual alignment is remaining
// Reason for different matrix buildup is still not known to me

int recursiveAlignmentCost(string&s, string&t, int i, int j, int&alpha, int&delta,
    std::vector<std::vector<int>>&opt){

        // Terminating condition 
        if(i==0 || j==0){
            return opt[i][j];
        }

        int rprev, cprev, dprev;

        // Gaps!
        if(opt[i-1][j] != -1){
            rprev = opt[i-1][j] + delta;
        }else{
            rprev = recursiveAlignmentCost(s, t, i-1, j, alpha, delta, opt) + delta;
        }
        if(opt[i][j-1] != -1){
            cprev = opt[i][j-1] + delta;
        }else{
            cprev = recursiveAlignmentCost(s, t, i, j-1, alpha, delta, opt) + delta;
        }

        // match - mismatch
        if(opt[i-1][j-1] != -1){
            dprev = opt[i-1][j-1];
        }else{
            dprev = recursiveAlignmentCost(s, t, i-1, j-1, alpha, delta, opt);
        }
        if(s[i-1] != t[j-1]){
            dprev += alpha;
        }

    return opt[i][j] = std::min(dprev, std::min(cprev, rprev));
}

// delta is for gap and alpha is for incorrect match.
void alignementCost(string& s, string& t, int alpha, int delta){
    int m = s.length();
    int n = t.length();

    std::vector<std::vector<int>> opt(m+1, std::vector<int>(n+1,-1));
    for(int i=0; i<=n; i++){
        opt[0][i] = i*delta;
    }
    for(int j=0; j<=m ; j++){
        opt[j][0] = j*delta;
    }
    opt[0][0] = 0;

    // Recursive implementation
    cout << "Total minimum cost of alignement between string '" << s << "' and '" << t << "' is: " << recursiveAlignmentCost(s,t,m, n, alpha, delta, opt) << "\n";

    cout << " Returned matrix is: \n";
    for(int i=0; i<=m; i++){
        cout << "[ "; 
        for(int j=0; j<=n ;j++){
            cout << opt[i][j] << " ";
        }
        cout << "]\n";
    }


    // Iterative implementation
    int rprev, cprev, dprev;
    for(int i=1; i<=m;  i++){
        for(int j=1; j<=n; j++){
            rprev = opt[i-1][j]+delta;
            cprev = opt[i][j-1]+delta;
            dprev = opt[i-1][j-1];
            if(s[i-1] == t[j-1]) dprev += alpha;
            opt[i][j] = std::min(dprev, std::min(cprev, rprev));
        }
    }
    cout << "Total minimum cost of alignement between string '" << s << "' and '" << t << "' is: " << opt[m][n] << "\n";

    cout << " Returned matrix is: \n";
    for(int i=0; i<=m; i++){
        cout << "[ "; 
        for(int j=0; j<=n ;j++){
            cout << opt[i][j] << " ";
        }
        cout << "]\n";
    }
}

void spaceEfficientAlignment(string&s, string&t, int alpha, int delta){
    int m = s.length();
    int n = t.length();
    std::vector<std::vector<int>> opt(m+1, std::vector<int>(2,0));  // m X 2 matrix
    int itr;
    int cprev, rprev, dprev;
    for(itr=0; itr<=m; itr++){
        opt[itr][0] = delta * itr;      // Column 0 of A
    }
    for(int j=1; j<=n; j++){
        opt[0][1] = j * delta;      // corresponds to entry A[0][j]
        for(itr=1; itr<=m; itr++){
            cprev = opt[itr-1][1]+delta;
            rprev = opt[itr][0] + delta;
            dprev = opt[itr-1][0];
            if(s[itr-1] != t[itr-1]) dprev += alpha;

            opt[itr][1] = std::min(dprev, std::min(cprev, rprev));
        }
        for(itr=1; itr<=m; itr++){
            opt[itr][0] = opt[itr][1];  //moving colmn 1 to colmn 0 to make room for nxt iteration
        }
    }
}

int main(int argv, char* argc[]){
    string s, t;
    int a, d;
    cin >> s>> t >> a >> d;
    alignementCost(s, t, a, d);
}
//IITB&Overleaf@pushpendra2023
// Git overleaf integration token: olp_47zMjnWdthylpph7BPi12Tvsq8mK5r3a6cQ9