//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int neg = str[0] == '-' ? 1 : 0;
        if(neg){
            str = str.substr(1,str.length() - 1);
        }
        int ans = 0;
        for(int i = 0; i < str.size(); i++){
            int num = str[i] - '0';
            if(num > 9 || num < 0) return -1;
            ans = ans * 10 + num;
        }
        return neg == 1 ? -ans : ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends