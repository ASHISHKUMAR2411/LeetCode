//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int mod = 1e9 + 7;
    long long int fibo(int n, long long int dp[]){
        dp[0] = 0, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        return dp[n];
    }
    long long int topDown(int n) {
        // code here
        long long int dp[n+1];
        // cout << (fibo(n, dp)%mod) << endl;
        return fibo(n, dp);
    }
    long long int bottomUp(int n) {
        // code here
        long long int prev1 = 1;
        long long int prev2 = 0;
        for(int i = 2; i <= n; i++){
            long long int curr = (prev1%mod + prev2%mod)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends