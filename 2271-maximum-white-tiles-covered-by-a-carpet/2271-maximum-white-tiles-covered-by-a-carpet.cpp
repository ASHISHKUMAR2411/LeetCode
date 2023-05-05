class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int cl) {
    sort(tiles.begin(), tiles.end());
    int n = tiles.size(); 
    int prefix[n + 1], et[n];

    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
      et[i] = tiles[i][1];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int start = tiles[i][0];
      int end = start + cl - 1;

      int indx = upper_bound(et, et + n, end) - et;
      int tsum = prefix[indx] - prefix[i];
      if (indx < n and end >= tiles[indx][0]) tsum += end - tiles[indx][0] + 1;

      ans = max(ans, tsum);

    }
    return ans;
        
    }
};