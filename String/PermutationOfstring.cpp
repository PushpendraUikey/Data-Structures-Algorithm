#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find if given two string, second string contains the permutation of
first string
Return: bool

we've used sliding window techniqu
*/
bool checkEqual(int count[26], int count1[26]){
    for(int i{0}; i<26; i++){
        if(count[i] != count1[i]) return 0;
    }
    return 1;
}
bool checkInclusion(string s1, string s2){      
    // s1 is the substring to check and s2 is the string in which we'll check
    int count[26] = {0};
    
    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count[index]++;
    }

    int i = 0;
    int windowSize = s1.length();
    int count1[26] = {0};

    while( i < windowSize && i < s2.length()) {        // traversing for first window;
        int index = s2[i] - 'a';
        count1[index]++;
        i++;
    }

    if( checkEqual(count, count1)){         // first window me hi permutation mil gya
        return 1;
    }

    while(i < s2.length()){
        int index = s2[i] - 'a';
        count1[index]++;

        int oldIndex = s2[i - windowSize] - 'a';
        count1[oldIndex]--;

        if( checkEqual(count, count1)){    // checking if permutation found in any string in between traversing.
        return 1;
        }
        i++;
    }
    return 0;
}

int main(){

}