#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Frac {
    ll num, den;

    Frac(ll n=0, ll d=1){
        ll g = std::gcd(llabs(n), llabs(d));
        num = n/g;
        den = d/g;
        if(den < 0) num=-num, den=-den;
    }

    Frac operator+(const Frac& o) const {
        return Frac(num*o.den + o.num*den, den*o.den);
    }

    Frac operator*(const Frac& o) const {
        return Frac(num*o.num, den*o.den);
    }
};

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int dir(char c){
    if(c=='^') return 0;
    if(c=='>') return 1;
    if(c=='v') return 2;
    return 3;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int N,M;
        cin >> N >> M;

        vector<string> g(N);
        for(auto &r: g) cin >> r;

        auto inside = [&](int r,int c){
            return r>=0 && r<N && c>=0 && c<M;
        };

        vector<vector<Frac>> dp(N, vector<Frac>(M, Frac(0,1)));

        queue<pair<int,int>> q;

        if(g[0][0] != '.'){
            dp[0][0] = Frac(1,1);
            q.push({0,0});
        }

        vector<vector<int>> vis(N, vector<int>(M,0));
        vis[0][0]=1;

        Frac collect(0,1);

        while(!q.empty()){
            auto [r,c]=q.front(); q.pop();

            char cell = g[r][c];
            Frac cur = dp[r][c];

            if(cell=='X'){
                continue;
            }

            auto push = [&](int nr,int nc, Frac w){
                if(!inside(nr,nc)) {
                    collect = collect + cur * w;
                    return;
                }
                if(g[nr][nc]=='.') return;

                dp[nr][nc] = dp[nr][nc] + cur * w;
                if(!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            };

            if(cell=='^'||cell=='v'||cell=='<'||cell=='>'){
                int d=dir(cell);
                push(r+dr[d], c+dc[d], Frac(1,1));
            }

            else if(cell=='S'){
                vector<pair<int,int>> nxt;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k], nc=c+dc[k];
                    if(!inside(nr,nc)) continue;
                    if(g[nr][nc]=='.') continue;
                    nxt.push_back({nr,nc});
                }
                int d=nxt.size();
                if(d){
                    for(auto [nr,nc]: nxt){
                        push(nr,nc, Frac(1,d));
                    }
                }
            }
        }

        if(collect.num==0) cout<<"0 1\n";
        else cout<<collect.num<<" "<<collect.den<<"\n";
    }
}