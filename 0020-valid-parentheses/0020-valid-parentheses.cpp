class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        for(int i  = 0; i < s.size(); i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                x.push(s[i]);
            }
            else{
                if(x.empty()) return false;
                else if((x.top() == '(' and s[i] != ')') or (x.top() == '[' and s[i] != ']') or (x.top() == '{' and s[i] != '}')){
                    return false;    
                }
                else{
                    x.pop();
                }
            }
        }
        if(x.empty())
            return true;
        else{
            return false;
        }
    }
};