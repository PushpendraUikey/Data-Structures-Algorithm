#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given the weights and values of N items, put these items in a knapsack of capacity W to get the 
maximum total value in the knapsack. In Fractional Knapsack, we can break items for maximizing 
the total value of the knapsack
*/

// Structure to store value and weight of an item
class Item {
public:
    int value, weight;

    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

// Comparator function to sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Main greedy function to solve the problem
double fractionalKnapsack(int W, vector<Item> &arr) {

    // Sorting items based on value/weight ratio
    sort(arr.begin(), arr.end(), compare);

    double finalValue = 0.0;  // Final result

    // Looping through all items
    for (Item &item : arr) {

        // If adding the whole item won't overflow, add it completely
        if (item.weight <= W) {
            W -= item.weight;
            finalValue += item.value;
        }
        // If we can't add the current item, add the fractional part
        else {
            finalValue += item.value * ((double)W / item.weight);
            break;
        }
    }

    return finalValue;  // Returning the final value
}

int main() {
    int W = 50;  // Weight of knapsack
    vector<Item> arr = { Item(60, 10), Item(100, 20), Item(120, 30) };

    // Function call
    double maxVal = fractionalKnapsack(W, arr);
    cout << "Maximum value we can obtain = " << maxVal << endl;

    return 0;
}