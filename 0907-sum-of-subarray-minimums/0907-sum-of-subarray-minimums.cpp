class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;

        stack<int> stack;
        int sumOfMinimums = 0;

        // building monotonically increasing stack
        for (int i = 0; i <= arr.size(); i++) {

            // when i reaches the array length, it is an indication that
            // all the elements have been processed, and the remaining
            // elements in the stack should now be popped out.

            while (!stack.empty() && (i == arr.size() || arr[stack.top()] >= arr[i])) {

                // Notice the sign ">=", This ensures that no contribution
                // is counted twice. rightBoundary takes equal or smaller 
                // elements into account while leftBoundary takes only the
                // strictly smaller elements into account

                int mid = stack.top();
                stack.pop();
                int leftBoundary = stack.empty() ? -1 : stack.top();
                int rightBoundary = i;

                // count of subarrays where mid is the minimum element
                int count = (mid - leftBoundary) *1ll* (rightBoundary - mid) % MOD;

                sumOfMinimums = (sumOfMinimums%MOD + (count *1ll* arr[mid]) % MOD)%MOD;
                // sumOfMinimums %= MOD;
            }
            stack.push(i);
        }

        return (sumOfMinimums);
        // stack<int> s;
        // map<string, int> prev, next;
        // int sum = 0, mod = 1e9+7;
        // string si;
        // for(int i = arr.size() - 1; i >= 0; i--){
        //     if(s.empty()){
        //         si = to_string(i) + " " + to_string(arr[i]);
        //         next[si] = i;
        //         s.push(i);
        //     }
        //     else{
        //         while(!s.empty() and arr[s.top()] >= arr[i]){
        //             int x = s.top();
        //             si = to_string(x) + " " + to_string(arr[x]);
        //             prev[si] = i;
        //             s.pop();
        //         }
        //         si = to_string(i) + " "+  to_string(arr[i]);
        //         if(!s.empty())
        //             next[si] = s.top();
        //         else
        //             next[si] = i;
        //         s.push(i);
        //     }
        // }
        // while(!s.empty()) {
        //     cout << s.top() << endl;
        //     si = to_string(s.top()) + " " + to_string(arr[s.top()]);
        //     prev[si] = s.top();
        //     s.pop();
        // }
        // // cout << "endl\n";
        // // for(auto &i : prev){
        // //     cout << i.first << " " << i.second << endl;
        // // }
        // // cout << "next\n";
        // // for(auto &i : next){
        // //     cout << i.first << " " << i.second << endl;
        // // }
        // for(int i = 0; i < arr.size(); i++){
        //     si = to_string(i) + " " + to_string(arr[i]);
        //     if(prev[si] == i){
        //         prev[si] = -1;
        //     }
        //     if(next[si] == i){
        //         next[si] = arr.size();
        //     }
        // }
        // // cout << "endl\n";
        // // for(auto &i : prev){
        // //     cout << i.first << " " << i.second << endl;
        // // }
        // // cout << "next\n";
        // // for(auto &i : next){
        // //     cout << i.first << " " << i.second << endl;
        // // }
        // // // int sum = 0;
        // // cout << endl<<endl;
        // for(int i =0; i < arr.size(); i++){
        //     si = to_string(i) + " " + to_string(arr[i]);
        //     // cout << arr[i] << ": ";
        //     // cout << (i - prev[si]) << " " << (next[si] - i)<< endl;
        //     sum = (sum%mod + (arr[i]%mod *1ll* ((i - prev[si] )%mod * (next[si] - i)%mod)%mod)%mod)%mod;
        // }
        // return sum;
    }
};