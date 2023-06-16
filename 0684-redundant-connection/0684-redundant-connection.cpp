class Solution {
public:
    bool dfs(vector<int> adj[], set<int> &vis, int u, int v){
        if(vis.find(u) == vis.end()){
            vis.insert(u);
            if(u == v) return true;
            for(auto it : adj[u]){
                if(dfs(adj,vis,it,v)) return true;
            }
        }
        return false;
            
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // create an empty adjacency list, we can add the elements
        int n = edges.size();
        vector<int> adj[n+1];
        // do dfs for each node and check whether we can reach the node, if yes then we got our ans
        for(int i = 0; i < n; i++){
            set<int> vis;
            int u = edges[i][0];
            int v = edges[i][1];
            if((adj[u].size() > 0) and (adj[v].size() > 0) and dfs(adj, vis, u, v)){
                return edges[i];
            }
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }  
        // we add the nodes to our adjacency list if not found, 
        vector<int> ans;
        return ans;
    }
};