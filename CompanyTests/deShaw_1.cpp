#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> getSecurityTimes(vector<int>& time, vector<int>& destination) {
    int n = time.size();

    // Tuple: (arrival_time, destination, index)
    vector<tuple<int, int, int>> people;
    for (int i = 0; i < n; ++i) {
        people.emplace_back(time[i], destination[i], i);
    }

    // Sort by arrival time, then by index
    sort(people.begin(), people.end());

    queue<tuple<int, int, int>> arriving;   // destination == 0
    queue<tuple<int, int, int>> departing;  // destination == 1

    vector<int> res(n);
    int i = 0;
    int current_time = 0;
    int last_used_time = -2;
    int last_person_type = 1; // assume last crossed was departing

    while (i < n || !arriving.empty() || !departing.empty()) {
        // Queue people arriving at current_time
        while (i < n && get<0>(people[i]) <= current_time) {
            if (get<1>(people[i]) == 0)
                arriving.push(people[i]);
            else
                departing.push(people[i]);
            i++;
        }

        if (arriving.empty() && departing.empty()) {
            current_time++;
            continue;
        }

        tuple<int, int, int> chosen;

        if (!arriving.empty() && !departing.empty()) {
            if (current_time - last_used_time > 1) {
                // No one crossed last second, prefer departing
                chosen = departing.front();
                departing.pop();
            } else {
                // Someone crossed last second
                if (last_person_type == 1) {
                    chosen = departing.front();
                    departing.pop();
                } else {
                    chosen = arriving.front();
                    arriving.pop();
                }
            }
        } else if (!departing.empty()) {
            chosen = departing.front();
            departing.pop();
        } else {
            chosen = arriving.front();
            arriving.pop();
        }

        int idx = get<2>(chosen);
        int type = get<1>(chosen);
        res[idx] = current_time;

        last_used_time = current_time;
        last_person_type = type;

        current_time++;
    }

    return res;
}


int main() {
    vector<int> time = {0, 0, 1, 5};
    vector<int> dest = {0, 1, 1, 0}; // 0 = arriving, 1 = departing

    vector<int> result = getSecurityTimes(time, dest);
    for (int t : result) cout << t << " ";
    return 0;
}
