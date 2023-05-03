class Solution {
public:
    void solve(int node, vector<bool> &vis, vector<int> adj[]){
        vis[node] = true;
        for(auto i : adj[node]){
            if(!vis[i]){
                solve(i, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& C) {
        vector<int> adj[C.size() + 1];
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < C[i].size(); j++){
                if(C[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count = 0;
        vector<bool> vis(C.size()+1, false);
        for(int i =1; i <= C.size(); i++){
            if(!vis[i]){
                solve(i, vis, adj);
                count++;
            }
        }
        return count;
    }
};