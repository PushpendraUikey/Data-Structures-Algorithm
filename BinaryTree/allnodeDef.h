
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode<T> *parent;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    ~BinaryTreeNode() {
        if(left) 
            delete left;
        if(right) 
            delete right;
        if(parent)
            delete parent;
    }
};


template <typename T>
class TreeNode {
    public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
template <typename T>
class TreeNode{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};
template <typename T = int>
class TreeNode{
    public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d): data(d), left(NULL), right(NULL) { }
};

struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
};