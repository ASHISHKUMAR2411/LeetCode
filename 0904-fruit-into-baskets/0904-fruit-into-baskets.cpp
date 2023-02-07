class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     set<int> g;
        int first = fruits[0],second;
       
        int index  =0,index1;
        g.insert(first);
        int size=1;
        int ans =1,count=0;
       
        for(int i=1;i<fruits.size();i++){
            if(fruits[i]==first){
                index=i;
                
            } if(fruits[i]==second){
                index1=i;
                
            }
            if(fruits[i]!=fruits[i-1] && g.count(fruits[i])==0){
                if(g.size()==2){
                   
                    if(fruits[i-1]==first){
                    g.erase(second);
                        size=2 + abs((i-1)-index1-1); ;
                }else{
                      g.erase(first);
                        size=2 + abs((i-1)-index-1);
                        
                }
                    
                    g.insert(fruits[i]);
                    first=fruits[i-1];
                    second = fruits[i];
                   
                   index = i-1;
                    index1=i;
                   
                }else{
                g.insert(fruits[i]);
                    if(count==0){
                    second = fruits[i];
                    index1=i;
                }
                    count=1;
                    size++;
            }
            }else{
                   size++;
            }
            ans=max(ans,size);
        }
        return ans;
    }
};