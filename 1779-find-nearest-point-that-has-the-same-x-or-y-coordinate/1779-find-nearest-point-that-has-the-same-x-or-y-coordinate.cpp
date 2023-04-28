class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int maxi = INT_MAX, index = -1;
        for(int i = 0; i < points.size(); i++){
            // int z = 
            if(abs(points[i][0] - x) == 0 || abs(points[i][1] - y) == 0){
                if(maxi > (abs(points[i][0] - x) + abs(points[i][1] - y))){
                    maxi = (abs(points[i][0] - x) + abs(points[i][1] - y));
                    index = i;
                }
            }
        }
        return index;
    }
};