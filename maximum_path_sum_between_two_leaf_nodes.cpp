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
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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

int maxPathSum(Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        cout << maxPathSum(root) << "\n";
    }
    return 0;
}// } Driver Code Ends


/*
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

// Sol1 O(n) time, O(H) space
// Assumption (after running the expected output code): there will be at least two leaf nodes
int recurseUtil(Node *root, int *path_sum) {
    int left_score = INT_MIN, right_score = INT_MIN;
    
    if (root -> left) left_score = recurseUtil(root -> left, path_sum);
    if (root -> right) right_score = recurseUtil(root -> right, path_sum);
    
    if (left_score != INT_MIN && right_score != INT_MIN)
        *path_sum = max(*path_sum, left_score + right_score + root -> data);
        
    if (left_score == INT_MIN && right_score == INT_MIN) return root -> data;
    if (left_score == INT_MIN && right_score != INT_MIN) return root -> data + right_score;
    if (left_score != INT_MIN && right_score == INT_MIN) return root -> data + left_score;
    else return max(root -> data + left_score, root -> data + right_score);
}

int maxPathSum(Node* root) {
    int ans = INT_MIN;
    recurseUtil(root, &ans);
    
    return ans;
}
