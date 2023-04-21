class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> arr; 
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0] , end = intervals[0][1];
        int i = 1, n = intervals.size(); 
        while(i < n){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }
            else{
                vector<int> v;
                v.push_back(start);
                v.push_back(end);
                arr.push_back(v);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            i++;
        }
        if(arr.size()){
            vector<int> c = arr[arr.size() - 1];
            if(start != c[0]){
                vector<int> v;
                v.push_back(start);
                v.push_back(end);
                arr.push_back(v);
            }
        }
        else{
            vector<int> v;
            v.push_back(start);
            v.push_back(end);
            arr.push_back(v);
        }
        return arr;
    }
};