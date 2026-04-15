#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using frac = pair<ll,ll>;

ll gcdll(ll a, ll b){ return b ? gcdll(b, a % b) : a; }

frac add(frac a, frac b){
    ll num = a.first * b.second + b.first * a.second;
    ll den = a.second * b.second;
    ll g = gcdll(abs(num), abs(den));
    return {num/g, den/g};
}

frac divi(frac a, ll d){
    ll g = gcdll(abs(a.first), abs(d));
    return {a.first/g, (a.second * (d/g))};
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

        vector<vector<frac>> dp(N, vector<frac>(M, {0,1}));
        dp[0][0] = {1,1};

        queue<pair<int,int>> q;
        q.push({0,0});

        vector<vector<bool>> vis(N, vector<bool>(M,false));

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            if(vis[x][y]) continue;
            vis[x][y] = true;

            char c = g[x][y];
            frac cur = dp[x][y];

            if(c == 'X') continue;

            if(dir.count(c)){
                int d = dir[c];
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx < 0 || ny < 0 || nx >= N || ny >= M){
                    continue;
                }
                dp[nx][ny] = add(dp[nx][ny], cur);
                q.push({nx,ny});
            }
            else if(c == 'S'){
                vector<pair<int,int>> nxt;
                for(int d=0;d<4;d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx<0||ny<0||nx>=N||ny>=M) continue;
                    char nc = g[nx][ny];
                    if(nc == 'X'){
                        nxt.push_back({nx,ny});
                    }
                    else if(dir.count(nc)){
                        int bd = dir[nc];
                        int bx = nx + dx[bd];
                        int by = ny + dy[bd];
                        if(bx == x && by == y) continue;
                        nxt.push_back({nx,ny});
                    }
                }
                int k = nxt.size();
                for(auto &p : nxt){
                    frac portion = divi(cur, k);
                    dp[p.first][p.second] = add(dp[p.first][p.second], portion);
                    q.push(p);
                }
            }
        }

        frac ans = {0,1};

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                char c = g[i][j];
                if(dir.count(c)){
                    int d = dir[c];
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx<0||ny<0||nx>=N||ny>=M){
                        ans = add(ans, dp[i][j]);
                    }
                }
            }
        }

        ll gval = gcdll(abs(ans.first), abs(ans.second));
        ans.first /= gval;
        ans.second /= gval;

        if(ans.first == 0) ans.second = 1;

        cout << ans.first << " " << ans.second << "\n";
    }
}

void destroy_the_tiles(){}

void read_your_input(){}