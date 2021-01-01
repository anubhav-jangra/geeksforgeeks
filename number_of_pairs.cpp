// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 
 // } Driver Code Ends


 

// Function to count number of pairs such that x^y is greater than y^x
// X[], Y[]: input arrau
// m, n: size of arrays X[] and Y[] respectively
long long countPairs(int X[], int Y[], int m, int n)
{
   //Your code here
   sort(X, X+m); sort(Y, Y+n);
   long long ans = 0;
   
   int count0s_1 = 0, count1s_1 = 0, count0s_2 = 0, count1s_2 = 0, p1, p2;
   int count2s_1 = 0, count3s_1 = 0, count2s_2 = 0, count3s_2 = 0, count4s_2 = 0;
   for (int i = 0; i < m; i++) {
       if (X[i] == 0) {
           count0s_1++;
       } else if (X[i] == 1) {
           count1s_1++;
       } else {
           p1 = i;
           break;
       }
   }
   for (int i = 0; i < n; i++) {
       if (Y[i] == 0) {
           count0s_2++;
       } else if (Y[i] == 1) {
           count1s_2++;
       } else {
           p2 = i;
           break;
       }
   }
   for (int i = p1; i < m; i++) {
       if (X[i] == 2) {
           count2s_1++;
       } else if(X[i] == 3) {
           count3s_1++;
       } else {
           break;
       }
   }
   for (int i = p2; i < n; i++) {
       if (Y[i] == 2) {
           count2s_2++;
       } else if(Y[i] == 3) {
           count3s_2++;
       } else if(Y[i] == 4) {
           count4s_2++;
       } else {
           break;
       }
   }
   // cout << "1: <0-" << count0s_1 << ", 1-" << count1s_1 << "> 2: <0-" << count0s_2 << ", 1-" << count1s_2 << ">\n";
   
   // handle exception of 0
   ans += (count0s_2) * (m - count0s_1);
   // cout << "Pairs from 0s: " << ans << endl;
   
   // handle exception of 1
   ans += (count1s_2) * (m - count0s_1 - count1s_1);
   // cout << "Pairs from 1s: " << (count1s_2) * (m - count0s_1 - count1s_1) << endl;
   
   // Handle the case <2, 3>
   ans -= count2s_1 * count3s_2;
   // cout << "Pairs from <2, 3>: " << count2s_1 * count3s_2 << endl;
   
   // Handle the case <2, 4>
   ans -= count2s_1 * count4s_2;
   // cout << "Pairs from <2, 4>: " << count2s_1 * count4s_2 << endl;
   
   // Handle the case <3, 2>
   ans += count3s_1 * count2s_2;
   // cout << "Pairs from <3, 2>: " << count3s_1 * count2s_2 << endl;
   
   int j = p2;
   for (int i = p1; i < m && j < n; i++) {
       if (X[i] < Y[j]) {
            // cout << X[i] << ", " << Y[j] << endl;
           ans += (n-j); // since all elements after this in Y will be greater than X
       } else {
           j++; i--;
       }
   }
   return ans;
}


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends
