/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node* rotate(Node* head, int k)
{
    Node *temp1 = head, *temp2, *ans;
    // find the split point
    for (int i = 1; i < k; i++) {
        temp1 = temp1 -> next;
    }
    // now go to the end
    temp2 = temp1 -> next;
    temp1 -> next = nullptr;
    ans = temp2; // to return the answer
    
    if (!temp2)
        return head;
        
    while (temp2 -> next) {
        temp2 = temp2 -> next;
    }
    temp2 -> next = head;
    return ans;
}

