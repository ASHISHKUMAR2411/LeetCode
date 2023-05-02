class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int start = 0, max = INT_MIN,zeroCounter=0;
        for(int end=0 ; end<A.size() ; end++){
            if(A[end]==0){
                zeroCounter++;
            }
            while(zeroCounter>k){
                if(A[start]==0){
                    zeroCounter--;
                }
                start++;
            }
            
            max = std::max(max,end-start+1);
        }
        
        return max;
    }
};