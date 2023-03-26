class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st1, st2;
        string ans;
        int count = 0;
        int n = s.size();
        for(int i =0; i < n; i++){
            if(s[i] == '('){
                count++;
                st1.push(s[i]);
            }
            else{
                count--;
                if(count == 0){
                    int size = st1.size() - 1;
                    while(size){
                        st2.push(st1.top());
                        st1.pop();
                        size--;
                    }
                    while(!st2.empty()){
                        ans += st2.top();
                        st2.pop();
                    }
                    st1.pop();
                }
                else{
                    st1.push(s[i]);
                }
            }
        }
        return ans;
    }
};