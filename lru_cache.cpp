// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

// Sol1 
struct ListNode {
    int val;
    ListNode *next;
    // ListNode *prev;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode (int x) : val(x), next(nullptr) {}
    ListNode (int x, ListNode *nxt) : val(x), next(nxt) {}
};

class LRUCache {
private:
    int capacity;
    int list_size;
    ListNode *head, *last_node; // head contains least visited node;
    unordered_map<int, int> info;
public:
    LRUCache(int cap) {
        // constructor for cache
        capacity = cap;
        head = nullptr; last_node = nullptr;
    }
    
    // a function that takes a value, and then places it at the end of the LL
    void place_on_back(int key) {
        if (key == last_node -> val) // already in position
            return;
        
        ListNode *temp = new ListNode(-100, head);
        if (temp -> next -> val == key) { // head is the key!
            if (head -> next)
                head = head -> next;
            else {
                // shouldn't happen since head == last_node == key!
                cout << "\nBazinga!\n";
            }
        }

        while (temp -> next -> val != key)
            temp = temp -> next;
        
        ListNode *temp2 = temp -> next;
        temp -> next = temp -> next -> next;
        // temp -> next -> prev = temp;
        temp2 -> next = nullptr;
        
        while (temp -> next) 
            temp = temp -> next;
            
        temp -> next = temp2;
        // temp2 -> prev = temp;
        last_node = temp2;
    }
    
    int get(int key) {
        // this function should return value corresponding to key
        if (info.find(key) == info.end()) {
            return -1;
        } else {
            place_on_back(key);
            return info[key];
        }
    }
    
    void set(int key, int value) {
        // storing key, value pair
        
        if (info.find(key) != info.end()) {
            place_on_back(key);
            info[key] = value;
            return;
        }
        if (list_size == capacity) {
            int remove_key = head -> val;
            if (head == last_node) {
                head = nullptr; last_node = nullptr;
            } else {
                head = head -> next;
            }
            list_size--;
            info.erase(remove_key);
        }
        if (!last_node) {
          head = new ListNode(key);
          last_node = head;
        } else {
          last_node -> next = new ListNode(key);
          last_node = last_node -> next;
        }
        list_size++;
        info[key] = value;
    }
};

// Failed Sol2: An O(n) time, and O(n) space simple solution
/*
class LRUCache {
private:
    int capacity;
    int idx;
    queue<int> q;
    queue<int> q2;
    unordered_map<int, int> info;
public:
    LRUCache(int cap) {
        // constructor for cache
        capacity = cap;
        idx = 0;
    }
    
    void print_info() {
        for (auto iter : info) {
            cout << "<" << iter.first << ", " << iter.second << "> ";
        }
        cout << " || ";
        q2 = q;
        while (!q2.empty()) {
            cout << q2.front() << " ";
            q2.pop();
        }
        cout << " || ";
    }
    
    // a function that takes a value, and then places it at the end of a queue
    void place_on_back(int key) {
        while (q.front() != key) {
            q2.push(q.front());
            q.pop();
        }
        int temp = q.front();
        q.pop();
        while(!q.empty()) {
            q2.push(q.front());
            q.pop();
        }
        while(!q2.empty()) {
            q.push(q2.front());
            q2.pop();
        }
        q.push(temp);
    }
    
    int get(int key) {
        // this function should return value corresponding to key
        
        // cout << "\nidx: " << idx++ << " ";
        // print_info();
        // cout << key << " -> ";
        if (info.find(key) == info.end()) {
            return -1;
        } else {
            place_on_back(key);
            return info[key];
        }
    }
    
    void set(int key, int value) {
        // storing key, value pair
        
        if (info.find(key) != info.end()) {
            place_on_back(key);
            info[key] = value;
            return;
        }
        if (q.size() == capacity) {
            int remove_key = q.front();
            q.pop();
            info.erase(remove_key);
        }
        q.push(key); // already on the back
        info[key] = value;
    }
};
*/

// Failed sol1 (I knew it wouldn't work, still gave it a shor :} )
/*
class LRUCache {
private:
    int capacity;
    queue<int> q;
    unordered_map<int, int> info;
public:
    LRUCache(int cap) {
        // constructor for cache
        capacity = cap;
    }
    
    int get(int key) {
        // this function should return value corresponding to key
        return (info.find(key) == info.end()) ? -1 : info[key];
    }
    
    void set(int key, int value) {
        // storing key, value pair
        if (q.size() == capacity) {
            int remove_key = q.front();
            q.pop();
            info.erase(remove_key);
        }
        q.push(key);
        info[key] = value;
    }
};
*/


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Endss