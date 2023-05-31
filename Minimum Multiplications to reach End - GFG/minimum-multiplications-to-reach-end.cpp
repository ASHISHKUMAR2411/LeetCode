//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        vector<int>ans(100000,1e9);
        q.push({start,0});
        while(!q.empty()){
            int node=q.front().first;
            int count=q.front().second;
            q.pop();
            for(auto it:arr){
                int temp=node*it;
                temp=temp%100000;
                if(ans[temp]==1e9){
                    ans[temp]=count+1;
                    if(temp==end) return count+1;
                    q.push({temp,count+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends