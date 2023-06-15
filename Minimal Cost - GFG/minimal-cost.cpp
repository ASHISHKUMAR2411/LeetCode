//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> &h, int n, int k, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != INT_MAX) return dp[n];
        int mn = INT_MAX;
        for(int i = 1; i <= k; i++){
            int l;
            if(n-i >= 0) l = solve(h, n-i, k, dp) + abs(h[n] - h[n-i]);
            mn = min(mn, l);
        }
        return dp[n] = mn;
     }
    int minimizeCost(vector<int>& h, int n, int k) {
        // Code here
        // this is a dp solution 
        vector<int> dp(n, INT_MAX);
        return solve(h, n-1, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends