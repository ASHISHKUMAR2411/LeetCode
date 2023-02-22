//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string> s;
	for(int i = 1; i <= N; i++){
	    string si;
	    int j = i;
	    while(j){
	        int k = j%2;
	        si+=to_string(k);
	        j/=2;
	    }
	    reverse(si.begin(), si.end());
	    s.push_back(si);
	}
	return s;
}


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends