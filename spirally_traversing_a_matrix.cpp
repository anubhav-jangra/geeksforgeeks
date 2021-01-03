// { Driver Code Starts

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

// Sol1 style2
class Solution {   
public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        int i, right_bound = c-1, bottom_bound = r-1, left_bound = 0, up_bound = 0;
        vector<int> ans;
        while (left_bound <= right_bound && up_bound <= bottom_bound) {
            // cout << left_bound << " " << right_bound << " " << up_bound << " " << bottom_bound << endl;
            // Going right
            for (i = left_bound; i <= right_bound; i++)
                ans.push_back(matrix[up_bound][i]);
            up_bound++;
            
            // Going down
            if (left_bound <= right_bound) {
                for (i = up_bound; i <= bottom_bound; i++)
                    ans.push_back(matrix[i][right_bound]);
                right_bound--;
            }
            
            // Going left
            if (up_bound <= bottom_bound) {
                for (i = right_bound; i >= left_bound; i--)
                    ans.push_back(matrix[bottom_bound][i]);
                bottom_bound--;
            }
            
            // Going up
            if (left_bound <= right_bound) {
                for (i = bottom_bound; i >= up_bound; i--)
                    ans.push_back(matrix[i][left_bound]);
                 left_bound++;
            }
        } // Repeating the same
        return ans;
    }
};

// Sol1 style1
/*
class Solution {   
public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        int i, right_bound = c-1, bottom_bound = r-1, left_bound = 0, up_bound = 0;
        vector<int> ans;
        while (left_bound <= right_bound && up_bound <= bottom_bound) {
            // cout << left_bound << " " << right_bound << " " << up_bound << " " << bottom_bound << endl;
            // Going right
            for (i = left_bound; i <= right_bound; i++)
                ans.push_back(matrix[up_bound][i]);
            up_bound++;
            
            if (left_bound > right_bound || up_bound > bottom_bound)
                break;
            
            // Going down
            for (i = up_bound; i <= bottom_bound; i++)
                ans.push_back(matrix[i][right_bound]);
            right_bound--;
            
            if (left_bound > right_bound || up_bound > bottom_bound)
                break;
            
            // Going left
            for (i = right_bound; i >= left_bound; i--)
                ans.push_back(matrix[bottom_bound][i]);
            bottom_bound--;
            
            if (left_bound > right_bound || up_bound > bottom_bound)
                break;
            
            // Going up
            for (i = bottom_bound; i >= up_bound; i--)
                ans.push_back(matrix[i][left_bound]);
             left_bound++;
        } // Repeating the same
        return ans;
    }
};
*/

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
