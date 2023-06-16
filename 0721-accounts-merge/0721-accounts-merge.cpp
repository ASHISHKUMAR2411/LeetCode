// Using DFS
class Solution {
public:
    void dfs(string node, map<string, set<string>> &adj, unordered_set<string> &vis, string &name, map<string, set<string>> &details){
        vis.insert(node);
        details[name].insert(node);
        for(auto it: adj[node]){
            if(vis.find(it) == vis.end()){
                dfs(it, adj, vis, name, details);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        // creating adjacency list 
        map<string, set<string>> adj;
        // adjancecy list 
        for(int i = 0; i < acc.size(); i++){
            for(int j = 2; j < acc[i].size(); j++){
                adj[acc[i][j]].insert(acc[i][1]);
                adj[acc[i][1]].insert(acc[i][j]);
            }
        }
        // for(auto it : adj){
        //     cout << it.first << " ";
        //     for(auto i : it.second){
        //         cout << i << " ";
        //     }
        //     cout << endl;
        // }
        int n = acc.size();
        unordered_set<string> vis;
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(vis.find(acc[i][1]) == vis.end()){
                map<string, set<string>> details;
                dfs(acc[i][1], adj, vis, acc[i][0], details);
                for(auto it: details){
                    vector<string> a;
                    a.push_back(it.first);
                    for(auto i : it.second){
                        a.push_back(i);
                    }
                    ans.push_back(a);
                }
            }
        }
        return ans;  
    }
};