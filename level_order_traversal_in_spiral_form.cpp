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

vector<int> findSpiral(Node *root);

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


int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for(int x : vec)
        cout<<x<<" ";
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
}; */

vector<int> findSpiral(Node *root) {
    if (!root) return vector<int>(0);
    
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    pair<Node *, int> temp;
    
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        if(temp.first -> left) q.push(make_pair(temp.first -> left, temp.second+1));
        if(temp.first -> right) q.push(make_pair(temp.first -> right, temp.second+1));
        
        if (temp.second % 2 == 1)
            mp[temp.second].push_back(temp.first -> data);
    }
    
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        if(temp.first -> right) q.push(make_pair(temp.first -> right, temp.second+1));
        if(temp.first -> left) q.push(make_pair(temp.first -> left, temp.second+1));
        
        if (temp.second % 2 == 0)
            mp[temp.second].push_back(temp.first -> data);
    }
    
    vector<int> ans;
    for (auto &it : mp)
        for (int i = 0; i < it.second.size(); i++)
            ans.push_back(it.second[i]);
    
    return ans;
}

// Failed attempt 1
/*
vector<int> findSpiral(Node *root) {
    if (!root) return vector<int>(0);
    
    vector<int> ans;
    
    queue<pair<Node *, int>> q;
    
    q.push(make_pair(root, 0));
    
    pair<Node *, int> temp;
    
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        ans.push_back(temp.first -> data);
        
        if (temp.second % 2 == 0) {
            if(temp.first -> left) q.push(make_pair(temp.first -> left, temp.second+1));
            if(temp.first -> right) q.push(make_pair(temp.first -> right, temp.second+1));
        } else {
            if(temp.first -> right) q.push(make_pair(temp.first -> right, temp.second+1));
            if(temp.first -> left) q.push(make_pair(temp.first -> left, temp.second+1));
        }
    }
    
    return ans;
}
*/
