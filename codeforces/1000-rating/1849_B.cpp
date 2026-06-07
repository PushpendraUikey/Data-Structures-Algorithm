#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

// Monsters
// https://codeforces.com/contest/1849/problem/B

struct Compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    }
};
int n, k;
int arr[300005];
void solve() {
    cin >> n >> k;
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
    int i=1;
    int elem;
    while(i<=n){
        cin >> elem;
        pq.push({elem, i});
        i++;
    }

    i = 0;
    while(!pq.empty()){
        auto front = pq.top();
        pq.pop();
        front.first -= k;
        if(front.first>0){
            pq.push(front);
        }else{
            arr[i] = front.second;
            i++;
        }
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}

/*
Your logic for the rules of the game is **conceptually perfect**. Your `Compare` structure exactly captures the 
priority conditions: hit the monster with the highest health, and use the lowest index as a tiebreaker.

However, this code will almost certainly hit a **Time Limit Exceeded (TLE)** on Codeforces.

### The Problem: Step-by-Step Simulation is Too Slow

The constraints for this problem allow $a_i$ (health) and $k$ (damage) to be up to $10^9$.
Imagine a test case where a monster has $10^9$ health and $k = 1$. Your `while` loop will pop, subtract 1, and push 
back into the priority queue **one billion times** for a *single* monster. This is $O(\frac{a_i}{k} \log n)$ per 
monster, which is way too slow for the 2.0-second time limit.

### The Fix: The Modulo Math Trick

Instead of simulating every single attack, we can fast-forward to the end of the monster's life using the modulo 
operator (`%`).

Every time you hit a monster, its health drops by $k$. Therefore, the *only* thing that matters for the kill order 
is the monster's health during the **final round of hits**—which is exactly `health % k`.

**The Edge Case:** If a monster's health is perfectly divisible by $k$ (e.g., `health % k == 0`), it means it will 
die exactly on a clean hit. In the "final round" of hits, its effective health was exactly $k$. So, if 
`health % k == 0`, we just treat its remaining health as $k$.

By calculating this effective final health, we can completely eliminate the simulation and just **sort** the array 
once!

### Refactored $O(n \log n)$ Code

Here is the optimized approach. It uses standard sorting and entirely avoids the priority queue simulation:

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    // Vector of pairs: {effective_health, index}
    vector<pair<int, int>> monsters(n);
    
    for (int i = 0; i < n; i++) {
        int hp;
        cin >> hp;
        
        // Fast-forward to the final round of health
        hp %= k;
        if (hp == 0) {
            hp = k; // If exactly divisible, its last health state was k
        }
        
        monsters[i] = {hp, i + 1};
    }

    // Sort using a custom lambda function
    sort(monsters.begin(), monsters.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second; // Tiebreaker: lowest index first
        }
        return a.first > b.first;       // Primary: highest effective health first
    });

    // Output the sorted indices
    for (int i = 0; i < n; i++) {
        cout << monsters[i].second << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}

```

### Why this is better:

* **Time Complexity:** $O(n \log n)$ strictly bounded by the `std::sort` function. It doesn't matter if $a_i$ is $10$ 
    or $10^9$; it processes instantly.
* **Space Complexity:** $O(n)$ to store the array, cleanly managed by `std::vector`.
* **No `priority_queue` overhead:** Inserting and extracting from a heap $N$ times carries a heavier constant factor 
    than a single contiguous memory sort.
*/