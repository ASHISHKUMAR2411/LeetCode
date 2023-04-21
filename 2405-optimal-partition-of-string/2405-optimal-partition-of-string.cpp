class Solution {
public:
    int partitionString(string s) {
        int count = 1; 
        int mask = 0;
        for(int i = 0; i < s.length(); i++){
            int shift = s[i] - 'a';
            if(mask & (1 << shift)){
                count++;
                mask = 0;
            }
            mask |= 1 << shift;
        }
        return count;
        
        
    }
};