//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
        // code here
        int i = 0;
        map<int,int> mp;
        for(int i = 0; i < 2*n; i+=2){
            mp[arr[i]] = arr[i+1];
        }
        queue<pair<int,int>> pq;
        pq.push({1, 0});
        while(!pq.empty()){
            int sz = pq.size();
            while(sz){
                int top = pq.front().first;
                int moves = pq.front().second;
                if(top == 30) return moves;
                pq.pop();
                for(int i = 1; i <= 6; i++){
                    if(mp.find(top + i) != mp.end()){
                        pq.push({mp[top+i], moves + 1});
                        // if(mp[top + i] == 30) flag = false, break;
                    }
                    else{
                        pq.push({top + i, moves + 1});
                        // if(top + i) flag = false, break;
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends