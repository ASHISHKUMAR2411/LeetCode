//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int n = s.length();
        int l = 0, r = n-1;
        while(l <= r){
            if(s[l] != '?' and s[r] != '?'){
                if(s[l] != s[r]) return -1;
            }
            if(s[l] != '?'){
                if(s[r] == '?'){
                    s[r] = s[l];
                }
            }
            else if(s[r] != '?'){
                if(s[l] == '?'){
                    s[l] = s[r];
                }
            }
            l++;
            r--;
        }
        int sum = 0;
        char prev = '?';
        for(int i = 0; i < n; i++){
            if(s[i] != '?'){
                if(prev == '?'){
                    prev = s[i];
                }
                else{
                    sum += abs(s[i] - prev);
                    prev = s[i];
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends