#include <bits/stdc++.h>
using namespace std;


//Produces a set of non-overlapping intervals from the original list.
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

// Here's the neater code for the above. [finding the total length of the union of intervals.]
int totalLength(std::vector<std::pair<int, int>>& intervals) {
    // Sort intervals by starting time
    std::sort(intervals.begin(), intervals.end());

    int length = 0, lastEnd = 0;

    for (const auto& interval : intervals) {
        if (interval.second <= lastEnd) continue; // Skip fully overlapping interval
        length += interval.second - std::max(interval.first, lastEnd); 
        lastEnd = interval.second; // Update the end of the last covered range
    }

    return length;
}


// No of non-overlapping intervals.
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

// Number of maximum intersecting intervals 
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

// This part deals with the minimum resources to schedule all the intervals.    [TC: O(nlogn)]
void miniResources(std::vector<std::pair<int, int>>& intervals){
    // Min Resources required is at least maximum intersecting intervals[They need to be scheduled differently]
    int d = maxintersecting(intervals);
    std::vector<std::vector<std::pair<int, int>>> minischedule(d);
    std::sort(intervals.begin(), intervals.end());

    for(auto &intrval : intervals){
        for(int i=0; i<d; i++){
            if(minischedule[i].empty() || minischedule[i].back().second <= intrval.first){
                minischedule[i].push_back(intrval);     // push the first found interval crspndng to a parti. label
                break;  // Once added no need to check further, you're good to go.
            }
        }
    }
}


// Here comes the solution to the problem of weighted scheduling where we have intervals with weights along
// with them and we want to schedule in such a way that intervals are compatible and total weight is 
// maximum among any compatible set

void pCalculate(std::vector<std::tuple<int,int,int>>&intervals, std::vector<int>&p){
    int n = intervals.size();
    for(int j=0; j<n; j++){
        int start_j, finish_j, weight_j;
        tie(start_j, finish_j, weight_j) = intervals[j];
        int i=j-1;
        while(i>=0){
            int start_i, finish_i, weight_i;
            tie(start_i, finish_i, weight_i) = intervals[i];
            if(finish_i <= start_j) break;  // found the end point of some interval to be less than start of require
            i--;
        }
        p[j] = i;   // allowing p[j] to be -1
    }
}
// Recusive optimal scheduling weight optimization
int ComputeWeight(std::vector<int>&computeOpt, int j, std::vector<std::tuple<int,int,int>>&intervals, std::vector<int>&p){
    int a,b,c; tie(a,b,c) = intervals[j];
    if(j < 0){
        return 0;
    }
    if(computeOpt[j] != -1) return computeOpt[j];   // memoization

    return computeOpt[j] = std::max(c + ComputeWeight(computeOpt, p[j], intervals, p), 
                            ComputeWeight(computeOpt, j-1, intervals, p) );
}

// Following algorithm traces back the optimal sets which maximized the weights and prints the
// weights which indeed were the part of maximum total weight set.
void find_solutions(int j, std::vector<int>&computOpt, std::vector<std::tuple<int,int,int>>&intervals, std::vector<int>&p){
    if(j < 0) return;   // base case
    if(j == 0){
        std::cout << std::get<2>(intervals[j]) << ' ' << "\n";  // print the solution;
    }
    if( std::get<2>(intervals[j]) + computOpt[p[j]]  >= computOpt[j-1]){
        std::cout << std::get<2>(intervals[j]);
        find_solutions(p[j], computOpt, intervals, p);
    }else{
        find_solutions(j-1, computOpt, intervals, p);
    }
}

// input contains {start, end, weight}
void weightedschedule(std::vector<std::tuple<int, int, int>>& intervals){
    int n = intervals.size();
    std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
        return std::get<1>(a) < std::get<1>(b);     // Sort on the basis of finish time
    });
    // P(j) calculation we define p(j), for an interval j, to be the largest index i < j such that intervals i and j are disjoint
    std::vector<int> p(n, 0), computeOpt(n+1, -1);
    pCalculate(intervals, p);
    int ans = ComputeWeight(computeOpt, n, intervals, p);
}

void iterativePcalculate(std::vector<int>&p, std::vector<std::tuple<int,int,int>>&intervals){
    int n = intervals.size();
    for(int j=0; j<n; j++){
        int start_j, finish_j, weight_j;
        tie(start_j, finish_j, weight_j) = intervals[j];
        int i=j-1;
        while(i>=0){
            int start_i, finish_i, weight_i;
            tie(start_i, finish_i, weight_i) = intervals[i];
            if(finish_i <= start_j) break;  // found the end point of some interval to be less than start of require
            i--;
        }
        p[j] = i+1; // if no interval found then i will be -1 thus p[j]=0
    }
}
// Instead of above recursive memoization we'll now use the Iterative approach to solve the problem.
void iterativeWeightedschedule(std::vector<std::tuple<int,int,int>>&intervals){
    int n = intervals.size();
    std::sort(intervals.begin(), intervals.end(), [](auto&a, auto&b){
        return std::get<1>(a) < std::get<1>(b);
    });
    std::vector<int> p(n,0), computeOpt(n+1, 0);
    iterativePcalculate(p, intervals);
    for(int j=1; j<= n; j++){
        int weight = std::get<2>(intervals[j]);
        computeOpt[j] = std::max(weight+computeOpt[p[j]], computeOpt[j-1]);
    }
    std::cout << "Maximum weight is : " << computeOpt[n] << "with following weights \n";
    find_solutions(n, computeOpt, intervals, p);
}

// Driver code.
int main(int argc, char* argv[]){
    int n; cin >> n;
    std::vector<pair<int,int>> vec;
    for(int i=0 ;i<n; i++){
        int a, b; cin >> a >> b;
        vec.push_back({a,b});
    }
    std::cout << totalLength(vec) << endl;
}