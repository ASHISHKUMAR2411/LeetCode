//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row, int col, vector<int> &curr_ans, int n){
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for(int k = 0; k < curr_ans.size(); k++){
            arr[curr_ans[k] - 1][k] = 1;
        }
        int dr = row, dc = col;
        while(row >= 0 and col >= 0){
            if(arr[row][col] == 1) return false;
            row--;
            col--;
        }
        row = dr, col = dc;
        while(col >= 0){
            if(arr[row][col] == 1) return false;
            col--;
        }
        row = dr, col = dc;
        while(row < n and col >= 0){
            if(arr[row][col]) return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(vector<vector<int>> &ans, vector<int> &curr_ans, 
    int col, int n){
        if(col == n){
            ans.push_back(curr_ans);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isSafe(row, col, curr_ans, n)){
                curr_ans.push_back(row + 1);
                solve(ans, curr_ans, col + 1, n);
                curr_ans.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans; 
        vector<int> curr_ans;
        solve(ans, curr_ans, 0, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends