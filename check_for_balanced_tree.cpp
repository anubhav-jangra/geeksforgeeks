// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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

bool isBalanced(Node *root);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        cout << isBalanced(root) << endl;
    }
    return 1;
}// } Driver Code Ends


/* A binary tree node structure

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

// This function should return tree if passed  tree 
// is balanced, else false. 

// Sol2 (from hints && Full Sols) : O(n) time and O(h) space
bool recurse(Node *root, int *h) {
    int l_h = 0, r_h = 0;
    
    bool l_ans = true, r_ans = true;
    if (root -> left)
        l_ans = recurse(root -> left, &l_h);
    if (root -> right)
        r_ans = recurse(root -> right, &r_h);
    
    *h = max(l_h, r_h) + 1;
    
    if (abs(l_h - r_h) <= 1 && l_ans && r_ans)
        return true;
    return false;
}


bool isBalanced(Node *root) {
    int h = 0;
    return recurse(root, &h);
}
// Sol 1 O(n2) time, O(h) space
/*
int max_height(Node *root, int curr_h) {
    if (!root) return 0;
    return 1 + max(root -> left ? max_height(root -> left, curr_h  + 1) : 0, 
                   root -> right ? max_height(root -> right, curr_h  + 1) : 0);
}

bool isBalanced(Node *root) {
    if (!root) return true;
    
    if (abs(max_height(root -> left, 0) - max_height(root -> right, 0)) <= 1 && isBalanced(root -> left) && isBalanced(root -> right))
        return true;
    return false;
}
*/

// Failed Sol1
/*
int utilFunc(Node *root, bool *ans, int curr_h) {
    if (!ans) return 0;
    if (!root) return 0;
    
    int l_h = utilFunc(root -> left, ans, curr_h + 1);
    int r_h = utilFunc(root -> right, ans, curr_h + 1);
    
    if (!ans) return 0;
    
    if (l_h - r_h > 1) {
        *ans = false;
    }
    
    return 1 + max(l_h, r_h);
}

bool isBalanced(Node *root) {
    bool ans = true;
    utilFunc(root, &ans, 0);
    return ans;
}
*/
