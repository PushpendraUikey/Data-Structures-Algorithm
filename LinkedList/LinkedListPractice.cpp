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

    // temp = reverse(head);
    // while(temp){
    //     // cout << temp->x << " ";
    //     cout << (*temp).x << " ";
    //     temp = temp->next;
    // }
    temp = middleofLLeff(head);
    if(temp) cout << temp->x;
    cout << "\n";
}