#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int x;
    node* next;
    node* prev;
};
node* reverse(node* head){
    if(!head) return nullptr;
    node* curr = head;
    node* prev = nullptr;
    node* temp = nullptr;
    while(curr->next){
        temp = curr->next;
        curr->next = prev;
        if(prev) prev->prev = curr;
        curr -> prev = temp;
        prev = curr;
        curr = temp;
    }

    curr->next = prev;
    curr->prev = nullptr;

    return curr;
}

node* reverseDll(node* head){
    if(head == nullptr || head->next == nullptr) return head;

    node* prev = nullptr, *curr = head;
    while(curr){
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}
void circularLLtraversal(node* head){
    if(!head) return;
    
    node* curr = head->next;
    cout << head -> x << ' ';
    while(curr != head){
        cout << curr->x << ' ';
        curr = curr -> next;
    }
    cout << "\n";
}
node* insertatHeadofcircularLL(node* head, int data){
    node* temp = new node();
    temp->next = temp->prev = nullptr;
    temp->x = data;
    if(!head) {
        temp->next = temp;
        return temp;
    }
    node* curr = head->next;
    while(curr->next != head) curr = curr -> next;
    temp->next = head;
    curr->next = temp;
    return temp;
}
node* insertAtHeadinO1CLL(node* head, int data){
    node* temp = new node(); 
    temp->next = temp->prev = nullptr;
    temp->x = data;
    if(!head){
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int t = head->x;
    head->x = temp->x;
    temp->x = t;
    return head;
}
node* insertAtEndinCLL(node* head, int data){
    node* temp = new node();
    temp->next = temp->prev = nullptr;
    temp->x = data;
    if(! head){
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;
    int t = head->x;
    head->x = temp->x;
    temp->x = t;
    return temp;
}

node* deleteHeadofCLL(node* head){
    if(!head) return nullptr;

    if(head->next == head){
        delete head;
        return nullptr;
    }
    head->x = head->next->x;
    node* temp = head->next;
    head->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return head;
}
node* deleteKthnodeFromCurrHeadCLL(node* head, int k /*1-based index*/){
    if(!head || k<=0) return head;

    // First, compute length of CLL
    int len = 1;
    node* temp = head->next;
    while (temp != head) {
        len++;
        temp = temp->next;
    }

    k = ((k - 1) % len) + 1;  // normalize k within [1, len]

    node* prev = nullptr;
    node* curr = head;
    while(k>1){
        k--;
        prev = curr;
        curr = curr->next;
    }
    if(!prev){
        if(curr->next == curr){
            delete curr;
            return nullptr;
        }else{
            curr->x = curr->next->x;
            node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return curr;
        }
    }else{
        prev->next = curr->next;
        delete curr;
        return head;
    }
}

node** head_ref;    /*For this recursive problem only*/
node* reverse_rec(node* head){
    if(!head) return nullptr;
    if(head->next == nullptr){
        (*head_ref) = head;
        return head;
    }
    node* temp = reverse_rec(head->next);
    temp->next = head;
    head->next = nullptr;
    return head;
}
node* reverseListTwoptr(node* head){
    node* curr = head;
    node* next = nullptr;
    while(curr->next != nullptr){   /*smart of moving just head ahead*/
        next = curr->next;
        curr->next = next->next;
        next->next = head;
        head = next;
    }
    return head;
}

node* utilityIntersec(node* head1, node* head2, int d){
    while(d>0){
        if(!head1) return nullptr;
        head1 = head1->next;
    }
    while(head1 != head2){
        if(head1==nullptr || head2 == nullptr) return nullptr;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}
node* findIntersectionofTwoLL(node* head1, node* head2){
    int c1 = 0, c2 = 0;
    node* t1 = head1, *t2 = head2;
    while(t1){
        c1++; t1 = t1->next;
    }
    while(t2){
        c2++; t2 = t2->next;
    }
    if(c1>c2){
        int d = c1-c2;
        return utilityIntersec(head1, head2, d);
    }else{
        int d = c2-c1;
        return utilityIntersec(head2, head1, d);
    }

    return nullptr;
}

node* insertatHeadCDLL(node* head, int data){ 
    if(!head){
        node* temp = new node();
        temp->x = data;
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    node* temp = new node();
    temp->x = data;
    temp->prev = head->prev;
    temp->next = head;
    head->prev->next = temp;
    head->prev = temp;
    return temp; /*Same code for insertion in the end we'll just return head here*/
}

node* sortedInsertLL(node* head, int data){
    node* curr=head, *prev = nullptr;
    while(curr && data > curr->x){
        prev = curr;
        curr = curr->next;
    }
    node* temp = new node();
    temp->x = data;
    temp->next = nullptr;
    if(!prev){
        temp->next = head;
        return temp;
    }
    temp->next = prev->next;
    prev->next = temp;
    return head;
}

node* middleofLL(node* head){
    node* curr = head;
    int len=0;
    while(curr){
        len++;
        curr = curr->next;
    }
    if(len==0) return nullptr;

    if(len%2){
        len = (len+1)/2;
    }else{
        len = len/2;
    }
    curr = head;
    while(len>1){
        curr = curr->next;
        len--;
    }
    return curr;
}
node* middleofLLeff(node* head){
    if(!head) return nullptr;
    node* slow = head, *fast = head->next;
    while(fast){
        if(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast = fast->next;
    }
    return slow;
}

node* NthFromEndLL(node* head, int n){
    if(!head) return head;
    int len=0;
    node* curr = head;
    while(curr){
        len++;
        curr = curr->next;
    }
    if(n > len) return nullptr;
    len -= n;
    curr = head;
    while(len>0){
        len--;
        curr = curr->next;
    }
    return curr;
}
node* NthFromEndLL_sec(node* head, int n){
    node* first = head;
    while(n-->0){
        if(!first) return first;
        first = first->next;
    }
    node* second = head;
    while(first){
        first = first->next;
        second = second->next;
    }

    return second;
}

node* recursiveReverseLL(node*head){
    if(!head) return nullptr;
    if(head->next == nullptr){
        return head;
    }
    node* nhead = recursiveReverseLL(head->next);
    node* t = head->next;
    t->next = head;
    head->next = nullptr;
    return nhead;
}

// Remove duplicates from sorted LL
node* removeDuplicatesfromSortedLL(node* head){
    node* curr = head;
    while(curr && curr->next){
        if(curr->x == (curr->next)->x){
            node* t = curr->next;
            curr->next = t->next;
            delete t;
        }else{
            curr = curr->next;
        }
    }
    return head;
}

// Reverse LL in groups of size k
node* reverseLLinGroupSizeK(node* head, int k){
    if(!head) return nullptr;
    node* prev = nullptr;
    node* curr = head;
    node* temp = nullptr;

    int cnt = 1;
    while(curr && cnt <= k){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }
    head->next = reverseLLinGroupSizeK(curr, k);
    return prev;
}

node* reverseLLinGroupSizeK_iter(node* head, int k){
    node* curr = head;
    node* prevFirst = NULL;
    bool isFirstpass = true;

    while(curr) {
        node* first = curr; node* prev = nullptr;
        int cnt = 0;
        while(curr && cnt < k){
            node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if(isFirstpass){
            head = prev;
            isFirstpass = false;
        }else{
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;
}

/*
class node {
  public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
    node* intersectpt(node* head){
        node* slow = head, * fast = head;
        
        while(fast && fast->next && slow){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return fast;
        }
        
        return nullptr;
    }
  public:
    void removeLoop(node* head) {
        // code here
        if(!head) return;
        
        node* second = intersectpt(head);
        if(!second) return;
        
        node* first = head;
        if(second==first){
            while(second->next != first) second = second->next;
            second->next = nullptr;
            return;
        }
        while(first->next != second->next){
            first = first->next;
            second = second->next;
        }
        
        second->next = nullptr;
        return;
    }
};

// Segregate even and odd nodes in a Linked List
node* seggregateEO(node* head){
    node* temp = head;
    node* eve=nullptr, *odd = nullptr;
    node* evehead=nullptr, *oddhead=nullptr;
    while(temp){
        if(temp->x&1){
            if(!oddhead){
                oddhead = temp;
                odd = temp;
            }else{
                odd->next = temp;
                odd = temp;
            }
        }else{
            if(!evehead){
                evehead = temp;
                eve = temp;
            }else{
                eve->next = temp;
                eve = temp;
            }
        }
        temp = temp->next;
        if(odd) odd->next = nullptr;
        if(eve) eve->next = nullptr;
    }
    if(!evehead) return oddhead;
    eve->next = oddhead;
    return evehead;
}

node* findYintersection(node* head1, node*head2){
    int l1=0, l2=0;
    node* t1=head1, *t2 = head2;
    while(t1){
        l1++;
        t1 = t1->next;
    }
    while(t2){
        l2++;
        t2 = t2 -> next;
    }
    if(l2>l1){
        swap(head1, head2);
        swap(l1, l2);
    }
    int addin = l1 - l2;
    while(addin--){
        if(!head1) return nullptr;
        head1 = head1->next;
    }
    while(head1 && head2 && head1 != head2){
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}

node* pairwiseSwap(node* head){
    if(!head || !head->next) return head;
    node* fast = head->next;
    node* slow = head;
    node* prev = nullptr;
    node* ans = fast;

    while(fast && slow){
        slow->next = fast->next;
        fast->next = slow;
        if(prev) prev->next = fast;
        prev = slow;
        slow = prev->next;
        if(slow) fast = slow->next;
    }
    if(slow && prev) prev->next = slow;
    return ans;
}

node* pairwiseSwap_rec(node* head){
    if(!head || !head->next) return head;
    node* first = head;
    node* second = head->next;

    first->next = pairwiseSwap_rec(second->next);
    second->next = first;
    return second;
}

node* pairwiseSwap_smp(node* head){
    if(!head || !head->next) return head;
    node* first = head; 
    node* second = head->next;

    while(first && second){
        swap(first->x, second->x);
        first = second -> next;
        if(first) second = first -> next;
    }
    return head;
}

node* cloneaLLwithRandomPointer(node* head){
    node* t = head;
    int x; node* next = nullptr;
    while(t){
        x = t->x;
        next = t->next;
        t->next = new node();
        t->next->x = x;
        t->next->next = next;
        t->next->random = nullptr;
        t = next;
    }

    t = head;
    while(t){
        if(t->random) t->next->random = t->random->next;
        t = t->next->next;
    }

    node* newhead = nullptr;
    node* curr = nullptr;
    t = head;
    while(t){
        if(!newhead){
            newhead = t->next;
            curr = t->next;
        }else{
            curr->next = t->next;
            curr = t->next;
        }
        t->next = t->next->next;
        t = t->next;
    }
    curr->next = nullptr;
    return newhead;
}
/*
Accumulate operation in Scheme is done over the entire list,
till the last procedure call returns the final values, which is
passed as a argument to the accumulate call.

// Sequences as a conventional interfaces: list return by one can be passed to another,
which is a beneficial way to handle problem using sequence of operations.
--------- This is not necessarily be efficient in terms of time and space. ---------

when we use sequences as interface, the major problem arises when we're looking for
some element withing a range but still we have to compute all elements in list till that range.
There is no early stop possible. 
Hence we can use lazy evaluation here, where elements are computed only when required.

Assignment breaks the substitution model, because the value of a variable can change over time.

We deal with infinite sequences using streams, where elements are computed lazily, only when required.
*/

// LRU Cache Design
void ImplementLRUCache(const vector<int>& accesstime, const int& maxCacheSize /*>1*/){
    unordered_map<int, node*> accessMap;
    int size = accesstime.size();
    node* head = new node();
    head->x = accesstime[0];
    accessMap[head->x] = head;
    node* tail = head;
    node* ptr;
    for(int i=1; i<size; i++){
        if(accessMap.find(accesstime[i]) != accessMap.end()){
            ptr = accessMap[accesstime[i]];
            node* nxt = ptr->next;
            node* pre = ptr->prev;
            if(tail == ptr){
                if(pre) tail = pre;
            }
            if(nxt){
                nxt->prev = pre;
            }
            if(pre){
                pre->next = nxt;
            }
        }else{
            if(accessMap.size() == maxCacheSize){
                node* pre = tail->prev;
                tail->prev = nullptr;
                pre->next = nullptr;
                accessMap.erase(tail->x);
                delete tail;
                tail = pre;
            }
            ptr = new node();
            ptr->x = accesstime[i];
            accessMap[ptr->x] = ptr;
        }
        if(ptr == head) continue;
        ptr->prev = nullptr;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
    }
}

int main(){
    node* head = nullptr;
    node* temp;
    int n, k; if(!(cin>>n)) exit(0);
    while(n--){
        cin >> k;
        if(head){
            temp->next = new node();
            temp->next->prev = temp;
            temp = temp->next;
            temp->x = k;
            temp->next = nullptr;
        }else{
            head = new node();
            head -> x = k;
            head -> next = nullptr;
            head -> prev = nullptr;
            temp = head;
        }
    }
    int cnt; cout << "Group size: "; cin >> cnt;
    temp = reverseLLinGroupSizeK(head, cnt);
    while(temp){
        // cout << temp->x << " ";
        cout << (*temp).x << " ";
        temp = temp->next;
    }
    // temp = middleofLLeff(head);
    // temp = NthFromEndLL(head, 5);
    // if(temp) cout << temp->x;
    cout << "\n";
}