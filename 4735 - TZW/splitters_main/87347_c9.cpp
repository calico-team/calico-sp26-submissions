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
vector<vector<int>> outputs;
vector<int> indeg;
vector<fraction> flow;
bool has_collection;
int collection_tile;

int idx(int r, int c) {
    return r * m + c;
}

bool conveyor_points_to(int r, int c, int dr, int dc) {
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
    outputs.assign(total, {});
    indeg.assign(total, 0);
    flow.assign(total, fraction(0, 1));
    has_collection = false;
    collection_tile = -1;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int id = idx(r, c);
            char ch = grid[r][c];
            
            if (ch == '.') {
            }
            else if (ch == 'x') {
            }
            else if (ch == '^') {
                if (r > 0 && grid[r-1][c] != '.') {
                    outputs[id].push_back(idx(r-1, c));
                } else if (r == 0) {
                    has_collection = true;
                    collection_tile = id;
                }
            }
            else if (ch == 'v') {
                if (r < n-1 && grid[r+1][c] != '.') {
                    outputs[id].push_back(idx(r+1, c));
                } else if (r == n-1) {
                    has_collection = true;
                    collection_tile = id;
                }
            }
            else if (ch == '<') {
                if (c > 0 && grid[r][c-1] != '.') {
                    outputs[id].push_back(idx(r, c-1));
                } else if (c == 0) {
                    has_collection = true;
                    collection_tile = id;
                }
            }
            else if (ch == '>') {
                if (c < m-1 && grid[r][c+1] != '.') {
                    outputs[id].push_back(idx(r, c+1));
                } else if (c == m-1) {
                    has_collection = true;
                    collection_tile = id;
                }
            }
            else if (ch == 's') {
                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};
                
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    
                    char nb = grid[nr][nc];
                    if (nb == '.') continue;
                    
                    if (nb == 'x') {
                        outputs[id].push_back(idx(nr, nc));
                    } else if (nb == '^' || nb == 'v' || nb == '<' || nb == '>') {
                        if (!conveyor_points_to(nr, nc, -dr[d], -dc[d])) {
                            outputs[id].push_back(idx(nr, nc));
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < total; i++) {
        for (int v : outputs[i]) {
            indeg[v]++;
        }
    }
    
    int start = idx(0, 0);
    flow[start] = fraction(1, 1);
    
    queue<int> q;
    for (int i = 0; i < total; i++) {
        if (indeg[i] == 0 && grid[i/m][i%m] != '.') {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (grid[u/m][u%m] == 'x') {
            continue;
        }
        
        if (outputs[u].empty()) {
            continue;
        }
        
        fraction out_flow;
        if (grid[u/m][u%m] == 's') {
            out_flow = flow[u] / outputs[u].size();
        } else {
            out_flow = flow[u];
        }
        
        for (int v : outputs[u]) {
            flow[v] += out_flow;
            indeg[v]--;
            if (indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    
    fraction collected(0, 1);
    if (has_collection && collection_tile != -1) {
        collected = flow[collection_tile];
    }
    
    cout << collected.p << " " << collected.q << "\n";
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