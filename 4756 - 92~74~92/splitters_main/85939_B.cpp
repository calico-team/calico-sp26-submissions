#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef _debug
#include </home/tonyz/templates/debug.cpp>
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define vt vector
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ub upper_bound
#define lb lower_bound


const int inf = (int)2e9, mod = (int)1e9 + 7, mx = (int)2e5 + 10;
const ll infll = (ll)7e18;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct frac{
    ll x, y; 
    frac(ll xx, ll yy){
        x = xx, y = yy; 
        ll g = gcd(x, y);
        x /= g, y /= g;
    }
    void red(){
        ll g = gcd(x, y); x/=g, y/=g;
    }
};
frac addf(frac a, frac b){
    ll g = lcm(a.y, b.y);
    frac nx = {a.x * (g/a.y) + b.x * (g/b.y), g}; nx.red();
    return nx; 
}
int ddx[] = {1, -1, 0, 0}, ddy[] = {0,0, 1, -1};
void solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j]; 
        }
    }
    vector<vector<frac>> rat(n, vector<frac>(m, {0, 1}));
    vector<pii> cur = {{0,0}};
    rat[0][0] = {1, 1};
    frac res = {0, 1}; set<char> f = {'v', '^', '>', '<'}; 
    auto conv = [&](int x, int y) -> bool{
        return f.count(g[x][y]);
    };
    map<char, pii> mp; mp['>'] = {0, 1}; mp['<'] = {0, -1};
    mp['v'] = {1, 0};
    mp['^'] = {-1, 0}; 
    auto nxt = [&](int x, int y) -> pii{
        if(g[x][y] == '>')return {x, y+1};
        if(g[x][y] == '<')return {x, y-1};
        if(g[x][y] == 'v')return {x+1, y}; 
        if(g[x][y] == '^')return {x-1, y};
        return {-1, -1};
    };
    auto chk = [&](int dx, int dy, int x, int y) -> bool{
        if(x >= 0 && x < n && y >= 0 && y < m){
            if(g[x][y] == 'X')return true; 
            if(conv(x, y)){
                if(nxt(x, y) != make_pair(dx, dy)){
                    return true; 
                }
            } 
        }
        return false; 
    };
    while(true){
        if(cur.empty()){
            break;
        }
      //  debug(cur);
      /*  for(auto u : cur){
            debug(rat[u.first][u.second].x, rat[u.first][u.second].y);
        }*/
        vector<vector<frac>> new_rat(n, vector<frac>(m, {0, 1}));
        while(!cur.empty()){
            auto [x, y] = cur.back(); cur.pop_back();
            if(g[x][y] == 'X'){
                //destroy!! 
                continue; 
            }
            if(g[x][y] == 'S'){
                vt<pii> splt;
                for(int i = 0; i < 4; i++){
                    int nx = ddx[i] + x, ny = ddy[i] + y;
                    if(chk(x, y, nx, ny)){
                        splt.pb({nx, ny});
                    }
                }
                if(splt.size()){
                        frac add = rat[x][y];
                        add.y *= splt.size(); add.red();
                        for(auto [l, r] : splt){
                            new_rat[l][r] = addf(new_rat[l][r], add);
                        }
                    }

            }
            if(conv(x, y)){
                pii s = mp[g[x][y]];
                int nx = x + s.first, ny = y + s.second;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    res = addf(res, rat[x][y]); res.red(); 
                }else{
                    new_rat[nx][ny] = addf(new_rat[nx][ny], rat[x][y]);
                    new_rat[nx][ny].red(); 
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               // debug(new_rat[i][j].x, new_rat[i][j].y);
                if(new_rat[i][j].x != 0){
                    cur.pb({i,j});
                }
            }
        }
        rat = new_rat;
    }
    res.red();
    cout << res.x << ' ' << res.y << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}

