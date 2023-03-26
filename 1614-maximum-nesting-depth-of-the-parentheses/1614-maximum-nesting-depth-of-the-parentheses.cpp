class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxi = INT_MIN;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                st.pop();
            }
            int x = st.size();
            maxi  = max(maxi, x);
        }
        return maxi;
    }
};