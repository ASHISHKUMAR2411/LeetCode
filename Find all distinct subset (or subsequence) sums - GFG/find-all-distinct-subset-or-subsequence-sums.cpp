//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    unordered_set<int> s;
    int solve(int i, int c_sum, int n, vector<int> &nums, vector<vector<int>> &dp){
        // if(c_sum > sum) return;
        if(i >= n){
            s.insert(c_sum);
            return 0;
        }
        if(dp[i][c_sum] != -1) return dp[i][c_sum];
        int t = solve(i+1, c_sum+nums[i], n,nums, dp);
        int nt = solve(i+1, c_sum, n, nums, dp);
        return dp[i][c_sum] = max(t,nt);
    }
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    int n = nums.size();
	    int sum = 0;
	    for(int i = 0; i < n; i++){
	        sum += nums[i];
	    }
	    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
	    s.clear();
	    solve(0, 0, n, nums, dp);
	    vector<int> ans;
	    for(auto i : s){
	        ans.push_back(i);
	    }
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends