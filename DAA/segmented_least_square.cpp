#include <bits/stdc++.h>
using namespace std;

// Attention! Code hasn't been tested for correctness through edge cases although correct.

// Given a set P of points in coordinate system and we want to partition P into different segments S{it is set 
// of continuous points} so that we can minimize errors with respect to points in the set S.

//  The problem is a fundamental instance of an issue in data mining and statistics
//  known as change detection: Given a sequence of data points, we want to
//  identify a few points in the sequence at which a discrete change occurs (in
//  this case, a change from one linear approximation to another)

double errorwrtLine(std::vector<std::pair<double,double>>&points, int i, int j){
    double e=0;
    double sigmay=0, sigmax=0, sigmaxy=0, sigmaxsq=0;
    for(int k=i; k<=j; k++){
        double x = points[k].first;
        double y = points[k].second;
        sigmay += y; sigmax += x; sigmaxy += (x*y); sigmaxsq += (x*x);
    }
    double n = j-i+1;
    double denom = (n*sigmaxsq) - (sigmax*sigmax);
    double coeffA = 0.0;
    if(std::fabs(denom) > 1e-12) coeffA = ((n * sigmaxy) - (sigmax * sigmay))/denom;
    double coeffB = (sigmay - coeffA*sigmax)/n;
    
    // now comes the error calclculation part
    for(int k=i; k<=j; k++){
        double x = points[k].first;
        double y = points[k].second;
        e += std::pow((y - coeffA*x - coeffB),2);
    }
    return e;
}
void errorcalculation(std::vector<std::pair<double,double>>&points, std::vector<std::vector<double>>&e){
    int n = points.size();

    for(int i = 0; i<n; i++){
        for(int j=i; j<n; j++){
            e[i][j] = errorwrtLine(points, i, j);
        }
    }

}

// This function prints the optimally partitioned segments.
void findsegments(int j, double cost, std::vector<std::pair<double,double>>&points, std::vector<double>&opt,
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


void segmented_least_square(std::vector<std::pair<double,double>>&points){
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
            // opt[i] holds the optimal cost for first i points;
            // update opt[i] (not opt[j])
            opt[i] = std::min(opt[i], currcost);            
        }
    }
    findsegments(n, cost, points, opt, e);
}

int main(){
    int n; std::cin >> n;
    std::vector<std::pair<double,double>> points(n);
    for(int i=0; i<n; i++){
        double x, y; std::cin >> x >> y;
        points[i] = {x,y};
    }
    segmented_least_square(points);
    return 0;
}


// ----------------------- Following is the GPT generated code for the same problem statement. -------------------
// #include <bits/stdc++.h>
// using namespace std;

// struct P { double x,y; };

// double eps = 1e-9;

// // prefix sums are 1-based: prefix[k] = sum of elements 1..k
// void build_prefix(const vector<P>& pts,
//                   vector<double>& Sx, vector<double>& Sy,
//                   vector<double>& Sxx, vector<double>& Sxy, vector<double>& Syy){
//     int n = pts.size();
//     Sx.assign(n+1,0.0); Sy.assign(n+1,0.0);
//     Sxx.assign(n+1,0.0); Sxy.assign(n+1,0.0); Syy.assign(n+1,0.0);
//     for(int i=1;i<=n;i++){
//         double x = pts[i-1].x, y = pts[i-1].y;
//         Sx[i]  = Sx[i-1]  + x;
//         Sy[i]  = Sy[i-1]  + y;
//         Sxx[i] = Sxx[i-1] + x*x;
//         Sxy[i] = Sxy[i-1] + x*y;
//         Syy[i] = Syy[i-1] + y*y;
//     }
// }

// // compute sums for interval [i..j] (1-based indices)
// inline void interval_sums(int i, int j,
//                           const vector<double>& Sx, const vector<double>& Sy,
//                           const vector<double>& Sxx, const vector<double>& Sxy, const vector<double>& Syy,
//                           double &sx, double &sy, double &sxx, double &sxy, double &syy){
//     sx  = Sx[j]  - Sx[i-1];
//     sy  = Sy[j]  - Sy[i-1];
//     sxx = Sxx[j] - Sxx[i-1];
//     sxy = Sxy[j] - Sxy[i-1];
//     syy = Syy[j] - Syy[i-1];
// }

// // SSE for best-fit line on points i..j (1-based)
// double error_interval(int i, int j,
//                       const vector<double>& Sx, const vector<double>& Sy,
//                       const vector<double>& Sxx, const vector<double>& Sxy, const vector<double>& Syy){
//     double sx, sy, sxx, sxy, syy;
//     interval_sums(i,j,Sx,Sy,Sxx,Sxy,Syy, sx,sy,sxx,sxy,syy);
//     double n = (double)(j - i + 1);
//     double denom = n * sxx - sx * sx;
//     double A = 0.0;
//     if (fabs(denom) > 1e-12) {
//         A = (n * sxy - sx * sy) / denom;
//     } else {
//         A = 0.0; // vertical-line case: fit horizontal through mean y
//     }
//     double B = (sy - A * sx) / n;
//     // SSE = Σ(y - A x - B)^2 = Syy + A^2*Sxx + n*B^2 + 2*A*B*Sx - 2*A*Sxy - 2*B*Sy
//     double SSE = syy + A*A*sxx + n*B*B + 2.0*A*B*sx - 2.0*A*sxy - 2.0*B*sy;
//     // numerical noise -> clamp tiny negative to 0
//     if (SSE < 0 && SSE > -1e-9) SSE = 0;
//     return SSE;
// }

// vector<pair<int,int>> segmented_least_squares(vector<P> pts, double C){
//     int n = pts.size();
//     sort(pts.begin(), pts.end(), [](const P&a,const P&b){
//         if (a.x != b.x) return a.x < b.x;
//         return a.y < b.y;
//     });

//     vector<double> Sx, Sy, Sxx, Sxy, Syy;
//     build_prefix(pts, Sx, Sy, Sxx, Sxy, Syy);

//     vector<double> opt(n+1, 1e100);
//     vector<int> prev(n+1, -1);
//     opt[0] = 0.0;

//     // DP O(n^2)
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             double err = error_interval(j, i, Sx, Sy, Sxx, Sxy, Syy);
//             double cand = opt[j-1] + err + C;
//             if (cand + 1e-12 < opt[i]){ // strict with tol
//                 opt[i] = cand;
//                 prev[i] = j; // segment [j..i]
//             }
//         }
//     }

//     // reconstruct segments in correct order
//     vector<pair<int,int>> segs;
//     int cur = n;
//     while(cur > 0){
//         int s = prev[cur];
//         if (s <= 0) { // safety
//             break;
//         }
//         segs.emplace_back(s, cur); // 1-based indices into sorted pts
//         cur = s - 1;
//     }
//     reverse(segs.begin(), segs.end());
//     // If caller needs the actual coordinates, we can map these indices to pts.
//     return segs;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n; 
//     if (!(cin >> n)) return 0;
//     vector<P> pts(n);
//     for(int i=0;i<n;i++) cin >> pts[i].x >> pts[i].y;
//     double C = 5.0; // segmentation penalty
//     auto segs = segmented_least_squares(pts, C);
//     cout << "Segments (indices in sorted-by-x order, 1-based):\n";
//     for(auto &pr: segs){
//         cout << "[" << pr.first << "," << pr.second << "] : ";
//         for(int k=pr.first; k<=pr.second; ++k){
//             cout << "(" << pts[k-1].x << "," << pts[k-1].y << ") ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }
