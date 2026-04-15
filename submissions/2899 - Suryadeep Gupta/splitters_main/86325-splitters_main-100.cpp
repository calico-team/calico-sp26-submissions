#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcdll(ll a, ll b){ return b ? gcdll(b, a % b) : a; }

struct Frac {
    ll num, den;
};

Frac make(ll n, ll d){
    if(n == 0) return {0,1};
    ll g = gcdll(abs(n), abs(d));
    return {n/g, d/g};
}

Frac add(Frac a, Frac b){
    ll n = a.num * b.den + b.num * a.den;
    ll d = a.den * b.den;
    return make(n,d);
}

Frac divi(Frac a, ll d){
    return make(a.num, a.den * d);
}

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int N,M; cin >> N >> M;
        vector<string> g(N);
        for(int i=0;i<N;i++) cin >> g[i];

        map<char,int> dir = {
            {'<',0},{'>',1},{'^',2},{'v',3}
        };

        vector<vector<vector<pair<int,int>>>> adj(N, vector<vector<pair<int,int>>>(M));
        vector<vector<int>> indeg(N, vector<int>(M,0));

        auto valid = [&](int x,int y){
            return x>=0 && y>=0 && x<N && y<M;
        };

        // Build graph
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                char c = g[i][j];
                if(c == '.' || c == 'X') continue;

                if(dir.count(c)){
                    int d = dir[c];
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if(valid(ni,nj)){
                        adj[i][j].push_back({ni,nj});
                        indeg[ni][nj]++;
                    }
                }
                else if(c == 'S'){
                    vector<pair<int,int>> nxt;
                    for(int d=0;d<4;d++){
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if(!valid(ni,nj)) continue;

                        char nc = g[ni][nj];
                        if(nc == 'X'){
                            nxt.push_back({ni,nj});
                        }
                        else if(dir.count(nc)){
                            int bd = dir[nc];
                            int bi = ni + dx[bd];
                            int bj = nj + dy[bd];
                            if(bi == i && bj == j) continue;
                            nxt.push_back({ni,nj});
                        }
                    }
                    for(auto &p : nxt){
                        adj[i][j].push_back(p);
                        indeg[p.first][p.second]++;
                    }
                }
            }
        }

        // Topological BFS
        queue<pair<int,int>> q;
        vector<vector<Frac>> dp(N, vector<Frac>(M, {0,1}));

        dp[0][0] = {1,1};

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(indeg[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            char c = g[i][j];

            if(c == '.' || c == 'X') continue;

            int k = adj[i][j].size();
            for(auto &p : adj[i][j]){
                int ni = p.first, nj = p.second;

                Frac contrib = dp[i][j];
                if(c == 'S') contrib = divi(contrib, k);

                dp[ni][nj] = add(dp[ni][nj], contrib);

                indeg[ni][nj]--;
                if(indeg[ni][nj] == 0){
                    q.push({ni,nj});
                }
            }
        }

        Frac ans = {0,1};

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                char c = g[i][j];
                if(dir.count(c)){
                    int d = dir[c];
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if(!valid(ni,nj)){
                        ans = add(ans, dp[i][j]);
                    }
                }
            }
        }

        ans = make(ans.num, ans.den);
        if(ans.num == 0) ans.den = 1;

        cout << ans.num << " " << ans.den << "\n";
    }
}