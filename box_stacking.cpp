// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends


/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

typedef struct Box {
    int l, b, h;
    
    Box(int l, int b, int h) : l(l), b(b), h(h) {};
} Box;

bool customSort(Box a1, Box a2) {
    return a1.l + a1.b < a2.l + a2.b; // both area and perimeter work well
}

// bool customSort(Box a1, Box a2) {
//     if (a1.l == a2.l) {
//         if (a1.b == a2.b) return a1.h < a2.h;
//         return a1.b < a2.b;
//     }
//     return a1.l < a2.l;
// }

int maxHeight(int height[],int width[],int length[],int n) {
    vector<Box> data;
    
    for (int i = 0; i < n; i++) {
        data.push_back(Box(length[i], height[i], width[i]));
        data.push_back(Box(height[i], length[i], width[i]));
        
        data.push_back(Box(width[i], length[i], height[i]));
        data.push_back(Box(length[i], width[i], height[i]));
        
        data.push_back(Box(height[i], width[i], length[i]));
        data.push_back(Box(width[i], height[i], length[i]));
    }
    
    sort(data.begin(), data.end(), customSort);
    
    // for (int i = 0; i < data.size(); i++)
    //     cout << "(" << data[i].l << ", " << data[i].b << ", " << data[i].h << ") ";
    // cout << endl;
    
    vector<int> dp(data.size(), -1);
    
    for (int i = 0; i < data.size(); i++) {
        dp[i] = data[i].h;
        for (int j = 0; j < i; j++)
            if (data[j].l < data[i].l && data[j].b < data[i].b)
                dp[i] = max(dp[i], dp[j] + data[i].h);
    }
    
    // for (int i = 0; i < data.size(); i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    
    return *max_element(dp.begin(), dp.end());
    
}
