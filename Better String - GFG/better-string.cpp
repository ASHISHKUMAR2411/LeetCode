//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string betterString(string str1, string str2) {
        // code here
        int n1 = str1.size();
        int n2 = str2.size();
        unordered_map<char, int> mp1, mp2;
        int dp1[n1+1], dp2[n2+1];
        dp1[0] = 1, dp2[0] = 1;
        for(int i = 1; i <= n1; i++){
            char c = str1[i-1];
            dp1[i] = 2*dp1[i-1];
            if(mp1.find(c) != mp1.end()){
                dp1[i] -= dp1[mp1[c] - 1];
            }
            mp1[c] = i;
        }
        for(int i = 1; i <= n2; i++){
            char c = str2[i-1];
            dp2[i] = 2*dp2[i-1];
            if(mp2.find(c) != mp2.end()){
                dp2[i] -= dp2[mp2[c] - 1];
            }
            mp2[c] = i;
        }
        if(dp1[n1] >= dp2[n2]) return str1;
        else return str2;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends