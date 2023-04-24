class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        // push the positive value of the stone onto the priority_queue
        for (int x : stones) pq.push(x); 
        // We need at least 2 stones to smash together, so we loop while
        // our heap has at least 2 stones inside.
        while (pq.size() >= 2) {
            // pop both stones off, the 1st is the largest stone.
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            // if the stones are not same, then the stone of weight x is detroyed
            // and the stone of weight y has new weight y - x.
            if (x != y) pq.push(y - x);
        }
        // if there are no stones left, return 0
        if (pq.size() == 0) return 0;
        // return the weight of the last remaining stone
        return pq.top();
    }
};