#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define pb push_back
#define sz(x) (int)(x).size()
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
bool comp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    else return p1.first > p2.first;
}
int main()
 {
	//code
    fast;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mp;
        int x = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            mp[x]++;
        }
        vector<pair<int,int>> v;
        for(auto i : mp){
            v.push_back({i.second, i.first});
        }
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].first; j++){
                cout << v[i].second << " ";
            }
        }
        cout << endl;
    }
	return 0;
}