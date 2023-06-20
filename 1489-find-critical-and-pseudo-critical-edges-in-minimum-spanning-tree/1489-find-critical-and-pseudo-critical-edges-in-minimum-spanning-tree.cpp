class UF{
private:
    vector<int> parent;
public:
    UF(int n){
        parent = vector<int>(n, 0);
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    
    int find(int n){
        if(parent[n] != n) parent[n] = find(parent[n]);
        return parent[n];
    }
    
    bool join(int a, int b){
        auto p1(find(a)), p2(find(b));
        if(p1 == p2) return false;
        parent[p1] = p2;
        return true;
    }
};

class Solution {
// This function allows us to create a MST, while "taking" certain edges, and "ignoring" certain edges.
// edges is <to, from, cost of edge, index in original array of bookkeeping for return statement>
//
// Ignored edge is the edge indicated by a 0-based index in the sorted edges from
// smallest to greatest in cost.  This represents an edge that CANNOT be used, and
// helps us find if an edge is critical.  If it is critical, leaving out this edge will
// give us a bigger mst cost.
//
// Taken edge is the edge indicated by a 0-based index in the sorted edges from
// smallest to greatest in cost. If this edge is taken, and we can get the same mst cost,
// AND THIS EDGE IS NOT CRITICAL, this means it is pseudo-critical.
int MST(int n, vector<tuple<int, int, int, int>>& edges, int ignored_edge, int taken_edge){
    auto u = UF(n);
    int ret = 0;
    
    // If there exists an edge we have to take, take it in the beginning before running Kruskal
    if(taken_edge != -1){
        auto [from, to, cost, idx] = edges[taken_edge];
        u.join(from, to);
        ret += cost; 
    }
    
    // Kruskal, but we ignore edge i, if told to.
    for(int i = 0; i < edges.size(); ++i){
        if(i == ignored_edge) 
            continue;
        auto [from, to, cost, idx] = edges[i];
        int p1(u.find(from)), p2(u.find(to));
        if(p1 == p2) continue;
        u.join(from, to);
        ret += cost;
    }
    
    for(int i = 0; i < n; ++i){
        if(u.find(i) != u.find(0)) return INT_MAX;
    }
    
    return ret;
}
public:
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    vector<tuple<int, int, int, int>> edge_list;
    int N(n);
    vector<int> critical, pseudo;
    for(int i = 0; i < edges.size(); ++i){
        edge_list.emplace_back(edges[i][0], edges[i][1], edges[i][2], i);
    }

    // Sort from smallest weight -> biggest weight of edge according to Kruskal
    sort(begin(edge_list), end(edge_list), [](auto& a, auto& b){ return get<2>(a) < get<2>(b);});

    // Find smallest MST weight, with no restrictions on what edge to keep & what edge to exclude.
    int optimal = MST(n, edge_list, -1, -1);
    
    for(int i = 0; i < edges.size(); ++i){
        // If excluding this edge makes kruskal give us a higher weight of MST, this edge is used in all MSTs, and is thus critical
        if(MST(n, edge_list, i, -1) > optimal) critical.push_back(get<3>(edge_list[i]));
        // If this edge is NOT critical AND always including this edge gives us a MST with same weight as optimal, this edge is psudo-critical
        else if(MST(n, edge_list, -1, i) == optimal) pseudo.push_back(get<3>(edge_list[i]));
    }
    
    return {critical, pseudo};
}


};
// My Solution One Test Case Failing 
// // Class to implement DSU for Kruskal's Algorithm 
// class DSU {
//     public:
//         vector<int> parent, rank, size;
//         DSU(int n){
//             parent.resize(n);
//             rank.resize(n);
//             size.resize(n);
//             for(int i =0 ; i < n; i++){
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//         }
//         int find_parent(int n){
//             if(n == parent[n]) return n;
//             return parent[n] = find_parent(parent[n]);
//         }
//         void unionByRank(int u, int v){
//             int pv = find_parent(v);
//             int pu = find_parent(u);
//             if(pv == pu) return;
//             if(rank[pv] > rank[pu]){
//                 parent[pu] = pv;
//             }
//             else if(rank[pu] > rank[pv]){
//                 parent[pv] = pu;
//             }
//             else{
//                 parent[pv] = pu;
//                 rank[pu] = rank[pv] + 1;
//             }
//         }
//         void unionBySize(int u, int v){
//             int pv = find_parent(v);
//             int pu = find_parent(u);
//             if(pv == pu) return;
//             if(size[pv] > size[pu]){
//                 parent[pu] = pv;
//                 size[pv] += size[pu];
//             }
//             else{
//                 parent[pv] = pu;
//                 size[pu] += size[pv];
//             }
//         }
// };


// bool comp(const vector<int> &p1,const vector<int> &p2){
//     return p1[2] < p2[2];
// }
// class Solution {
//     int findMST(int &n, vector<vector<int>> &edges, vector<int> incEdge, vector<int> excEdge){
//         // edges are already sorted
//         DSU ob(n);
//         int sum = 0;
//         if(incEdge.size() != 0){
//             sum += incEdge[2];
//             ob.unionByRank(incEdge[0], incEdge[1]);
//         }
//         for (auto it : edges) {
//             if(excEdge.size() and it == excEdge) continue;
//             int wt = it[2];
//             int u = it[0];
//             int v = it[1];
//             if (ob.find_parent(u) != ob.find_parent(v)) {
//                 sum += wt;
//                 ob.unionByRank(u, v);
//             }
//         }
//         return sum;
//     }
// public:
//     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
//         // storing the cost for reference
//         vector<int> cri, pseudo;
//         sort(edges.begin(), edges.end(), comp);
//         int cost = findMST(n, edges, {}, {});
//         for(int i = 0; i < edges.size(); i++){
//             int cost_e = findMST(n, edges, {}, edges[i]);
//             if(cost_e > cost){
//                 cri.push_back(i);
//             }
//             else{
//                 int cost_i = findMST(n, edges, edges[i], {});
//                 if(cost_i == cost){
//                     pseudo.push_back(i);
//                 }
//             }
//         }
//         return {cri,pseudo};
        
        
//     }
// };