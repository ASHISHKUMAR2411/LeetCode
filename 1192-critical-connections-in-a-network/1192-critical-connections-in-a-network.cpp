class Solution {
public:
    int timer = 0; 
    void dfs(int node, int parent, vector<bool> &vis, vector<int> adj[], vector<int> &low, vector<int> &actual, vector<vector<int>> &bridge){
        vis[node] = true;
        low[node] = timer;
        actual[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, adj, low, actual, bridge);
                low[node] = min(low[node], low[it]);
                if(low[it] > actual[node]){
                    bridge.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[node], low[it]); 
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        // create an adjancency list 
        vector<int> adj[n];
        for(auto it : con){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n, false);
        // then creating the variable for timer and all
        vector<int> actual(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> ans;
        // then we do dfs traversal and store the bridges 
        dfs(0, -1, vis, adj, low, actual, ans);
        return ans;
        
    }
};