// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
    int counter;
public: 
    void serializeUtil(Node *root, vector<int> &ans) {
        if (root -> left) {
            ans.push_back(root -> left -> data);
            serializeUtil(root -> left, ans);
        } else ans.push_back(-1);
        
        if (root -> right) {
            ans.push_back(root -> right -> data);
            serializeUtil(root -> right, ans);
        } else ans.push_back(-1);
    }
    
    vector<int> serialize(Node *root) {
        if (!root) return vector<int>(0);
        
        vector<int> ans;
        ans.push_back(root -> data);
        serializeUtil(root, ans);
        
        // for (int i = 0; i < ans.size(); i++)
        //     cout << ans[i] << " ";
        // cout << endl;
        
        return ans;
    }

    void deSerializeUtil(vector<int> &A, Node *root) {
        if (A[counter] == -1) counter++; // left node
        else {
            root -> left = new Node(A[counter++]);
            deSerializeUtil(A, root -> left);
        }
        if (A[counter] == -1) counter++; // right node
        else {
            root -> right = new Node(A[counter++]);
            deSerializeUtil(A, root -> right);
        }
    }
    
    Node *deSerialize(vector<int> &A) {
        counter = 1;
        if (A[0] == -1) return nullptr;
        
        Node *root = new Node(A[0]);
        deSerializeUtil(A, root);
        return root;
    }

};

// Failed attempt 2
/*
class Solution {
private:
    //int arr_len = 0;

public:    
    vector<int> serialize(Node *root) {
        // we'll use level order traersal to solve this problem
        if (!root) return vector<int>(0);
        
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 1));
        
        vector<int> ans(1001, 0);
        ans[1] = root -> data;
        
        pair<Node *, int> temp;
        int counter = 0, k, curr_lvl = 0;
        
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            
            k = temp.second;
            // cout << temp.first -> data << " k: " << k << endl;
            if (curr_lvl < k) {
                curr_lvl = k;
                counter = 0;
            }
            if (temp.first -> left) {
                q.push(make_pair(temp.first -> left, k + 1));
                ans[(int) pow(2, k) + counter++] = temp.first -> left -> data;
            } else {
                ans[(int) pow(2, k) + counter++] = 0;
            }
            if (temp.first -> right) {
                q.push(make_pair(temp.first -> right, k + 1));
                ans[(int) pow(2, k) + counter++] = temp.first -> right -> data;
            } else {
                ans[(int) pow(2, k) + counter++] = 0;
            }
            // arr_len = max((int) pow(2, k) + counter, arr_len);
        }
        
        // cout << "ans_Arr: ";
        // for (int i = 0; i <= arr_len; i++) cout << ans[i] << " ";
        // cout << endl;
        
        return ans;
    }

    Node * deSerialize(vector<int> &A) {
        Node *ans;
        
        if (A[1] == 0) return nullptr; // edge case
        
        ans = new Node(A[1]);
        queue<pair<Node *, int>> q;
        q.push(make_pair(ans, 1));
        pair<Node *, int> temp;
        
        for (int i = 2; !q.empty(); i += 2) {
            temp = q.front();
            // cout << "i: " << i << " " << (int) pow(2, temp.second) << endl;
            if (i >= (int) pow(2, temp.second)) {
                q.pop();
            
                if (A[i] != 0) {
                   temp.first -> left = new Node(A[i]);
                   // cout << "Setting left val as: " << temp.first -> left -> data << endl;
                   q.push(make_pair(temp.first -> left, temp.second + 1));
                }
                
                if (A[i + 1] != 0) {
                   temp.first -> right = new Node(A[i + 1]);
                   // cout << "Setting right val as: " << temp.first -> right -> data << endl;
                   q.push(make_pair(temp.first -> right, temp.second + 1));
                }
            }
        }
        
        return ans;
    }

};
*/

// Failed sol1, since this way, the tree order will not be preserved!
/*
class Solution{
public:    
    vector<int> serialize(Node *root) {
        // we'll use level order traersal to solve this problem
        if (!root) return vector<int>(0);
        
        queue<Node *> q;
        q.push(root);
        
        vector<int> ans;
        while(!q.empty()) {
            root = q.front();
            q.pop();
            
            ans.push(root -> data);
            
            if (root -> left) q.push(root -> left);
            if (root -> right) q.push(root -> right);
        }
        
        return ans;
    }

    Node * deSerialize(vector<int> &A) {
       Node *ans;
       for (int i = 0; i < A.size(); i++) {
           
       }
    }

};
*/

// { Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    /* first delete both subtrees */
    _deleteTree(node->left);  
    _deleteTree(node->right);  
  
    /* then delete the node */
    //cout << "Deleting node: " << node->data << endl;  
    delete node;  
}  
  
/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        
        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        cout << "\n";

    }


    return 0;
}  // } Driver Code Ends
