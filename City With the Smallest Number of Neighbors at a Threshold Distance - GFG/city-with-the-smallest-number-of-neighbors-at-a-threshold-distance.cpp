//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& e, int dT) {
        vector<vector<int>> dp(n, vector<int>(n,180000000));
        for(int i = 0; i < n; i++){
            dp[i][i] = 0;
        }
        for(int i = 0; i < e.size(); i++){
            dp[e[i][0]][e[i][1]] = e[i][2];
            dp[e[i][1]][e[i][0]] = e[i][2];
        }
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i!=via and j != via and i!=j)
                    dp[i][j] = min(dp[i][j], (dp[i][via] + dp[via][j]));
                }
            }
        }
        int city = -1, count = INT_MAX;
        for(int i = 0; i < n; i++){
            int c = 0;
            for(int j = 0; j < n; j++){
                if(dp[i][j] <= dT){
                    c++;
                }
            }
            if(c < count){
                count = c;
                city = i;
            }
            else if(c == count){
                city = i;
            }
        }
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends