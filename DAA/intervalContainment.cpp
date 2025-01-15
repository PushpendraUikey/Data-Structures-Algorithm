#include <bits/stdc++.h>
using namespace std;

std::vector<std::pair<int, int>> intervals(std::vector<std::pair<int, int>>& interval){
    // we need to sort on the basis increasing order of their starting time
    // O(nlogn) 
    std::sort(interval.begin(), interval.end());
    std::vector<std::pair<int, int>> ans;
    int lastend = INT_MIN;
    int j = -1;
    for(int i=0; i<interval.size(); i++){

        if( j!=-1 && interval[i].first == ans[j].first && interval[i].second > lastend){ // overlapping inteval's found(same start)
            ans.pop_back();
            ans.push_back(interval[i]);
            lastend = interval[i].second;
        }else
        if(interval[i].second > lastend){   // They didn't overlapped
            j++;
            ans.push_back(interval[i]);
            lastend = interval[i].second;
        }
    }

    return ans;
}

// in this part we need to find the total length of union of all the intervals given to us
int totalLength(std::vector<std::pair<int,int>>&interval){

    std::sort(interval.begin(), interval.end());

    int length = 0;
    int deficit=0, lastend=0;

    for(int i=0; i<interval.size(); i++){
        if(interval[i].second <= lastend) continue; // later interval is contained inside the prior
        length += (interval[i].second - lastend);
        // if there's some gap between successive interavls(they're in increasing order)
        if(interval[i].first > lastend){
            deficit += (interval[i].first - lastend);
        }
        lastend = interval[i].second;
    }

    return length - deficit;
}

int nonOverlapping(std::vector<std::pair<int,int>>&interval){
    std::sort(interval.begin(), interval.end());
    int lastend = INT_MIN;
    int nonoverlap = 0;
    for(int i=0; i<interval.size(); i++){
        if(interval[i].first >= lastend) nonoverlap++;
        lastend = std::max(interval[i].second, lastend);
    }
    return nonoverlap;
}

int maxintersecting(std::vector<std::pair<int,int>>&interval){
    std::vector<std::pair<int,int>> events;
    for(auto& in: interval){
        events.push_back({in.first, 1});
        events.push_back({in.second, -1});
    }
    std::sort(events.begin(), events.end());

    int activeinterval=0, maxinterval=0;
    for(auto& in:events){
        activeinterval += in.second;
        maxinterval = std::max(activeinterval, maxinterval);
    }
    return maxinterval;
}

int main(int argc, char* argv[]){
    int n; cin >> n;
    std::vector<pair<int,int>> vec;
    for(int i=0 ;i<n; i++){
        int a, b; cin >> a >> b;
        vec.push_back({a,b});
    }
    std::cout << totalLength(vec) << endl;
}