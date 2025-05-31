#include<bits/stdc++.h>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<algorithm>

using namespace std;

/////////////////////////// Binary Search ////////////////

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);

    cout << "finding 8-> "  << binary_search(v.begin(), v.end(), 8) << endl;    // It requires sorted array to process.

    cout << "lower bound-> " << lower_bound(v.begin(), v.end(), 8) - v.begin() << endl;
    cout << "upper bound-> " << upper_bound(v.begin(), v.end(), 8) - v.begin() << endl;

    int a = 3;
    int b = 4;
    cout << "Max -> " << max(a,b) << endl;
    cout << "Min -> " << min(a,b) << endl;

    swap(a,b);
    cout << "a-> " << a << endl;
    cout << "b-> " << b << endl;

    string abcd = "abcdefg";

    reverse(abcd.begin(), abcd.end());

    cout << "String -> " << abcd << endl;

    rotate(v.begin(), v.begin()+1,v.end());

    cout << "After Rotation: " << endl;
    for(auto i:v){                       // To dereference it v[i] can be used only when fixed sized array is used there.
        cout << i << ' ';
    } cout << endl;

    sort(v.begin(), v.end());
    for(auto i:v){     
        cout << i << ' ';
    } cout << endl;

}

/////////////////////////// Map /////////////////////////

// int main() {
//     map<int , string> m;// one key can map to only one value, but single value can be mapped by multiple keys.

//     m[1] = "Pushpendra";
//     m[2] = "You";
//     m[3] = "See";
//     m[4] = "What";
//     m[5] = "Have";
//     m[6] = "You";
//     m[7] = "Done.";

//     for(auto i:m) cout << i.first << ' ' << i.second << endl;
//     cout << endl;

//     cout << "finding 7-> " << m.count(7) << endl;

//     m.erase(7);
//     cout << "After erase : " << endl;
//     for( auto i:m){
//         cout << i.first << ':' << i.second << endl;
//     }
//     cout << endl;

//     auto it = m.find(3);
//     for(auto i=it; i!=m.end(); i++){
//         cout << (*i).first << ':' << (*i).second << endl;
//     } cout << endl;
// }

/////////////////////////// Set /////////////////////////

// int main() {
//     set <int> s;    // insert only element only time that too a in sorted order only,
//     s.insert(5);
//     s.insert(6);
//     s.insert(5);
//     s.insert(3);
//     s.insert(9);
//     s.insert(6);
//     s.insert(5);
//     s.insert(7);

//     for(int i: s) cout << i << ' ';
//     cout << endl;

//     set<int>::iterator it = s.begin();
//     it++;   // You can increment like this but you can't manually add the indices.

//     s.erase(it); // Erase only the indexed given.

//     for(auto i:s){
//         cout << i << endl;
//     }

//     cout << "3 is present or not: " << s.count(3) << endl;  // This function tells the presence of given number.

//     set<int>::iterator itr = s.find(5);     // find() method returns the iterator if the element is present.

//     cout << "Value present at itr: " << *itr << endl;

//     for(auto it=itr; it!=s.end(); it++){
//         cout << *it << ' ';
//     }cout << endl;

// }

/////////////////////////// priorit_queue /////////////////////

// int main(){
    // Max Heap
    // priority_queue<int> maxi;
    
    // Min Heap
    // priority_queue<int, vector<int>, greater<int> > mini;
    
    // maxi.push(1);
    // maxi.push(2);
    // maxi.push(3);
    // maxi.push(0);

    // pop() method is removing the element from the beginning.

//     int n = maxi.size();
//     for(int i{0}; i<n ; i++){
//         cout << maxi.top() << ' ';
//         maxi.pop();
//     } cout << endl;

//     mini.push(5);
//     mini.push(2);
//     mini.push(3);
//     mini.push(4);
//     mini.push(0);


//     int k = mini.size();
//     for(int i{0}; i<k ; i++){
//         cout << mini.top() << ' ';
//         mini.pop();
//     } cout << endl;

//     cout << "Is empty -> " << mini.empty() << endl;
// }

/////////////////////////// queue ///////////////////////////

// int main() {
//     queue<string> s;    // first come first in

