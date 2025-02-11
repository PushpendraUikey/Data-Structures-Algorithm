#include <bits/stdc++.h>
using namespace std;

// Attention! Code hasn't been tested for correctness through edge cases although correct.

// Given a set P of points in coordinate system and we want to partition P into different segments S{it is set 
// of continuous points} so that we can minimize errors with respect to points in the set S.

//  The problem is a fundamental instance of an issue in data mining and statistics
//  known as change detection: Given a sequence of data points, we want to
//  identify a few points in the sequence at which a discrete change occurs (in
//  this case, a change from one linear approximation to another)

double errorwrtLine(std::vector<std::pair<int,int>>&points, int i, int j){
    double e=0;
    double sigmay=0, sigmax=0, sigmaxy=0, sigmaxsq=0;
    for(int k=i; k<=j; k++){
        int x, y; x = points[k].first; y = points[k].second;
        sigmay += y; sigmax += x; sigmaxy += (x*y); sigmaxsq += (x*x);
    }
    double n = j-i+1;
    double coeffA = ((n * sigmaxy) - (sigmax * sigmay))/((n*sigmaxsq)-(sigmax*sigmax));
    double coeffB = (sigmay - coeffA*sigmax)/n;
    
    // now comes the error calclculation part
    for(int k=i; k<=j; k++){
        int x, y; x = points[k].first; y = points[k].second;
        e += std::pow((y - coeffA*x - coeffB),2);
    }
    return e;
}
void errorcalculation(std::vector<std::pair<int,int>>&points, std::vector<std::vector<double>>&e){
    int n = points.size();

    for(int i = 0; i<n; i++){
        for(int j=i; j<n; j++){
            e[i][j] = errorwrtLine(points, i, j);
        }
    }

}

// This function prints the optimally partitioned segments.
void findsegments(int j, double cost, std::vector<std::pair<int,int>>&points, std::vector<double>&opt,
                std::vector<std::vector<double>>&e){
        if(j<=0){
            std::cout << " End of partition! \n";
            return;
        }
        double minicost = 10000000009.0; // arbtry large num
        int indx = 0;
        for(int i=1; i<=j; i++){
            double currcost = cost + e[i-1][j-1] + opt[i-1];
            if(minicost >= currcost){
                minicost = currcost;
                indx = i;
            }   
        }
        std::cout << "Next segment is : ";
        for(int k=indx; k<=j; k++){
            std::cout << "("<< points[k-1].first << ' ' << points[k-1].second << "), ";     // Since it is 1-based indexing
        }
        std::cout << "\n";
        findsegments(indx-1, cost, points, opt, e);
}


void segmented_least_square(std::vector<std::pair<int,int>>&points){
    int n = points.size();
    // First we need to sort them in the order of increasing x coordinate points
    std::sort(points.begin(), points.end());
    std::vector<std::vector<double>> e(n, std::vector<double>(n,0));  // n * n matrix for error in points [i,j]

    errorcalculation(points,e);

    // Here we'll produce the segments usign Dynamic programming approach.
    // A fixed cost we'll associate with each sement division

    std::vector<double> opt(n+1, 0);    // This will contain the cumulative error values of optimal segments at index i
    double cost = 5.0;  // any value
    for(int i=1; i<=n; i++){
        opt[i] = 10000000009.0; // any arbitrary large value
        for(int j=1; j<=i; j++){
            double currcost = cost + e[j-1][i-1] + opt[j-1];
            opt[j] = std::min(opt[j], currcost);            
        }
    }
    findsegments(n, cost, points, opt, e);
}