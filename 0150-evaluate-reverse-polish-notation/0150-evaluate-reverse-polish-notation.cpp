class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<string> st;
        int n = t.size();
        for(int i =0; i < n; i++){
            if(t[i] == "*" || t[i] == "+" || t[i] == "-" || t[i] == "/"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                if(t[i] == "*"){
                    st.push(to_string(x*y));
                }
                else if(t[i] == "+"){
                    st.push(to_string(x+y));
                }
                else if(t[i] == "-"){
                    st.push(to_string(y-x));
                }
                else if(t[i] == "/"){
                    st.push(to_string(y/x));
                }
            }
            else{
                st.push(t[i]);
            }
        }
        return stoi(st.top());
    }
};