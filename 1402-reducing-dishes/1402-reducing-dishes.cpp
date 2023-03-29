class Solution {
public:
    int dp[501][2001];
    int solve(int i,int t,vector<int>& arr)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        int not_taken = solve(i+1,t,arr);
        int taken = arr[i]*t + solve(i+1,t+1,arr);
        return dp[i][t] = max(taken, not_taken);
    }
    int maxSatisfaction(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, arr);
    }
};