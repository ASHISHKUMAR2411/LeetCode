//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    bool check5pow(int n){
        for(int i = 0; i <= 15; i++){
            if(pow(5,i) == n) return true;
        }
        return false;
    }
    int solve(int i, int n, int p, string &s){
        if(i == 0){
            if(s[i] == '1' and check5pow(n+pow(2,p))){
                return 1;
            }
            else return 1e9;
        }
        int temp = solve(i-1, n + (pow(2, p))*(s[i]-'0'), p+1, s);
        if(s[i] == '1'){
            if(check5pow(n+pow(2,p))){
                temp = min(1+solve(i-1, 0, 0, s), temp);
            }
        }
        return temp;
    }
    int cuts(string s){
        //code
        int n = s.size();
        if(n == 1 and s[0] == '1') return 1;
        int ans = solve(n-1, 0, 0, s);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends