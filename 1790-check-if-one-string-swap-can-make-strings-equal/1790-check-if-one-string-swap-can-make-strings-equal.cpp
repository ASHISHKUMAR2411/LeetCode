class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i1 = -1, i2 = -1;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(i1 == -1) i1 = i;
                else if(i2 == -1) i2 = i;
                else break;
            } 
        }
        if(i1 == -1 and i2 == -1) return true;
        else if(i1 == -1 || i2 == -1) return false;
        swap(s1[i1], s1[i2]);
        if(s1 == s2) return true;
        else return false;
        
    }
};