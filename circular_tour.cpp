// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n) {
   // detect the impossible case first
   
   int total_petrol = 0, total_dist = 0;
   for (int i = 0; i < n; i++) {
       total_petrol += p[i].petrol;
       total_dist   += p[i].distance;
   }
   
   if (total_dist > total_petrol) {
       return -1;
   }
   
   int requirements[n];
   
   for (int i = 0; i < n; i++) {
       requirements[i] = p[i].petrol - p[i].distance;
   }
   
   int sum, idx = 0, point;
   while (idx < n) {
       point = idx;
       sum = requirements[idx++];
       while (sum >= 0 && idx < n) {
           sum += requirements[idx++];
       }
   }
   return point;
}


