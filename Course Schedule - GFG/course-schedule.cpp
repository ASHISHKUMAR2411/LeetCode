//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    bool cycle(int node, vector<bool> &vis, vector<bool> &path, vector<int> adj[]){
        vis[node] = true;
        path[node] = true;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(cycle(it, vis,path, adj)) return true;
            }
            else if(path[it]) return true;
        }
        
        path[node] = false;
        return false;
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> p) 
    {
        //code here
        // it will not work for cyclic graphs
        // we need to check cycle
        vector<int> adj[n];
        vector<int> in(n,0);
        for(int i = 0; i < m; i++){
            adj[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }
        vector<int> ans;
        vector<bool> vis(n,false), path(n,false);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(cycle(i,vis,path,adj)){
                    return ans;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                in[it]--;
                if(in[it] == 0){
                    q.push(it);
                }
            }
            ans.push_back(node);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends