#include <bits/stdc++.h>
using namespace std;

struct fraction {
    long long p, q;
    
    fraction(long long p_ = 0, long long q_ = 1) : p(p_), q(q_) {
        simplify();
    }
    
    void simplify() {
        if (p == 0) {
            q = 1;
            return;
        }
        long long g = __gcd(p, q);
        p /= g;
        q /= g;
    }
    
    fraction operator+(const fraction& other) const {
        long long new_q = q / __gcd(q, other.q) * other.q;
        long long new_p = p * (new_q / q) + other.p * (new_q / other.q);
        return fraction(new_p, new_q);
    }
    
    fraction operator/(long long d) const {
        return fraction(p, q * d);
    }
    
    fraction& operator+=(const fraction& other) {
        *this = *this + other;
        return *this;
    }
};

int n, m;
vector<string> grid;
vector<vector<int>> nxt;
vector<fraction> flow;
bool has_collection;
int collection_tile;

int id(int r, int c) {
    return r * m + c;
}

bool inside(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool points_to(int r, int c, int dr, int dc) {
    char ch = grid[r][c];
    if (ch == '^') return dr == -1 && dc == 0;
    if (ch == 'v') return dr == 1 && dc == 0;
    if (ch == '<') return dr == 0 && dc == -1;
    if (ch == '>') return dr == 0 && dc == 1;
    return false;
}

void solve() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int total = n * m;
    nxt.assign(total, {});
    flow.assign(total, fraction(0, 1));
    has_collection = false;
    collection_tile = -1;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int u = id(r, c);
            char ch = grid[r][c];
            
            if (ch == '.') continue;
            if (ch == 'x') continue;
            
            if (ch == '^') {
                if (r == 0) {
                    has_collection = true;
                    collection_tile = u;
                } else if (grid[r-1][c] != '.') {
                    nxt[u].push_back(id(r-1, c));
                }
            }
            else if (ch == 'v') {
                if (r == n-1) {
                    has_collection = true;
                    collection_tile = u;
                } else if (grid[r+1][c] != '.') {
                    nxt[u].push_back(id(r+1, c));
                }
            }
            else if (ch == '<') {
                if (c == 0) {
                    has_collection = true;
                    collection_tile = u;
                } else if (grid[r][c-1] != '.') {
                    nxt[u].push_back(id(r, c-1));
                }
            }
            else if (ch == '>') {
                if (c == m-1) {
                    has_collection = true;
                    collection_tile = u;
                } else if (grid[r][c+1] != '.') {
                    nxt[u].push_back(id(r, c+1));
                }
            }
            else if (ch == 's') {
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (!inside(nr, nc)) continue;
                    char nb = grid[nr][nc];
                    if (nb == '.') continue;
                    if (nb == 'x') {
                        nxt[u].push_back(id(nr, nc));
                    } else if (nb == '^' || nb == 'v' || nb == '<' || nb == '>') {
                        if (!points_to(nr, nc, -dr[d], -dc[d])) {
                            nxt[u].push_back(id(nr, nc));
                        }
                    }
                }
            }
        }
    }
    
    vector<int> order;
    vector<bool> vis(total, false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : nxt[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
        order.push_back(u);
    };
    
    int start = id(0, 0);
    dfs(start);
    reverse(order.begin(), order.end());
    
    flow[start] = fraction(1, 1);
    
    for (int u : order) {
        if (grid[u/m][u%m] == 'x') continue;
        if (nxt[u].empty()) continue;
        
        fraction out;
        if (grid[u/m][u%m] == 's') {
            out = flow[u] / nxt[u].size();
        } else {
            out = flow[u];
        }
        
        for (int v : nxt[u]) {
            flow[v] += out;
        }
    }
    
    fraction ans(0, 1);
    if (has_collection && collection_tile != -1) {
        ans = flow[collection_tile];
    }
    
    cout << ans.p << " " << ans.q << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}