#include<bits/stdc++.h>
using namespace std;

/*
Basic implementation of LL, Circular LL, and Doubly LL
*/

// Linked list is a dynamic D.S.     we can expand and shrink run time.

/*
delete ptr; deallocates the memory pointed to by ptr but does not delete the pointer variable ptr.
After delete, ptr becomes a dangling pointer if not set to nullptr
*/

// Singly linked list

// class Node{
//     public:
//         int data_;
//         Node* next;
    
//         Node(int data=0): data_(data) {
//             this -> next = NULL;
//         }
//         ~Node(){
//             int value = this -> data_;
//             if(this->next != NULL){
//                 this -> next = NULL;     // make sure the ptr points to null before deletion.
//                 delete next;
//             }
//             cout << "Memory is free for node with data " << value << endl;
//         }
// };

// void insertAtHead(Node* &head, int d=0){

//     // New node creation
//     Node* temp = new Node(d);
//     temp -> next = head;
//     head = temp;
// }
// void insertAtTail(Node* &tail, int d=0){
//     Node* temp = new Node(d);
//     tail -> next = temp;
//     tail = temp;
// }
// void insertatPos(Node* &tail, Node* &head, int pos, int d=0){
//     if(pos==1){
//         insertAtHead(head,d);
//         return;
//     }
//     Node* temp = head;
//     int cnt = 1;
//     while(cnt < pos-1){
//         temp = temp -> next;
//         cnt++;
//     }
//     if(temp->next == NULL){
//         insertAtTail(tail, d);
//         return;
//     }
//     Node* mid = new Node(d);
//     mid -> next = temp -> next;
//     temp-> next = mid;
// }
// void deleteNode(Node* &head, Node* &tail, int pos){
//     // Deleting the start node
//     if(pos == 1){
//         Node* temp = head;
//         head = head -> next;
//         // temp -> next = NULL;
//         delete temp;
//         return;
//     }
//     Node* curr = head;
//     Node* prev = NULL;
//     int cnt = 1;
//     while(cnt < pos){
//         prev = curr;
//         curr = curr -> next;
//         cnt++;
//     }
//     prev -> next = curr -> next;
//     if(curr->next == NULL){
//         tail = prev;
//     }
//     delete curr;
//     return;
// }
// void printNode(Node* &head){
//     Node* temp = head;
//     while(temp!=NULL){
//         cout << temp -> data_ << endl;
//         temp = temp->next;
//     }
//     cout << endl;
// }
// int main(){
//     Node* a = new Node(4);
//     cout << a -> data_ << endl;
//     cout << a -> next << "NULL" << endl;
//     cout << "_______________________________________" << endl;

//     // head pointed to node1;
//     Node* head, *tail = a;
//     head = tail;
//     printNode(head);
//     cout << "___________________________________________" << endl;
//     insertAtHead(head, 23);
//     printNode(head);
//     insertAtTail(tail,56);
//     printNode(head);
//     insertatPos(tail,head,3,89);
//     printNode(head);

//     cout << "___________________________________________" << endl;
//     deleteNode(head, tail, 4);
//     printNode(head);
//     cout << "head : " << head -> data_ << endl;
//     cout << "tail : " << tail -> data_ << endl;
// }



//////////////////////////// Doubly Linked list
// class Node{
//     public:
//     int data_;
//     Node* prev;
//     Node* next;

//     // Constructor
//     Node(int d=0): data_(d) {
//         this-> prev = NULL;
//         this-> next = NULL;
//     }
//     ~Node(){
//         this -> next = NULL;
//         this -> prev = NULL;
//         delete next, prev;
//     }
// };
// void print(Node* &head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout << temp -> data_ << ' ';
//         temp = temp -> next;
//     }
//     cout << endl;
// }

// int getLength(Node* &head){
//     int len = 0;
//     Node* temp = head;
//     while(temp != NULL){
//         len++;
//         temp = temp -> next;
//     }
//     return len;
// }
// void insertAthead(Node* &head, int d=0){
//     Node* temp = new Node(d);
//     temp -> next = head;
//     head -> prev = temp;
//     head = temp;
// }
// void insertAtend(Node* &tail, int d=0){
//     Node* temp = new Node(d);
//     temp -> prev = tail;
//     tail -> next = temp;
//     tail = temp;
// }
// void insertAtpos(Node* &head, int pos, int d =0){
//     if(pos == 1){
//         insertAthead(head, d);
//         return;
//     }
//     int cnt = 1;
//     Node* temp = head;
//     Node* prevs = NULL;
//     while(cnt < pos){
//         prevs = temp;
//         temp = temp -> next;
//         cnt++;
//     }

//     Node* mid = new Node(d);
//     prevs->next = mid; mid -> prev = prevs;
//     mid->next = temp; temp -> prev = mid;
// }

// void deleteNode(int pos, Node* &head, Node* &tail){
//     Node* temp = head;
//     if(pos==1){
//         if(temp->next == NULL) {
//             delete temp;
//             temp = head = tail = nullptr;
//             return;
//         }
//         head = head->next;
//         head->prev = nullptr;
//         delete temp;
//         temp = nullptr;
//         return;
//     }
//     int cnt=1;
//     while(cnt < pos && temp != nullptr){
//         temp = temp->next;
//         cnt++;
//     }

//     if(temp == nullptr) return;

//     if(temp->next == NULL){
//         (temp -> prev) -> next = nullptr;
//         tail = temp->prev;
//         delete temp;
//         temp = nullptr;
//         return;
//     }
//     // Node* t = (temp -> next) -> prev;
//     // t = (temp -> prev) -> next;
//     // (temp -> prev) -> next = (temp -> next) -> prev;
//     (temp -> prev) -> next = temp->next;
//     (temp -> next) -> prev = temp -> prev;
//     delete temp;
//     temp = nullptr;
//     return;
// }
// int main(){
//     Node* node1 = new Node(10); 
//     Node* head = node1;
//     Node* tail = node1;

//     insertAthead(head, 11); /// Remember this code requires head to not pointing to the NULL for execution.
//     print(head);
//     insertAthead(head, 14);
//     print(head);

//     insertAthead(head, 8);
//     print(head);
    
//     insertAtend(tail, 34);
//     print(head);
//     cout << "head : " << head -> data_ << endl;
//     cout << "tail : " << tail -> data_ << endl;

//     insertAtpos(head,5,12);
//     print(head);
//     cout << "head : " << head -> data_ << endl;
//     cout << "tail : " << tail -> data_ << endl;

//     deleteNode(3 ,head, tail);
//     print(head);
//     cout << "head : " << head -> data_ << endl;
//     cout << "tail : " << tail -> data_ << endl;
// }


/////////////////////////// Circular linked list

class Node{
    public:
    int data_;
    Node* next;

    Node(int d=0): data_(d){
        this -> next = NULL;
    }
    ~Node(){
        if(this->next != NULL){
            this -> next = NULL;
            delete next;
            
        }
    }
};

void insertNode(Node* &tail,int e, int d=0){
    // Empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;  // pointing self
        return;
    }
    Node* curr = tail;
    while(curr -> data_ != e){  // we are supposing that given element is present in the nodes.
        curr = curr -> next;
    }

    // element found and curr is representing the node at which element is present.
    Node* temp = new Node(d);
    temp -> next = curr -> next;
    curr -> next = temp;
}
void print(Node* &tail){
    Node* temp = tail;
    if(temp == NULL){
        cout << "List is empty! " << endl;
        return;
    }
    do{
        cout << temp->data_ << ' ';
        temp = temp->next;
    }while(temp -> next != tail);
    if(temp->next != temp) cout << temp -> data_;
    cout << endl;
}
void deleteNode(Node* &tail, int e){
    Node* temp = tail;
    Node* prev = NULL;
    if(tail == NULL){
        cout << "List is empty, please check again! " << endl;
    }
    do{    // Assuming given element is present in the nodes.
        prev = temp;
        temp = temp -> next;
    }while(temp->data_ != e);
    
    if(prev->next == temp->next){
        tail = NULL;
        delete temp;
        return;
    }

    if(temp == tail){
        tail = temp->next;
    }
    
    prev -> next = temp -> next;
    temp -> next = NULL;
    delete temp;
    temp = NULL;
}

bool detectLoop(Node* head){
    if(head == NULL) return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while (temp != nullptr)
    {
        if(visited[temp]) return true;

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Floyd's cycle detection algorithm
Node* floydDetectionLoop(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(slow != NULL && fast  != NULL){
        fast = fast -> next;
        if(fast != nullptr){
            fast = fast->next;
        }
        slow = slow -> next;
        if(slow == fast) return slow;
    }
    return NULL;
}
// Assumes a loop is present.
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydDetectionLoop(head);
    Node* slow = head;

    while(slow!= intersection){
        slow = slow->next;
        intersection = intersection ->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL) return;
    Node* startOfloop = getStartingNode(head);
    Node* temp = startOfloop;
    while(temp -> next != startOfloop){
        temp = temp -> next;
    }
    temp->next = NULL;
}

int main(){
    Node* tail = NULL;
    insertNode(tail,-1, 5);
    // insertNode(tail, 5, 3);
    // insertNode(tail, 5, 7);
    // insertNode(tail, 3, 10);
    // insertNode(tail,10,8);
    // print(tail);
    // deleteNode(tail, 10);
    // print(tail);
    // deleteNode(tail, 5);
    // print(tail);
    // deleteNode(tail, 8);
    // print(tail);
    print(tail);
   
    deleteNode(tail, 5);
   
    print(tail);
}