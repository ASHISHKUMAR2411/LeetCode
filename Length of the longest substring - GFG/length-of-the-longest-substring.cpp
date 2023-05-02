//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector<int>v(256,-1);
        int j=0;
        int ans=INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            j=max(j,v[s[i]]+1);
            
            ans=max(ans,i-j+1);
            v[s[i]]=i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends