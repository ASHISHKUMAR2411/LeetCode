//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        int prev = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.'){
                reverse(s.begin() + prev, s.begin() + i);
                prev = i+1;
            }
        }
        reverse(s.begin() + prev, s.end());
        // cout << s << endl;
        reverse(s.begin(), s.end());
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends