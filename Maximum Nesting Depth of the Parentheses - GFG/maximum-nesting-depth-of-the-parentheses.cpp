//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int maxi = INT_MIN;
        stack<char> st;
        for(int i =0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            if(s[i] == ')'){
                st.pop();
            }
            int x = st.size();
            maxi = max(maxi, x);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends