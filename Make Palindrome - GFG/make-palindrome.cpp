//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool isPalindrom(string s){
        int l = 0, r = s.size() - 1;
        while(l <= r){
            if(s[l] == s[r]){
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        if(arr.size() == 1){
            return isPalindrom(arr[0]);
        }
        map<string, int> mp;
        for(int i = 0; i < arr.size(); i++){
            string x = arr[i];
            reverse(arr[i].begin(), arr[i].end());
            if(mp.find(arr[i]) != mp.end()){
                mp[arr[i]]++;
            }
            else{
                mp[x]++;
            }
        }
        int count = 0;
        for(auto i : mp){
            // cout << i.first << " " << i.second << endl;
            if(i.second%2){ 
                bool f = isPalindrom(i.first);
                if(f)
                    count++;
                else {
                    return false;
                }
                
            }
        }
        if(count == 1 || count == 0)
            return true;
        else return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends