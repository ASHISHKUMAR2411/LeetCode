//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        int v = 0, ele = 0;
        for(int i = 0; i < n; i++){
            v = abs(arr[i]);
            ele = arr[v-1];
            if(ele > 0){
                arr[v - 1] = -ele;
            }
            else ans[0] = v;
        }
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends