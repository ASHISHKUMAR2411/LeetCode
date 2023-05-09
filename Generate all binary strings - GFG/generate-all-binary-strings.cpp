//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateBinaryStrings(int num){
        //Write your code
        vector<string> ans;
        for(int i = 0; i < (1<<num); i++){
            string s;
            for(int j =0; j < num; j++){
                if(i & (1<<j)){
                    if((j-1) >= 0 and s[j-1] == '1'){
                        break;
                    }
                    else{
                        s.push_back('1');
                    }
                }
                else{
                    s.push_back('0');
                }
            }
            if(s.size() == num){
                ans.push_back(s);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i =0; i< ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends