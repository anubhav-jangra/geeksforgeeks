// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    cout << isBST(root) << endl;
   }
   return 0;
}



 // } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Sol2 (from hint)
bool util(Node* root, int min_val, int max_val) {
    if (!root) return true;
    
    if (root -> left) {
        if (max_val <= root -> left -> data || min_val >= root -> left -> data) return false;
        if (root -> data <= root -> left -> data) return false;
        if (!util(root -> left, min_val, min(root -> data, max_val))) return false;
    }
    
    if (root -> right) {
        if (max_val <= root -> right -> data || min_val >= root -> right -> data) return false;
        if (root -> data >= root -> right -> data) return false;
        if (!util(root -> right, max(min_val, root -> data), max_val)) return false;
    }
    
    return true;
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    return util(root, INT_MIN, INT_MAX);
}

// Sol1 (done myself ;))
/*
bool util(Node* root, int parent_val, int isLeft) {
    if (!root) return true;
    
    if (root -> left) {
        if (isLeft == 1 && parent_val <= root -> left -> data) return false;
        if (isLeft == 2 && parent_val >= root -> left -> data) return false;
        if (root -> data <= root -> left -> data) return false;
        if (!util(root -> left, ((isLeft == 0) ? root -> data : max(root -> data, parent_val)), 1)) return false;
    }
    
    if (root -> right) {
        if (isLeft == 1 && parent_val <= root -> right -> data) return false;
        if (isLeft == 2 && parent_val >= root -> right -> data) return false;
        if (root -> data >= root -> right -> data) return false;
        if (!util(root -> right, ((isLeft == 0) ? root -> data : min(root -> data, parent_val)), 2)) return false;
    }
    
    return true;
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    return util(root, 0, 0);
}
*/



// { Driver Code Starts
  // } Driver Code Ends
