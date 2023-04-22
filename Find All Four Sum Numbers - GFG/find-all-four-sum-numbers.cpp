//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        set<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i =0; i < n - 3; i++){
            for(int j = i + 1; j < n - 2; j++){
                int l = j + 1, h = n - 1;
                while(l < h){
                    if((arr[i] + arr[j] + arr[l] + arr[h]) == k){
                        vector<int> a = {arr[i], arr[j], arr[l], arr[h]};
                        ans.insert(a);
                        if((l + 1) < h and arr[l] == arr[l+1]){
                            l++;
                        }
                        else if((h-1) > l and arr[h] == arr[h-1]){
                            h--;
                        }
                        else{
                            l++;
                            h--;
                        }
                    }
                    else if((arr[i] + arr[j] + arr[l] + arr[h]) > k){
                        h--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        vector<vector<int>> answer;
        for(auto i : ans){
            answer.push_back(i);
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends