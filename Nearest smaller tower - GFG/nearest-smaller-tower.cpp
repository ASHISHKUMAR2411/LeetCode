//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        stack<int> st;
        vector<int> left(arr.size(), 0), right(arr.size(), 0);
        for(int i = 0; i < arr.size(); i++){
            while(!(st.empty()) and arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!(st.empty())){
                left[i] = st.top();
            }
            else{
                left[i] = -1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!(st.empty()) and arr[st.top()] >= arr[i]) st.pop();
            if(!(st.empty())){
                right[i] = st.top();
            }
            else{
                right[i] = -1;
            }
            st.push(i);
        }
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            if(left[i] == -1 and right[i] == -1) {
                ans.push_back(-1);
            }
            else if(left[i] == -1){
                ans.push_back(right[i]);
            }
            else if(right[i] == -1){
                ans.push_back(left[i]);
            }
            else if(abs(i - left[i]) == abs(i - right[i])){
                if(arr[left[i]] == arr[right[i]]){
                    ans.push_back(left[i]);
                }
                else if(arr[right[i]] < arr[left[i]]){
                    ans.push_back(right[i]);
                }
                else{
                    ans.push_back(left[i]);
                }
            }
            else if(abs(i - left[i]) < abs(i - right[i])){
                ans.push_back(left[i]);
            }
            else{
                ans.push_back(right[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends