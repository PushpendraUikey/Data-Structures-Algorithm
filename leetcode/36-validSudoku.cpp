#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<9; i++) {
            set<char> st;
            for(int j=0; j<9; j++){
                char ch = board[i][j];
                if(ch != '.'){
                    if(st.count(ch) > 0) return false;
                    st.insert(ch);
                }
            }
        }

        for(int j=0; j<9; j++){
            set<char> st;
            for(int i=0; i<9; i++){
                char ch = board[i][j];
                if( ch != '.'){
                    if(st.count(ch) > 0) return false;
                    st.insert(ch);
                }
            }
        }

        for(int i=0; i<9; i++) {
            set<char> st;

            for(int j=0; j<9; j++) {
                char ch = board[3*(i/3) + j/3][(3*i+j%3)%9];
                if(ch != '.'){
                    if(st.count(ch) > 0) return false;
                    st.insert(ch);
                }
            }
        }
        return true;
    }
};