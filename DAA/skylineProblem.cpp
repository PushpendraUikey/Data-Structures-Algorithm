#include <bits/stdc++.h>
using namespace std;
#define ll long long

// DANGER: Solution are not completely correct and based on certain assumptions, needs to be completed.

// let me make an O(n^2) algorithm: 
ll calculateAreabruteforce(std::vector<std::tuple<int, int, int>>& buildings){
    std::vector<std::pair<int, int>> outline;
    for(int i=0; i<buildings.size(); i++){
        for(int j=0; j != i && j<buildings.size(); j++){

        }
    }
    return 0;
}

// Here I'm trying Divide and Conquer approach to solve the outline of skyline
void mergeoutline(std::vector<std::pair<int,int>>&outline1, std::vector<std::pair<int,int>>&outline2,
    std::vector<std::pair<int,int>>&finaloutline){
        int height_1 =0, height_2 = 0;
        int i=0, j=0;
        // This has only one problem which is it will have consecutive repeating heights as it pushes
        // the outline for each corner.
        while(i<outline1.size() && j<outline2.size()){
            if(outline1[i].first < outline2[j].first){
                height_1 = outline1[i].second;
                finaloutline.push_back({outline1[i].first, std::max(height_1, height_2)});
                i = i+1;
            }else{
                height_2 = outline2[j].second;
                finaloutline.push_back({outline2[j].first, std::max(height_1, height_2)});
                j = j + 1;
            }
        }
        while(i<outline1.size()){
            height_1 = outline1[i].second;
            finaloutline.push_back({outline1[i].first, std::max(height_1, height_2)});
            i = i+1;
        }
        while(j<outline2.size()){
            height_2 = outline2[j].second;
            finaloutline.push_back({outline2[j].first, std::max(height_1, height_2)});
            j = j + 1;
        }
}

// alternative of above implementation with just improvement that height won't be repeated
std::vector<std::pair<int,int>> mergeoutline2(std::vector<std::pair<int,int>>&outline1, std::vector<std::pair<int, int>>&outline2){
        int height_1 =0, height_2 = 0;
        int i=0, j=0;
        std::vector<std::pair<int,int>> finaloutline;
        int heighttopush=0, lastpushedh = 0;
        while(i<outline1.size() && j<outline2.size()){
            if(outline1[i].first < outline2[j].first){
                height_1 = outline1[i].second;
                heighttopush = std::max(height_1, height_2);
                if(heighttopush != lastpushedh){
                    // finaloutline[k] = {outline1[i].first, heighttopush};
                    finaloutline.push_back({outline1[i].first, heighttopush});
                    lastpushedh = heighttopush;
                }                
                i = i+1;
            }else{
                height_2 = outline2[j].second;
                heighttopush = std::max(height_1, height_2);
                if(heighttopush != lastpushedh){
                    // finaloutline[k] = {outline2[j].first, heighttopush};
                    finaloutline.push_back({outline2[j].first, heighttopush});
                    lastpushedh = heighttopush;
                }
                j = j + 1;
            }
        }
        while(i<outline1.size()){
            height_1 = outline1[i].second;
            heighttopush = std::max(height_1, height_2);
            if(heighttopush != lastpushedh){
                // finaloutline[k] = {outline1[i].first, heighttopush};
                finaloutline.push_back({outline1[i].first, heighttopush});
                lastpushedh = heighttopush;
            }
            i = i+1;
        }
        while(j<outline2.size()){
            height_2 = outline2[j].second;
            heighttopush = std::max(height_1, height_2);
            if(heighttopush != lastpushedh){
                // finaloutline[k] = {outline2[j].first, heighttopush};
                finaloutline.push_back({outline2[j].first, heighttopush});
                lastpushedh = heighttopush;
            }
            j = j + 1;
        }

        return finaloutline;
    }

std::vector<std::pair<int,int>> makeSkyline(std::vector<std::tuple<int, int, int>>&buildings){
    int n = buildings.size();
    if(n<=1) {
        std::vector<std::pair<int,int>> out;
        int x,y,h; std::tie(x,y,h) = buildings[0];
        out.push_back({x,h});
        out.push_back({y, 0});
        return out;
    }
    std::vector<std::tuple<int,int,int>> first, second;
    int i=0;
    for(i=0;i<n/2; i++){
        first.push_back(buildings[i]);
    }
    for(i=n/2; i<n; i++){
        second.push_back(buildings[i]);
    }
    // The approach similar to the merge sort.
    std::vector<std::pair<int,int>> ans1 = makeSkyline(first);
    std::vector<std::pair<int,int>> ans2 = makeSkyline(second);

    return mergeoutline2(ans1, ans2);
}


// Here's the algorithm to create a skyline using multiset
// The same approach can be used using Heaps.
std::vector<std::pair<int, int>> createSkyline(std::vector<std::tuple<int, int, int>>&buildings){
    int n = buildings.size();
    std::vector<std::pair<int, int>> wall;
    for(int i=0; i<n; i++){
        int x1, x2, h;
        std::tie(x1, x2, h) = buildings[i];
        wall.push_back({x1, -h});
        wall.push_back({x2, h});
    }
    std::sort(wall.begin(), wall.end());
    std::vector<std::pair<int, int>> skyline;
    std::multiset<int> leftwallheight = {0};

    int top=0;
    for(auto & w: wall){
        if(w.second < 0){   // this is for the left wall
            leftwallheight.insert(-w.second);
        }// if right wall is found
        else{
            leftwallheight.erase(           // this particular building is done(we're done with it)
                leftwallheight.find(w.second)
            );
        }

        // We'll mark the skyline point if top changes
        if(*leftwallheight.rbegin() != top){
            top = *leftwallheight.rbegin();
            skyline.push_back({w.first, top});
        }
    }
    return skyline;
}

// Here's the wrong approach I was going with to solve the skyline problem and 
// : You shouldn't often try to check every possible cases if the cases are so many
// 
ll calculateArea(std::vector<std::tuple<int, int, int>> buildings){
    // We need outline first of all
    std::vector<std::pair<int, int>> outline;
    std::sort(buildings.begin(), buildings.end());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> beg, end;

    int lastend = INT_MIN;
    int prevh = 0;
    for(int i=0; i<buildings.size(); i++){
        int x1, x2, h;
        std::tie(x1, x2, h) = buildings[i];
        beg.push({x1, h});
        end.push({x2, h});
    }


    while( !beg.empty() && !end.empty()){
        if(beg.top().first > end.top().first){
            outline.push_back({beg.top()});
            beg.pop();
        }else{
            if(beg.top().second > end.top().second){
                outline.push_back({beg.top()});
                beg.pop();
            }else{
                outline.push_back({end.top().first, beg.top().second});
                end.pop();
                beg.pop();
            }
        }
    }

    for(int i=0; i<outline.size(); i++){
        std::cout << outline[i].first << "  " << outline[i].second << std::endl;
    }

    std::cout << "GFG solution: \n";
    outline = createSkyline(buildings);
    for(int i=0; i<outline.size(); i++){
        std::cout << outline[i].first << "  " << outline[i].second << std::endl;
    }
    
    std::cout << "Class Solution: \n";
    outline = makeSkyline(buildings);
    for(int i=0; i<outline.size(); i++){
        std::cout << outline[i].first << "  " << outline[i].second << std::endl;
    }
    return 0ll;
}

int main(int argc, char* argv[]){
    std::vector<std::tuple<int, int, int>> building;
    building.push_back({1,4,4});
    building.push_back({2,3,5});
    building.push_back({4, 6, 3});
    building.push_back({7, 9, 2});
    building.push_back({10, 15, 1});
    calculateArea(building);
}


