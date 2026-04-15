#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;
 
void solve(){
    int K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
    int x, y; cin >> x >> y;
    
    vector<pair<int, int>>vp(K);
    vector<vector<int>>gr(N + 2, vector<int>(M + 2, INF));
    vp[0] = {x, y};
    int t = 0;

    while(true){
        x += Q;
        y += P;
        if(x >= N) x -= N;
        if(y >= M) y -= M;
        
        if(gr[x][y] != INF) break;
        gr[x][y] = ++t;
        // cout << x << " " << y << " " << t << endl;
    }

    int ans = 0;
    for(int i = 1; i < K; i++){
        int x, y; cin >> x >> y;
        if(gr[x][y] < gr[vp[ans].first][vp[ans].second]) ans = i;
        vp[i] = {x, y};
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}