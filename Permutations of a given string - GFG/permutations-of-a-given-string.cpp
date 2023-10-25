//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int i, string s, set<string> &ans){
	        if(i == s.size()){
	            ans.insert(s);
	            return;
	        }
	        for(int j = i; j < s.size(); j++){
	            swap(s[i], s[j]);
	            solve(i + 1, s, ans);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> ans;
		    sort(S.begin(), S.end());
		    solve(0, S, ans);
		    vector<string> a;
		    for(auto it : ans){
		        a.push_back(it);
		    }
		    return a;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends