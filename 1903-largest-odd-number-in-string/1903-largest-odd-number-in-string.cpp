class Solution {
public:
    string largestOddNumber(string s) {
        int index = - 1;
        for(int i = s.size() - 1; i >= 0; i--){
            if((s[i] - '0')%2 == 1){
                index = i;
                break;
            }
        }
        if(index == -1) return "";
        else return s.substr(0, index + 1);
    }
};