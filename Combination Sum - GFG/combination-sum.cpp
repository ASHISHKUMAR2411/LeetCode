//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    void solve(int i,int sum, vector<int> a, vector<int> &A, vector<vector<int>> &s){
        if(sum < 0) return;
        if(i == A.size()){
            if(sum == 0){
                s.push_back(a);
            }
            return;
        }
        if(sum >= A[i]){
        a.push_back(A[i]);
        solve(i, sum - A[i], a, A, s);
        a.pop_back();
        }
        solve(i+1, sum , a, A, s);
        // }
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<vector<int>> s;
        // vector<vector<int>> ans;
        vector<int> a;
        solve(0, B, a, A, s);
        sort(s.begin(), s.end());
        // for(auto i : s){
        //     ans.push_back(i);
        // }
        return s;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends