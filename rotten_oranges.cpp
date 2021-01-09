// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively

// Sol1 - after seeing the hint
int rotOranges(vector<vector<int> > &matrix, int R, int C) {
    vector<vector<int> > rotSheet = matrix; // to store the current updates
    queue<pair<int, int> > rotten;
    int i, j, ans = -1;
    
    // add the already rotten 
    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++)
            if (matrix[i][j] == 2) 
                rotten.push(make_pair(i, j));
    
    while (!rotten.empty()) {
        
        rotten.push(make_pair(-1, -1)); // a delimiter notifying that new time stamp will take place from this point onwards
        ans++;
        
        while (rotten.front() != pair<int, int>(-1, -1)) {
            // rot the nearby oranges in a BFS manner
            
            i = rotten.front().first;
            j = rotten.front().second;
            // cout << "<" << i << ", " << j << ">\n";
            rotten.pop();
            
            // check left
            if (i-1 >= 0 && rotSheet[i-1][j] == 1) {
                rotSheet[i-1][j] = 2;
                rotten.push(make_pair(i-1, j));
            }
            
            // check right
            if (i+1 < R && rotSheet[i+1][j] == 1) {
                rotSheet[i+1][j] = 2;
                rotten.push(make_pair(i+1, j));
            }
            
            // check up
            if (j-1 >= 0 && rotSheet[i][j-1] == 1) {
                rotSheet[i][j-1] = 2;
                rotten.push(make_pair(i, j-1));
            }
            
            // check bottom
            if (j+1 < C && rotSheet[i][j+1] == 1) {
                rotSheet[i][j+1] = 2;
                rotten.push(make_pair(i, j+1));
            }

        }
        
        // cout << "~~~~~~~~~\n";
        // remove the delimiter
        rotten.pop();
    }
    
    // check if there is any fresh orange left in the grid
    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++)
            if (rotSheet[i][j] == 1)
                return -1;
    
    return ans;
}

// Failed attempt 2: Same complexity as the previous one
/*
int getOrange(vector<vector<int> > &sheet, int i, int j) {
    if (i < 0 || j < 0 || i >= sheet.size() || j >= sheet[0].size()) {
        return INT_MAX;
    }
    if (sheet[i][j] == INT_MAX) { // blank space
        return INT_MAX;
    } else if (sheet[i][j] == -1) { // fresh_orange
        return INT_MAX;
    } else { // rotten_orange
        return sheet[i][j];
    }
}

int rotOranges(vector<vector<int> > &matrix, int R, int C) {
    vector<vector<int> > rotSheet(R, vector<int>(C, -1));
    int count = R*C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 0) 
                rotSheet[i][j] = INT_MAX;
            else if (matrix[i][j] == 2)
                rotSheet[i][j] = 0;
            else
                count--; // decrease by one for any '1' (fresh orange encountered)
        }
    }
    
    int temp;
    bool change;
    
    while (count < R*C) {
        // cout << "********* Round " << ans+1 << " *********\n";
        change = false;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rotSheet[i][j] == -1) { // fresh orange encountered
                    // cout << "encountered fresh orange at: (" << i << ", " << j << "). " << endl;
                    temp = min(getOrange(rotSheet, i-1, j),  // left
                           min(getOrange(rotSheet, i+1, j),  // right
                           min(getOrange(rotSheet, i, j-1),  // up
                               getOrange(rotSheet, i, j+1))) ); // down
                    if (temp == INT_MAX) { // no rotten orange in the surrounding
                        continue;
                    } else { // rotton orange encountered nearby
                        // cout << "\tfound a rotton orange at " << temp+1 << " steps." << endl;
                        rotSheet[i][j] = temp+1;
                        change = true;
                        count++;
                    }
                }
            }
        }
        if (!change)
            return -1;
    }
    
    int ans = 0;
    
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            ans = max(ans, ((rotSheet[i][j] == INT_MAX) ? 0 : rotSheet[i][j]) );
    
    return ans;
}
*/

// Implementing a trivial solution of order O(max(r,c) * r * c)
/*
int getOrange(vector<vector<int> > &sheet, int i, int j) {
    if (i < 0 || j < 0 || i >= sheet.size() || j >= sheet[0].size()) {
        return INT_MAX;
    }
    if (sheet[i][j] == INT_MAX) { // blank space
        return INT_MAX;
    } else if (sheet[i][j] == -1) { // fresh_orange
        return INT_MAX;
    } else { // rotten_orange
        return sheet[i][j];
    }
}

int rotOranges(vector<vector<int> > &matrix, int R, int C) {
    vector<vector<int> > rotSheet(R, vector<int>(C, -1));
    int count = R*C;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] == 0) 
                rotSheet[i][j] = INT_MAX;
            else if (matrix[i][j] == 2)
                rotSheet[i][j] = 0;
            else
                count--; // decrease by one for any '1' (fresh orange encountered)
        }
    }
    
    int ans = 0, temp;
    bool change;
    
    vector<vector<int> > rotSheet_new = rotSheet;
    
    while (count < R*C) {
        // cout << "********* Round " << ans+1 << " *********\n";
        change = false;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rotSheet[i][j] == -1) { // fresh orange encountered
                    // cout << "encountered fresh orange at: (" << i << ", " << j << "). " << endl;
                    temp = min(getOrange(rotSheet, i-1, j),  // left
                           min(getOrange(rotSheet, i+1, j),  // right
                           min(getOrange(rotSheet, i, j-1),  // up
                               getOrange(rotSheet, i, j+1))) ); // down
                    if (temp == INT_MAX) { // no rotten orange in the surrounding
                        continue;
                    } else { // rotton orange encountered nearby
                        // cout << "\tfound a rotton orange at " << temp+1 << " steps." << endl;
                        rotSheet_new[i][j] = temp+1;
                        change = true;
                        count++;
                    }
                }
            }
        }
        if (change)
            ans++; // one rount of rottenness spreaded
        else
            return -1;
        rotSheet = rotSheet_new;
    }
    
    return ans;
}
*/

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}  // } Driver Code Ends
