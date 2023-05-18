//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& f, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(int i  = 0; i < f.size(); i++){
            adj[f[i][0]].push_back({f[i][1], f[i][2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        k++;
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX) );
        pq.push({0, 0, src});
        // vector<int> ans(n, INT_MAX);
        // ans[src] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            // if(it[2] == dst) return it[0];
            if(it[1] < k){
                for(auto i : adj[it[2]]){
                    if(dp[i.first][it[1]] > it[0] + i.second){
                        dp[i.first][it[1]] = it[0] + i.second;
                        if(i.first != dst)
                            pq.push({it[0] + i.second, it[1] + 1, i.first});
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= k; i++){
            ans = min(ans,dp[dst][i]);
        }
        // return -1;
        return ans == INT_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends