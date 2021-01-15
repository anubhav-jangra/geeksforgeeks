// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* nextRight;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->nextRight = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void connect(struct Node *p);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */


void printSpecial(Node *root)
{
   if (root == NULL)
     return;

   Node* next_root=NULL;

   while (root != NULL)
   {
      cout<< root->data<<" ";

      if( root->left && (!next_root) )
        next_root = root->left;
      else if( root->right && (!next_root)  )
        next_root = root->right;

      root = root->nextRight;
   }
   
   printSpecial(next_root);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     string s;
     getline(cin, s);
     Node* root = buildTree(s);

     connect(root);
     printSpecial(root);
     cout<<endl;
     inorder(root);
     cout<<endl;
  }
  return 0;
}
// } Driver Code Ends


/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes

// Sol2 O(n) time, O(1) space (after goinf through the editorial)

// a function to return the next left child of nodes at the same level as p
// This can be used to find the next connection for a node's right element, or left's in case the right element does not exist
Node *getNextRight(Node *p) {
    Node *temp = p -> nextRight;
    
    while (temp) {
        if (temp -> left) return temp -> left;
        if (temp -> right) return temp -> right;
        temp = temp -> nextRight;
    }
    
    return nullptr;
}

void connect(Node *p) {
    if (!p) return;
    
    p -> nextRight = nullptr;
    
    Node *q;
    // traverse one level at a time
    while (p) {
        q = p;
        
        // iterate over all the elements at that level
        while (q) {
            if (q -> left) {
                if (q -> right) q -> left -> nextRight = q -> right;
                else q -> left -> nextRight = getNextRight(q);
            }
            
            if (q -> right) 
                q -> right -> nextRight = getNextRight(q);
                
            q = q -> nextRight;
        }
        
        if (p -> left) p = p -> left;
        else if (p -> right) p = p -> right;
        else p = getNextRight(p);
    }
}

// Sol1 (level order traversal) O(n) time and O(n) space (for maintaining the queue)
/*
void connect(Node *p) {
   
   // handle the edge case
   if (!p) return;
   
   queue<pair<Node *, int>> q; // to store the node and depth
   
   q.push(make_pair(p, 0));
   
   pair<Node *, int> temp;
   
   while(!q.empty()) {
       temp = q.front();
       q.pop();
       
       if (q.empty()) temp.first -> nextRight = nullptr;
       else if (q.front().second != temp.second) temp.first -> nextRight = nullptr;
       else temp.first -> nextRight = q.front().first;
       
       if (temp.first -> left) q.push(make_pair(temp.first -> left, temp.second + 1));
       if (temp.first -> right) q.push(make_pair(temp.first -> right, temp.second + 1));
   }
}
*/
