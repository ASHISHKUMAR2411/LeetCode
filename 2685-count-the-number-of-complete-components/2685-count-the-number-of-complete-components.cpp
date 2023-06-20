class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &in, vector<int> &out, vector<int> &belong){
        vis[node] = true;
        belong.push_back(node);
        for(auto it : adj[node]){
            out[node]++;
            in[it]++;
            if(!vis[it]){
               dfs(it, adj, vis, in, out, belong); 
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n], in(n, 0), out(n, 0);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n, false);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> nodesBelongToComponents;
                dfs(i, adj, vis, in, out, nodesBelongToComponents);
                int sz = nodesBelongToComponents.size();
                bool flag = true;
                for(auto it : nodesBelongToComponents){
                    if(!(in[it] == out[it] and in[it] == sz - 1)){
                        flag = false;
                    }
                }
                if(flag) count++;
            }
        }
        return count;
    }
};