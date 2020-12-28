// { Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

// Sol2 O(n) time complexity
void removeLoop(Node* head)
{
    Node *ptr1 = head, *ptr2 = head, *temp;
    do {
        if (!ptr2 || !ptr2 -> next) {
            return; // no loop, hence just return
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
    } while (ptr1 != ptr2);
    
    // there is a loop present
    
    // find the size of the loop
    int size = 0;
    do {
        ptr1 = ptr1 -> next;
        size++;
    } while (ptr1 != ptr2);
    
    // cout << "size is: " << size << endl;
    
    // now one final pass to find the connection to be broken
    ptr1 = head;
    ptr2 = head;
    while (size > 0) {
        ptr2 = ptr2 -> next;
        size--;
    }
    // cout << "ptr2 is: " << ptr2 -> data << endl;
    while (ptr1 != ptr2) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    };
    
    do {
        ptr2 = ptr2 -> next;
    } while (ptr2 -> next != ptr1);
    
    ptr2 -> next = nullptr; // break the connection
    
}


// Sol1 unoptimized O(n2)
/*
void removeLoop(Node* head)
{
    Node *ptr1 = head, *ptr2 = head, *temp;
    do {
        if (!ptr2 || !ptr2 -> next) {
            return; // no loop, hence just return
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
    } while (ptr1 != ptr2);
    
    // there is a loop present
    ptr1 = head; // lets find the place of loop connection one step at a time
    temp = ptr2; // any pointer in the loop
    while (temp -> next != ptr1) { 
        // cout << "ptr1 is: " << ptr1 -> data << endl;
        do {
            if (temp -> next == ptr1) { // found the link to be broken
                temp -> next = nullptr;
                return;
            }
            temp = temp -> next;
        } while (temp != ptr2); // check for one lap (since initially both are same)
        ptr1 = ptr1 -> next;
    }
    temp -> next = nullptr;
}
*/
