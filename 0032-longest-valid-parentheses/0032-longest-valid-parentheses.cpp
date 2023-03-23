class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;
        int maxi = 0; 
        stack<int> st;
        st.push(-1);
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ')'){
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxi = max(maxi, (i - st.top()));
                }
            }
            else{
                st.push(i);
            }
        }
        
        return maxi;
    }
};