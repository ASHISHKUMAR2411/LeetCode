//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        unordered_map<int,int> changeIhave;
        // sort(bills.begin(), bills.end());
        for(int i = 0; i < N; i++){
            int order = bills[i];
            if(order == 5){
                changeIhave[order]++;
            }
            else if(order == 10){
                if(changeIhave[5] >= 1){
                    changeIhave[5]--;
                    changeIhave[order]++;
                }
                else{
                    return false;
                }
            }
            else if(order == 20){
                if(changeIhave[5] >= 1 and changeIhave[10] >= 1){
                    changeIhave[5]--;
                    changeIhave[10]--;
                    changeIhave[order]++;
                }
                else if(changeIhave[5] >= 3){
                    changeIhave[5] -= 3;
                    changeIhave[order]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends