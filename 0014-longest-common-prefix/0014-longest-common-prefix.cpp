class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int length =INT_MAX;
        int N = arr.size();
        for(int i=0; i < N; i++){
            int n = arr[i].size();
            length = min(length, n);
        }
        int l = 0, r = length;
        while(l <= r){
            int mid = (l + r)/2;
            bool flag = true;
            string k = arr[0].substr(0, mid);
            for(int i = 0; i < N; i++){
                if(arr[i].substr(0, mid) != k){
                    flag = false;
                    break;
                }
            }
            if(flag){
                l = mid + 1;
            }
            else{
                r = mid -1 ;
            }
        }
        string ans = arr[0].substr(0,r);
        return ans;
    }
};