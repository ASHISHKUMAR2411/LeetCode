//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        sort(arr.begin(), arr.begin() + n/2);
        sort(arr.begin() + n/ 2, arr.end());
        // for(int i = 0; i < n; i++){
        //     cout << arr[i] << " ";
        // }
        int count = 0; 
        int l = 0, r = n/2;
        while(l < n/2 and r < n){
            if(arr[l] >= (5*arr[r])){
                count += n/2 - l;
                r++;
            }
            else{
                l++;
            }
        }
        return count;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends