class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int l = 1, r = a.size();
        int maxi = INT_MIN;
        while(l <= r){
            int mid = (l+r)/2;
            bool flag = false;
            int f = 0, t = 0;
            for(int i = 0; i < mid; i++){
                if(a[i] == 'T') t++;
                else f++;
            }
            for(int i = mid; i < a.size(); i++){
                if(f <= k || t <= k){
                    flag = true;
                }
                if(a[i - mid] == 'T') t--;
                else f--;
                if(a[i] == 'T') t++;
                else f++;
            }
            if(f <= k || t <= k){
                flag = true;
            }
            if(flag){
                l = mid + 1;
                maxi = max(maxi, mid);
            }
            else{
                r = mid - 1;
            }
        }
        return maxi;
    }
};