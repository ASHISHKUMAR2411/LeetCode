//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int dp[10005];
    int mod = 1e9 + 7;
    int count = 0;
    //Function to count number of ways to reach the nth stair.
    int solve(int n){
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (solve(n-2)%mod + solve(n-1)%mod)%mod;
    }
    int countWays(int n)
    {
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        return solve(n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends