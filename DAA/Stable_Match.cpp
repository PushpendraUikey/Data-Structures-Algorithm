#include <bits/stdc++.h>
using namespace std;

// We're here trying to build stable matching for n Men and Women using there preference lists.
// Men and Women presented here are with numbers corresponding there indices. eg: 0, 1, 2

// int checkPriority(int person, std::vector<int>&priorlist){
//     for(int i=0; i<priorlist.size(); i++){
//         if(priorlist[i] == person){
//             return i;
//         }
//     }
//     return -1;  // although this condition won't be reach
// }
// int getTop_Choice(std::vector<int>& priority){
//     for(int i=0; i<priority.size(); i++){
//         if(priority[i] != -1){
//             int topchoice = priority[i];
//             priority[i] = -1;   // 
//             return topchoice;
//         }
//     }
//     return -1;  // although this case won't reach in our constraints
// }
// std::unordered_map<int, int> StableMatch(std::set<int>&freeMen, std::set<int>&freeWomen, 
//     std::vector<std::vector<int>>&priorMen, std::vector<std::vector<int>>&priorWomen){
//         std::unordered_map<int, int> couple;

//         while(!freeMen.empty()){
//             int man = *freeMen.begin();
//             int woman = getTop_Choice(priorMen[man]);

//             // Let's make the pair for our man.
//             while(freeMen.find(man) != freeMen.end()){
                    // if (woman == -1) {
                    //     throw std::logic_error("Ran out of women to propose!");
                    // }
//                 if(freeWomen.find(woman) != freeWomen.end()){   // chosen women is free then form couple
//                     couple[woman] = man;                        // they form a couple
                                                        // priorMen[man][woman] = -1; // this is wrong logic[as priorMen is priority list not mapping]
//                     freeMen.erase(man);
//                 }else{                                          // The girl he chose is engaged.
//                     int anotherman = couple[woman];
                    
//                     // lesser index means more prior
//                     if(checkPriority(man, priorWomen[woman]) < checkPriority(anotherman, priorWomen[woman])){
//                         freeMen.insert(anotherman);             // another man is now free.
//                         couple[woman] = man;
                                                        // priorMen[man][woman] = -1; // wrong logic
//                         freeMen.erase(man);
//                     }
//                     else{
//                         // we gotta change the woman
//                         woman = getTop_Choice(priorMen[man]);
//                     }
//                 }
//             }
//         }
//         return couple;      // this is stable and perfect matching
// }

/// @brief Gale-Shapely algorithm to find stable matching
/// @param freeMen In our case men are going to propose hence to keep track of men who haven't proposed
/// @param priorMen This will be priority or men
/// @param priorWomen This will be priority of women
/// @return a map of couple
std::unordered_map<int, int> StableMatch(std::set<int>& freeMen, std::vector<std::vector<int>>& priorMen,
                                         std::vector<std::vector<int>>& priorWomen) {
    int n = priorMen.size();
    std::unordered_map<int, int> couple;      // woman -> man
    std::unordered_map<int, int> menPartner; // man -> woman
    std::vector<int> nextProposal(n, 0);     // Track next proposal index for each man
    std::vector<std::unordered_map<int, int>> womenRanks(n);

    // Precompute women preferences(Very important step!!)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            womenRanks[i][priorWomen[i][j]] = j;
        }
    }

    // Gale-Shapley Algorithm
    while (!freeMen.empty()) {
        int man = *freeMen.begin();
        int woman = priorMen[man][nextProposal[man]++];  // Get top choice and increment index

        if (couple.find(woman) == couple.end()) {
            // Woman is free, pair them
            couple[woman] = man;
            menPartner[man] = woman;
            freeMen.erase(man);
        } else {
            int currentPartner = couple[woman];
            // Compare priorities
            if (womenRanks[woman][man] < womenRanks[woman][currentPartner]) {
                // Woman prefers the new man
                couple[woman] = man;
                menPartner[man] = woman;
                freeMen.erase(man);
                freeMen.insert(currentPartner);  // Current partner becomes free
            }
        }
    }

    return couple;
}
// Stable match with forbidden pairs is also the same but with just a minute difference, we won't pair a 
// man with the woman(vice-versa) who are fobidden for them.
