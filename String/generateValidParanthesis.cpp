#include<bits/stdc++.h>
using namespace std;

// Famous Catalan Number problem!
// non optimal solution to paranthesis generation of n valid brackets,

void generate(string& par, stack<char>&st1, stack<char>&st2,
    vector<string>&paranthesis){
    
    if(st1.empty()&&st2.empty()){
        paranthesis.push_back(par);
        return;
    }
    
    if(!st1.empty()){
        char ch = st1.top();
        st1.pop();
        par.push_back(ch);
        generate(par, st1, st2, paranthesis);
        st1.push(ch);
        par.pop_back();
    }
    if(st1.size() < st2.size()){
        char ch = st2.top();
        st2.pop();
        par.push_back(ch);
        generate(par, st1, st2, paranthesis);
        st2.push(ch);
        par.pop_back();
    }
}
void printParantheses(int n) {
    
    vector<string> paranthesis;
    string par = "";
    stack<char> st1, st2;
    for(int i=0; i<n; i++){
        st1.push('{');
        st2.push('}');
    }
    generate(par, st1, st2, paranthesis);

    for(int i=0; i<paranthesis.size(); i++){
        cout << paranthesis[i] << endl;
    }
}

int main(){
    int n; std::cout << "Give number for catalan: "; cin >> n;
    printParantheses(n);
}