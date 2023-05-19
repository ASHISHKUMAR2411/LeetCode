//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& f, int n, int k) {
        // code here
        int maxi = 0;
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < f.size(); i++){
            adj[f[i][0]-1].push_back({f[i][1]-1, f[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans(n, INT_MAX);
        pq.push({0,k-1});
        ans[k-1] = 0;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            for(auto it : adj[t.second]){
                if(ans[it.first] > (it.second + t.first)){
                    ans[it.first] = it.second + t.first;
                    pq.push({ans[it.first], it.first});
                }
            }
        }
        maxi = *max_element(ans.begin(), ans.end());
        return maxi == INT_MAX ? -1 : maxi;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends