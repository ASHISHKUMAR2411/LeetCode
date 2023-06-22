//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[100001][3];
    // this is my recusive solution 
    int solve(int index, vector<vector<int>>& points, int choice){
        if(index < 0) return 0;
        if(dp[index][choice] != -1) return dp[index][choice];
        if(choice == 0){
            return dp[index][choice] = points[index][choice] + max(solve(index - 1, points, 1), solve(index - 1, points, 2));
        }
        else if(choice == 1){
            return dp[index][choice] = points[index][choice] + max(solve(index - 1, points, 0), solve(index - 1, points, 2));
        }
        else if(choice == 2){
            return dp[index][choice] = points[index][choice] + max(solve(index - 1, points, 0), solve(index - 1, points, 1));
        }
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        memset(dp, -1, sizeof(dp));
        return max(solve(n-1, points, 0), max(solve(n-1, points, 1), solve(n-1, points, 2)));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends