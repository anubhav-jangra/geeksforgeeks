// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string str) {
    int ans = 0, counter = 1;
    
    string nums = "0123456789";
    
    for (int i = str.length()-1; i >= 0; i--) {
        if (i == 0 && str[i] == '-') return ans * -1;
        if (nums.find(str[i]) == string :: npos) return -1;
        ans += (str[i] - '0') * counter;
        counter *= 10;
    }
    
    return ans;
}
