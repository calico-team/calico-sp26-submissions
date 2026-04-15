#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>  
using namespace std;

typedef long long ll;

ll my_gcd(ll a, ll b) {
    while (b) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

struct Frac {
    ll up, down;  
    
    Frac(ll u = 0, ll d = 1) {
        if (d < 0) { u = -u; d = -d; }
        ll g = my_gcd(u >= 0 ? u : -u, d);
        up = u / g;
        down = d / g;
    }
    
    Frac operator+(const Frac& o) const {
        return Frac(up * o.down + o.up * down, down * o.down);
    }
    
    Frac operator*(ll k) const {
        return Frac(up * k, down);
    }
    
    Frac operator/(ll k) const {
        return Frac(up, down * k);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> g(n);
        for (int i = 0; i < n; ++i) cin >> g[i];
        
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};
        
        vector<vector<vector<pair<int,int>>>> nxt(n, vector<vector<pair<int,int>>>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] != 'S') continue;
                for (int d = 0; d < 4; ++d) {
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    char c = g[ni][nj];
                    if (c == 'X') {
                        nxt[i][j].push_back({ni, nj});
                    } else if (c == '.' || c == 'S') {
                        continue;
                    } else {
                        int ti = ni, tj = nj;
                        switch (c) {
                            case '^': ti--; break;
                            case 'v': ti++; break;
                            case '<': tj--; break;
                            case '>': tj++; break;
                            default: break;
                        }
                        if (ti == i && tj == j) continue;
                        nxt[i][j].push_back({ni, nj});
                    }
                }
            }
        }
        
        vector<vector<Frac>> prob(n, vector<Frac>(m, Frac(0, 1)));
        queue<pair<int,int>> q;
        prob[0][0] = Frac(1, 1);
        q.push({0, 0});
        
        Frac ans(0, 1);  
        
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            Frac cur = prob[r][c];
            if (cur.up == 0) continue;
            
            char ch = g[r][c];
            if (ch == 'X') continue;
            if (ch == '.' || (ch != 'S' && ch != '^' && ch != 'v' && ch != '<' && ch != '>')) {
                continue;
            }
            
            if (ch == 'S') {
                int deg = nxt[r][c].size();
                if (deg == 0) continue;  
                Frac each = cur / deg;
                for (auto [nr, nc] : nxt[r][c]) {
                    if (prob[nr][nc].up == 0) q.push({nr, nc});
                    prob[nr][nc] = prob[nr][nc] + each;
                }
            } else {
                int nr = r, nc = c;
                switch (ch) {
                    case '^': nr--; break;
                    case 'v': nr++; break;
                    case '<': nc--; break;
                    case '>': nc++; break;
                    default: break;
                }
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    ans = ans + cur;  
                } else {
                    if (prob[nr][nc].up == 0) q.push({nr, nc});
                    prob[nr][nc] = prob[nr][nc] + cur;
                }
            }
        }
        
        cout << ans.up << " " << ans.down << "\n";
    }
    return 0;
}