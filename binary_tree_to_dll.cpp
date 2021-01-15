// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
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


Node* bToDLL(Node *root);


/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
   if (root != NULL)
   {
       inorder(root->left);
       cout << root->data;
       inorder(root->right);
   }
}

/* Driver program to test size function*/
int main()
{
  int t;
  cin >> t;
  getchar();
  
  while (t--)
  {
     string inp;
     getline(cin, inp);
     Node *root = buildTree(inp);
     
      
     Node *head = bToDLL(root);
     printList(head);

  }
  return 0;
}

// } Driver Code Ends


/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Sol2 (after peeking at editorials) : O(n) time and O(H) space
Node *prev_node;
void recurse(Node *root) { // lr_val 0: left, 1: root
    
    if (root -> left) recurse(root -> left);
    
    if (prev_node) {
        prev_node -> right = root;
        root -> left  = prev_node;
    }
    prev_node = root;
    
    if (root -> right) recurse(root -> right);
}

Node * bToDLL(Node *root) {
    if (!root) return nullptr;
    
    prev_node = nullptr;
    recurse(root);
    
    while (prev_node -> left) 
        prev_node = prev_node -> left;
    return prev_node;
    
}

// Sol1 O(n2) time (I think), and O(H) auxilary space
/*
// this util function assums that root is not null!
Node *recurse(Node *root, bool lr_val) { // lr_val 0: left, 1: root
    if (root -> left) {
        Node *l_node = recurse(root -> left, false);
        l_node -> right = root;
        root -> left = l_node;
    }
    
    if (root -> right) {
        Node *r_node = recurse(root -> right, true);
        // cout << "r_node: " << r_node -> data << endl;
        root -> right = r_node;
        r_node -> left = root;
    }
    
    Node *temp = root;
    // return wisely
    if (lr_val) { // right, hence return the beginning of the DLL
        while (temp -> left) 
            temp = temp -> left;
        return temp;
    } else { // left, hence return the end of the list
        while (temp -> right)
            temp = temp -> right;
        return temp;
    }
}

// This function should return head to the DLL
Node * bToDLL(Node *root) {
    if (!root) return nullptr;
    
    return recurse(root, true); // since we need beginning of the DLL, we chose the right setting ;)
}

*/
