//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string a, string b,int n, int m, vector<vector<int>> &dp){
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(a[n-1] == b[m-1]){
            return dp[n][m] = 1 + solve(a,b,n-1,m-1, dp);
        }
        else{
            return dp[n][m] = solve(a,b,n-1,m, dp);
        }
    }
    int getLongestSubsequence(string A, string B) {
        // code here
        int n = A.size(), m = B.size();
        int maxi = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
                maxi = max(maxi, dp[i][j]);
            }
        }
        
        // for(int i = 0; i <= m; i++){
        //     int x = solve(A,B,n,i,dp);
        //     maxi = max(maxi, x);
        // }
        return maxi;
        // int size = min(n,m);
        // int maxi = 0;
        // // expecting the size to min(A,B) 
        // for(int i = size; i > 0; i--){
        //     int r = i - 1;
        //     // using sliding window over B to consider the current window as our substring
        //     while(r < m){
        //         // using two pointer on the substring and find whether it is possible to reach the substring end while skipping or taking a subsequence from A. 
        //         int j = r - i + 1, k = 0;
        //         while(j <= r and k < n){
        //             if(A[k] == B[j]){
        //                 k++;
        //                 j++;
        //             }
        //             else{
        //                 k++;
        //             }
        //         }
        //         if(j == r+1){
        //             return i;
        //         }
        //         r++;
        //     }
        // }
        // return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A,B;

        cin >>A>>B;

        Solution ob;
        cout << ob.getLongestSubsequence(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends