class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        map<string, int> prev, next;
        int sum = 0, mod = 1e9+7;
        string si;
        for(int i = arr.size() - 1; i >= 0; i--){
            if(s.empty()){
                si = to_string(i) + " " + to_string(arr[i]);
                next[si] = i;
                s.push(i);
            }
            else{
                while(!s.empty() and arr[s.top()] >= arr[i]){
                    int x = s.top();
                    si = to_string(x) + " " + to_string(arr[x]);
                    prev[si] = i;
                    s.pop();
                }
                si = to_string(i) + " "+  to_string(arr[i]);
                if(!s.empty())
                    next[si] = s.top();
                else
                    next[si] = i;
                s.push(i);
            }
        }
        while(!s.empty()) {
            cout << s.top() << endl;
            si = to_string(s.top()) + " " + to_string(arr[s.top()]);
            prev[si] = s.top();
            s.pop();
        }
        // cout << "endl\n";
        // for(auto &i : prev){
        //     cout << i.first << " " << i.second << endl;
        // }
        // cout << "next\n";
        // for(auto &i : next){
        //     cout << i.first << " " << i.second << endl;
        // }
        for(int i = 0; i < arr.size(); i++){
            si = to_string(i) + " " + to_string(arr[i]);
            if(prev[si] == i){
                prev[si] = -1;
            }
            if(next[si] == i){
                next[si] = arr.size();
            }
        }
        // cout << "endl\n";
        // for(auto &i : prev){
        //     cout << i.first << " " << i.second << endl;
        // }
        // cout << "next\n";
        // for(auto &i : next){
        //     cout << i.first << " " << i.second << endl;
        // }
        // // int sum = 0;
        // cout << endl<<endl;
        for(int i =0; i < arr.size(); i++){
            si = to_string(i) + " " + to_string(arr[i]);
            // cout << arr[i] << ": ";
            // cout << (i - prev[si]) << " " << (next[si] - i)<< endl;
            sum = (sum%mod + (arr[i]%mod *1ll* ((i - prev[si] )%mod * (next[si] - i)%mod)%mod)%mod)%mod;
        }
        return sum;
    }
};