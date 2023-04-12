//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
    vector<pair<int, int>> vp;
    int sum = 0;
    int start = 0, end = 0;
    for(int i = 1; i < n; i++){
        if(sum == 0){
            start = i - 1;
        }
        sum = price[i] - price[i-1];
        if(sum >= 0){
            end = i;
        }
        else{
            if(end > start)
                vp.push_back({start, end});
            sum = 0;
        }
    }
    if(end > start){
        if(vp.size() and vp.back().first == start and vp.back().second == end){
            ;
        }
        else{
            vp.push_back({start, end});
        }
    }
    if(vp.size())
    for(auto i : vp){
        cout << "(" << i.first << " " << i.second << ") ";
    }
    else{
        cout << "No Profit";
    }
    cout << endl;
}