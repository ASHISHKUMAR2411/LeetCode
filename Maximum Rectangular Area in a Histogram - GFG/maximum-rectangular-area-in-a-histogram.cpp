//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int> left_s(n), right_s(n);
        stack<int> s1, s2;
        long long ans = 0;
        // for finding the smaller left
        s1.push(0);
        left_s[0] = -1;
        for(int i = 1; i < n; i++){
            while(!s1.empty()){
                if(arr[s1.top()] > arr[i]){
                    s1.pop();
                }
                else{
                    break;
                }
            }
            if(s1.empty()){
                left_s[i] = -1;
                s1.push(i);
            }
            else{
                left_s[i] = s1.top();
                s1.push(i);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << left_s[i] << " ";
        // }
        // cout << endl;
        
        // for right smaller 
        s2.push(n-1);
        right_s[n-1] = -1;
        for(int i = n-2; i >= 0; i--){
            while(!s2.empty()){
                if(arr[s2.top()] >= arr[i]){
                    s2.pop();
                }
                else{
                    break;
                }
            }
            if(s2.empty()){
                right_s[i] = -1;
                s2.push(i);
            }
            else{
                right_s[i] = n - 1 - s2.top();
                s2.push(i);
            }
        }
        // for(int i = 0; i < n; i++){
        //     cout << right_s[i] << " ";
        // }
        // cout << endl;
        
        for(int i = 0; i < n; i++){
            long long count = abs(left_s[i] - i) + abs(right_s[i] - (n - 1 - i))  - 1;
            // cout << count << " ";
            ans = max(ans, count*arr[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends