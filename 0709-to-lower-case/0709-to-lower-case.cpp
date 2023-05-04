class Solution {
public:
    string toLowerCase(string S) {
        for(int i = 0; i < S.size(); i++){
            if(isalpha(S[i]))
            if(S[i] - 'a' >= 0 and S[i] - 'a' <= 25){
                S[i] = S[i];
            }
            else{
                S[i] |= ' ';
            }
        }
        return S;
    }
};