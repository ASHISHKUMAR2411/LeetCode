//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[100005];
    // Recursive Solution  & DP Memoization
    int solve(int i, vector<int> &h){
        if(i <= 0) return 0;
        if(dp[i] != -1) return dp[i];
        int sum1 = solve(i - 1, h) + abs(h[i] - h[i-1]);
        int sum2 = 1e9;
        if(i > 1){
            sum2 = solve(i-2, h) + abs(h[i] - h[i-2]);
        }
        return dp[i] = min(sum2, sum1);
    }
    int minimumEnergy(vector<int>& h, int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            int sum1 = dp[i-1] + abs(h[i] - h[i-1]);
            int sum2 = 1e9;
            if(i > 1){
                sum2 = dp[i-2] + abs(h[i] - h[i-2]);
            }
            dp[i] = min(sum1, sum2);
        }
        return dp[n-1];
        // return solve(n-1, h);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends