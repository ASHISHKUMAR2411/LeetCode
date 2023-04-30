//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        int index = - 1;
        for(int i = s.size() - 1; i >= 0; i--){
            if((s[i] - '0')%2 == 1){
                index = i;
                break;
            }
        }
        if(index == -1) return "";
        else return s.substr(0, index + 1);
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

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends