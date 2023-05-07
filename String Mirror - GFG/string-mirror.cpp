//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        int index = 0;
        for(int i = 1; i < str.length(); i++){
            if((i > 1 and str[i] <= str[index]) || str[i] < str[index]){
                index++;
            }
            else break;
        }
        string s = str.substr(0,index+1), ans = s;
        reverse(s.begin(), s.end());
        ans += s;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends