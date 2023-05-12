//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void solve(int node, int dist, vector<int> &ans, vector<pair<int,int>> adj[]  , vector<bool> &vis){
         vis[node] = true;
         ans[node] = min(ans[node], dist);
         for(auto i : adj[node]){
             if(!vis[i.first]){
                 solve(i.first, dist + i.second, ans, adj, vis);
             }
         }
         vis[node] = false;
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i = 0; i < M; i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<bool> vis(N, false);
        vector<int> ans(N, INT_MAX);
        solve(0, 0, ans, adj, vis);
        for(int i =0; i< N; i++){
            if(ans[i] == INT_MAX){
                ans[i] = -1;
            }
        }
        return ans;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends