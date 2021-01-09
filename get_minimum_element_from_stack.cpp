// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

// Sol2 (after looking at the hint)

// returns min element from stack
int _stack :: getMin()
{
   return s.empty() ? -1 : minEle;
}

// returns poped element from stack
int _stack :: pop()
{
   if (s.empty())
       return -1;
   int temp = s.top();
   if (temp >= minEle) {
       s.pop();
       return temp;
   }
   temp = minEle;
   minEle = 2*minEle - s.top();
   s.pop();
   return temp;
}

// push element x into the stack
void _stack::push(int x)
{
   if (s.empty()) {
       minEle = x;
       s.push(x);
   } else if (minEle > x) {
       s.push(2*x - minEle);
       minEle = x;
   } else {
       s.push(x);
   }
   
}


// Sol1 (Cheat), since it is O(n) time and space in worst case; passes the question thought :/
/*

// returns min element from stack
int _stack :: getMin()
{
   return s.empty() ? -1 : minEle;
}

// returns poped element from stack
int _stack :: pop()
{
   if (s.empty())
       return -1;
   int temp = s.top();
   s.pop();
   if (temp == minEle) {
        stack<int> stk = s;
        minEle = INT_MAX;
        while (!stk.empty()) {
            if (stk.top() < minEle)
                minEle = stk.top();
            stk.pop();
        }
   }
   return temp;
}

// push element x into the stack
void _stack::push(int x)
{
   if (s.empty()) {
       minEle = x;
   } else if (minEle > x) {
       minEle = x;
   }
   s.push(x);
}
*/
