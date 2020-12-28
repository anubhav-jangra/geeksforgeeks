/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

int init_k;
struct node *successor;
struct node *func (struct node *head, int k) {
    if (!head || !head->next) 
        return head;
    
    if (k == 1) {
        successor = func(head -> next, init_k);
        return head;
    }
    
    struct node *temp = func(head -> next, k-1);
    head -> next -> next = head;
    head -> next = successor;
    return temp;
}

struct node *reverse (struct node *head, int k)
{ 
    successor = nullptr;
    init_k = k;
    return func(head, k);
}

