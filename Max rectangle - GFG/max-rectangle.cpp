//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int getMaxArea(int arr[], int n)
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
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> arr(m);
        int ans = 0;
        for(int i = 0; i < n; i++){
            // for finding the height of the rectangle 
            for(int j = 0; j < m; j++){
                if(M[i][j] == 0){
                    M[i][j] = 0;
                }
                else if((i - 1) >= 0)
                    M[i][j] += M[i-1][j];
                
            }
            ans = max(ans, getMaxArea(M[i], m));
            
            // // finding MAH for the row 
            // stack<int> s1, s2;
            // vector<int> left(m), right(m);
            
            // // for left smaller 
            // s1.push(0);
            // left[0] = -1;
            // for(int j = 1; j < m; i++){
            //     while(!s1.empty()){
            //         cout << s1.top() << endl;
            //         if(M[i][j] >= M[i][j]){
            //             s1.pop();
            //         }
            //         else{
            //             break;
            //         }
            //     }
            //     if(s1.empty()){
            //         left[j] = -1;
            //         s1.push(j);
            //     }
            //     else{
            //         left[j] = s1.top();
            //         s1.push(j);
            //     }
            // }
            
            // // for(int j = 0; j < m; i++){
            // //     cout << left[j] << " ";
            // // }
            // // cout << endl;
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << M[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends