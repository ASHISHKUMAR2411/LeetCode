class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.size(); i++){
            
            if(!(st.empty()) and st.top().first != s[i]){
                st.push(make_pair(s[i], 1));
            }
            else{
                if(st.empty()){
                    st.push(make_pair(s[i], 1));
                }
                else{
                    int val = st.top().second + 1;
                    char c = st.top().first;
                    if(val == k){
                        st.pop();
                    }
                    else{
                        st.pop();
                        st.push(make_pair(c, val));
                    }
                }
            }
        }
        string ans = "";
        while(!(st.empty())){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};