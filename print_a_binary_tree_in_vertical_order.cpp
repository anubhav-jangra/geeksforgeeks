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

vector <int> verticalOrder(Node *root);

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
    	Node* root = buildTree(s);
    	
    	vector <int> res = verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}


// } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child 
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

// Sol2

// Sol2 (using level order traversal), from editorial
vector<int> verticalOrder(Node *root) {
    if (!root) return vector<int>(0);
    
    queue<pair<Node *, int>> q;
    map<int, vector<int>> mp;
    
    q.push(make_pair(root, 0));
    
    pair<Node *, int> temp;
    
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        mp[temp.second].push_back(temp.first -> data);
        
        if (temp.first -> left) q.push(make_pair(temp.first -> left, temp.second - 1));
        if (temp.first -> right) q.push(make_pair(temp.first -> right, temp.second + 1));
    }
    
    vector<int> ans;
    
    for (auto &it : mp)
        for (int i = 0; i < it.second.size(); i++)
            ans.push_back(it.second[i]);
    
    return ans;
}
// Sol1 using map of map of vectors ;)
/*
void verticalOrderUtil(Node *root, int lr_val, int depth, map<int, map<int, vector<int>>> &mp) {
    if (!root) return;
    
    mp[lr_val][depth].push_back(root -> data);
    
    verticalOrderUtil(root -> left, lr_val - 1, depth + 1, mp);
    
    verticalOrderUtil(root -> right, lr_val + 1, depth + 1, mp);
}

// root: root node of the tree
vector<int> verticalOrder(Node *root) {
    map<int, map<int, vector<int>>> mp;
    
    verticalOrderUtil(root, 0, 0, mp);
    
    vector<int> ans;
    
    for (auto iter = mp.begin(); iter != mp.end(); iter++) // lr_val
        for (auto &it : iter -> second) // depth
            for (int i = 0; i < it.second.size(); i++) // all values at same depth
                ans.push_back(it.second[i]);
            
    return ans;
}
*/

// Failed attempt 1: issue occurs when multiple same level elements have different values. 
// Fail case: 20 8 22 5 4 3 25 N N 10 11 N 14
/*
void verticalOrderUtil(Node *root, int lr_val, int depth, map<int, set<pair<int, int>>> &mp) {
    if (!root) return;
    
    mp[lr_val].insert(make_pair(depth, root -> data));
    
    verticalOrderUtil(root -> left, lr_val - 1, depth + 1, mp);
    
    verticalOrderUtil(root -> right, lr_val + 1, depth + 1, mp);
}

// root: root node of the tree
vector<int> verticalOrder(Node *root) {
    map<int, set<pair<int, int>>> mp;
    
    verticalOrderUtil(root, 0, 0, mp);
    
    vector<int> ans;
    
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
        for (auto &it : iter -> second)
            ans.push_back(it.second);
            
    return ans;
}
*/

