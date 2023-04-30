//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        vector<int> pos;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(count == 0) pos.push_back(i);
            if(s[i] == '('){
                count++;
            }
            else{
                count--;
            }
            if(count == 0) pos.push_back(i);
        }
        for(int i =0; i < pos.size(); i++){
            s.erase((pos[i]-i), 1);
        }
        return s;
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends