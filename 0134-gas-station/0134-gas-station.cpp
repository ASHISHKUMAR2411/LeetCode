class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
       int start = 0;
       int curr=0;
       int prev=0;
       for(int i = 0; i < n; i++){
           curr+=gas[i]-cost[i];
           if(curr<0){
               prev+=curr;
               start=i+1;
               curr=0;
           }
           
           
       }
       if(curr+prev>=0){
           return start;
       }
       else{
           return -1;
       }
        
        
    }
};