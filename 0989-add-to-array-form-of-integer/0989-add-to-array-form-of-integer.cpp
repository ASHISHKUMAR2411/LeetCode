class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int i = n-1;
        int carry = 0;
        while(k and i >= 0){
            num[i] = num[i] + k%10 + carry;
            carry = num[i]/10;
            num[i] = num[i]%10;
            i--;
            k /= 10;
        }
        while(i >= 0){
            if(carry){
                num[i] = num[i] + carry;
                carry = num[i]/10;
                num[i] = num[i]%10;
                i--;
            }
            else{
                break;
            }
        }
        vector<int> ans;
        while(k){
            int extra = k%10 + carry;
            carry = extra/10;
            extra = extra%10;
           ans.push_back(extra);
            k /=10 ;
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        
        for(int i = 0; i < n; i++){
            ans.push_back(num[i]);
        }
        return ans;
    }
};