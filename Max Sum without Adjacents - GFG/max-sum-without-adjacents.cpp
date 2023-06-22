//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    // recursive solution
    int dp[1000005];
    int solve(int index, int *arr){
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int take = arr[index] + solve(index - 2, arr);
        int ntake = solve(index - 1, arr);
        return dp[index] = max(take, ntake);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    memset(dp, -1, sizeof(dp));
	    return solve(n-1, arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends