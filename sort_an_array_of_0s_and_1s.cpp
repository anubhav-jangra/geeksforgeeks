// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    int j = -1, k = n;
    for (int i = 0; i < k; i++) {
        if (a[i] == 2) {
            swap(a[--k], a[i--]);
        } else if (a[i] == 0) {
            swap(a[++j], a[i]);
        }
    }
}
