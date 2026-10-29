#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arAlM = 10 * (arriveAlice[0]-'0') + (arriveAlice[1]-'0');
        int arAlD = 10 * (arriveAlice[3]-'0') + (arriveAlice[4]-'0');
        int lvAlM = 10 * (leaveAlice[0]-'0') + (leaveAlice[1]-'0');
        int lvAlD = 10 * (leaveAlice[3]-'0') + (leaveAlice[4]-'0');

        int arBbM = 10 * (arriveBob[0]-'0') + (arriveBob[1]-'0');
        int arBbD = 10 * (arriveBob[3]-'0') + (arriveBob[4]-'0');
        int lvBbM = 10 * (leaveBob[0]-'0') + (leaveBob[1]-'0');
        int lvBbD = 10 * (leaveBob[3]-'0') + (leaveBob[4]-'0');

        int arAl = dayOfYear(arAlM, arAlD), lvAl = dayOfYear(lvAlM, lvAlD);
        int arBb = dayOfYear(arBbM, arBbD), lvBb = dayOfYear(lvBbM, lvBbD);

        // overlap of [arAl, lvAl] and [arBb, lvBb]
        int start = max(arAl, arBb);
        int end = min(lvAl, lvBb);
        return max(0, end - start + 1);
    }

private:
    int dayOfYear(int month, int day) {
        int days = day;
        for(int i = 0; i < month - 1; i++) days += arr[i];
        return days;
    }
};