//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> ans(n, -1);
        stack<int> s;
        s.push(arr[n-1]);
        ans[n-1]  = -1;
        for(int i = n-2; i >= 0; i--){
            // if(arr[i+1] < arr[i]){
            //     ans[i] = arr[i+1];
            //     s.push(arr[i]);
            // }
            // else{
                
            // }
            int x = arr[i];
            while(!s.empty()){
                if(s.top() >= x){
                    s.pop();
                }
                else{
                    break;
                }
            }
            if(s.empty()){
                ans[i] = -1;
                s.push(x);
            }
            else{
                ans[i] = s.top();
                s.push(arr[i]);
            }
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
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends