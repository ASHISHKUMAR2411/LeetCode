class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);
        for(int i =0; i < n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};