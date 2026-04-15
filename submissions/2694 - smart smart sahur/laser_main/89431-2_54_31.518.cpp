#include <bits/stdc++.h>
#define DEBUG false
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define endl '\n'
using namespace std;
struct hash_pair{
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first)^(hash<int>()(p.second)<<1);
    }
};
signed main() {
    if(!DEBUG){
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    }
    else{
        (void)freopen("test.in", "r", stdin);
        (void)freopen("test.out", "w", stdout); 
    }
    int T;
    cin>>T;
    while(T--){
        int K, N, M, P, Q;
        cin>>K>>N>>M>>P>>Q;
        vector<pair<int, int>> asteroids;
        unordered_map<pair<int,int>, int, hash_pair> map;
        asteroids.assign(K, make_pair(0, 0));
        bool found = false;
        for(int i = 0; i < K; i++){
            int a, b;
            cin>>a>>b;
            asteroids[i].first=a;
            asteroids[i].second=b;
            map[asteroids[i]] = i;
        }
        int x=asteroids[0].first;
        int y=asteroids[0].second;
        while(!found){
            x+=Q;
            y+=P;
            if(x>N){
                x=x-N;
            }
            if(x<0){
                x=x+N;
            }
            if(y>M){
                y=y-M;
            }
            if(y<0){
                y=y+M;
            }
            if(map.count({x, y})){
                cout<<map[{x, y}]<<endl;
                found = true;
                break;
            }
        }
    }
}