//     s.push("Pushpendra");
//     s.push("You are");
//     s.push("taken back to job.");

//     cout << "First element: " << s.front() << endl;
//     cout << "Size before pop: " << s.size() << endl;

//     s.pop();
    
//     cout << "First element: " << s.front() << endl;
//     cout << "Size after pop: " << s.size() << endl;
// }

/////////////////////////// Stack ///////////////////////////

// int main() {
//     stack<string> s;    // last in  -  first out 

//     s.push("Pushpendra");
//     s.push("ThereFore");
//     s.push("You are fired.");

//     cout << "Top Element: " << s.top() << endl;
//     s.pop();
//     cout << "Top Element after pop: " << s.top() << endl;

//     cout << "Size of Stack " << s.size() << endl;
//     cout << "Empty or not " << s.empty() << endl;

// }

//////////////////////////// list ////////////////////////////
// int main(){
//     list <int> l;
//     l.push_back(1);
//     l.push_front(2);

//     list <int> n(5,100);    // created 5 elements of list and initialized them with 100;

//     for(int i:n) cout << i << ' ';
//     cout << endl;

//     for(int i:l) cout << i << ' ';
//     cout << endl;

//     l.erase(l.begin());

//     cout << "After erase: " << endl;
//     for(int i:l) {
//         cout << i << ' ';
//     }
//     cout << endl;
// }

//////////////////////////// deque ///////////////////////////
// int main(){
//     deque<int> d;
//     d.push_back(1);
//     d.push_front(2);

//     for(int i:d) cout << i << ' ';  // 'i' not traversing through indices but rather through elements of d;
//     cout << endl;
//     // d.pop_front();
//     for(int i:d) cout << i << endl;

//     cout << "Print first INDEX Element-> " << d.at(1) << endl;

//     cout << "front: " << d.front() << endl;
//     cout << "back:  " << d.back() << endl;
//     cout << "Empty or Not: " << d.empty() << endl;
//     cout << "Before erase: " << d.size() << endl;
//     d.erase(d.begin(), d.begin() + 1);
//     cout << "after erase " << d.size() << endl;
// }

//////////////////////////// Array //////////////////////////

// int main(){

//     int basic[3] = {1,2,3};
//     array<int,4> a = {1,2,3,4};

//     int size = a.size();

//     for(int i{0}; i<size; i++) cout << a[i] << ' ';
//     cout << endl;

//     cout << "Element at 2nd Index of array: " << a.at(2) << endl;
//     cout << "Empty or not: " << a.empty() << endl;

//     cout << "First element-> " << a.front() << endl;
//     cout << "Last element-> " << a.back() << endl;
// }

/////////////////////////////// Vector /////////////////////////////////

// int main() {
//     vector<int> v;
//     vector<int> a(5,1); // five elements initialzed with 1, if not specified then with zero.
//     vector<int> last(a); // last vector with all the elements copied from 'a';

//     for(int i:a) cout << a[i] << ' ';
//     cout << endl;
//     for(int i:last) cout << last[i] << ' ';
//     cout << endl;

//     cout << "Size-> " << v.capacity() << endl;

//     v.push_back(1);
//     cout << "Size-> " << v.capacity() << endl;

//     v.push_back(2);
//     cout << "Size-> " << v.capacity() << endl;

//     v.push_back(3);
//     cout << "Size-> " << v.capacity() << endl;

//     cout << "Capacity-> " << v.size() << endl;
//     cout << "Element at 2nd Index: " << v.at(2) << endl;

//     cout << "Front " << v.front() << endl;
//     cout << "Back " << v.back() << endl;

//     cout << "Before Pop " << endl;
//     for(int i:v)cout << v[i] <<' ';
//     cout << endl;

//     v.pop_back();

//     cout << "After Pop " << endl;
//     for(int i:v) cout << v[i] << ' ';
//     cout << endl;

//     cout << "Size-> " << v.capacity() << endl;
//     cout << "Capacity-> " << v.capacity() << endl;

//     cout << "Before clear size: " << v.size() << endl;
//     v.clear();
//     cout << "After clear size: " << v.size() << endl;
// }