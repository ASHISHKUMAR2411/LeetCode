//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int m = 1e9+7;
	int solve(vector<vector<int>>&dp, int sum, int arr[], int n){
	   // if(sum == 0) return 1;
	    if(n == 0){
	        if(arr[n] == sum && sum == 0) return 2;
	        if(arr[n] == sum || sum == 0) return 1;
	        return 0;
	    }
	    if(dp[n][sum] != -1) return dp[n][sum];
	   // if(sum == curr_sum) return 1;
	   int l = 0, r = 0;
	    if(arr[n] <= sum)
    	    l = solve(dp, sum - arr[n] , arr, n-1);
	    r = solve(dp, sum, arr, n-1);
	    return dp[n][sum] = (l%m + r%m)%m;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solve(dp, sum, arr, n-1);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends