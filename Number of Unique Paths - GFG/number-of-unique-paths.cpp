//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    int dp[17][17];
    int solve(int i, int j, int n, int m){
        if(i == n-1 and j == m-1) return 1;
        if(i >= n or j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i, j+1, n, m) + solve(i+1, j, n, m);
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, a, b);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends