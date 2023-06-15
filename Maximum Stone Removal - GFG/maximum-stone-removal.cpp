//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int start) {
        visited[start] = true;

        const vector<int>& neighbors = graph[start];
        for (int x : neighbors) {
            if (visited[x]) {
                continue;
            }

            dfs(graph, visited, x);
        }
    }
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        if (n <= 1) {
            return 0;
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            graph[i] = vector<int>();
        }

        for (int i = 0; i < n; i++) {
            vector<int>& u = stones[i];
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                vector<int>& v = stones[j];
                if (u[0] == v[0] || u[1] == v[1]) {
                    graph[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            dfs(graph, visited, i);
            ans++;
        }

        return n - ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends