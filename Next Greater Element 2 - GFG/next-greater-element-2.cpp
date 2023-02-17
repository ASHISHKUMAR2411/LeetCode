//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        vector<int> ans(n);
        stack<int> s;
        s.push(arr[n-1]);
        ans[n-1] = INT_MIN;
        for(int i = n-2; i>= 0; i--){
            while(!s.empty()){
                if(s.top() <= arr[i]){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.empty()){
                s.push(arr[i]);
                ans[i] = INT_MIN;
            }
            else{
                ans[i] = s.top();
                s.push(arr[i]);
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            if(ans[i] == INT_MIN){
                while(!s.empty()){
                    if(s.top() > arr[i]){
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
                if(s.empty()){
                    ans[i] = -1;
                    s.push(arr[i]);
                }
                else{
                    ans[i] = s.top();
                    s.push(arr[i]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends