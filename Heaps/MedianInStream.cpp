#include<bits/stdc++.h>
using namespace std;

/*
Algorithm to find median in running stream
*/
// the aim of the program is to generate a median of stream(i.e. as input will come update the mean)
// so we are using one "maxheap" and one "minheap", where we store element smaller than meadian into the "maxheap"
// and element greater than the meadian into "minheap", thus making it easy to calculate the median of next stage easily.

int signum(int a, int b){
    if(a==b){
        return 0;
    }
    else if(a>b){
        return 1;
    }else{
        return -1;
    }
}

void callMedian(int element, priority_queue<int>& maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median){
    switch (signum(maxi.size(), mini.size()))
    {
    case 0:
        if(element>median){
            mini.push(element);
            median = mini.top();
        }else{
            maxi.push(element);
            median = maxi.top();
        }
        break;
    case 1:     //// maxheap has n while minheap has n-1 element
        if(element>median){         //// input element is more than median thus push it into minHeap
            mini.push(element);
            median = (mini.top() + maxi.top())/2; 
        }else{ /// since input ele is smaller than median(we have to push it into maxheap) and maxheap has more element
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median = (mini.top() + maxi.top())/2; 
        }
        break;
    case -1:
        if(element>median){
            maxi.push(mini.top());
            mini.pop();
            mini.push(element);
            median = (mini.top() + maxi.top())/2;
        }else{
            maxi.push(element);             /// mini has more ele and e < median thus push it to maxheap
            median = (mini.top() + maxi.top())/2;       /// now maxi and mini have equal no of elements
        }
    default:
        break;
    }
}