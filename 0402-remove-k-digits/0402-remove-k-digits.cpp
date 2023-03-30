class Solution {
public:
    string removeKdigits(string num, int k) {
       stack<int> st;
        int n = num.size();
       for(int i=0;i<n;i++) {
           if(k) {
               while(!(st.empty()) and (num[i] - '0') < (st.top() - '0') and k ) {
                   st.pop();
                   k--;
               }
           }
           st.push(num[i]);
       }
        while(k and !(st.empty())){
            st.pop() ;
            k--;
        } 
        string ans = "", q;
        while(!(st.empty())) {
            ans += st.top();
            st.pop();
        }
        // cout << ans << endl;
        reverse(ans.begin(),ans.end());
        int i = 0;
        q = ans;
        // cout << ans << endl;
        while(ans[i] == '0' and i < n) {
            i++;
        }
        q.erase(0, i);
        if(q.size() == 0) {
             q = "0";
        }

        return q;
    }
};