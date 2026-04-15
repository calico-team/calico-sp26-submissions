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
    
    fraction operator*(const fraction& other) const {
        return fraction(p * other.p, q * other.q);
    }
    
    fraction operator+(const fraction& other) const {
        long long new_q = q / __gcd(q, other.q) * other.q;
        long long new_p = p * (new_q / q) + other.p * (new_q / other.q);
        return fraction(new_p, new_q);
    }
    
    fraction operator/(long long d) const {
        return fraction(p, q * d);
    }
};

struct tile {
    char type;
    int id;
    vector<int> outputs;
    fraction flow;
};

int n, m;
vector<string> grid;
vector<tile> tiles;
vector<int> splitter_ids;
bool has_collection;
int collection_tile;

int idx(int r, int c) {
    return r * m + c;
}

bool is_valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool conveyor_points_to(int r, int c, int dr, int dc) {
    char ch = grid[r][c];
    if (ch == '^') return dr == -1 && dc == 0;
    if (ch == 'v') return dr == 1 && dc == 0;
    if (ch == '<') return dr == 0 && dc == -1;
    if (ch == '>') return dr == 0 && dc == 1;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        
        tiles.assign(n * m, {});
        splitter_ids.assign(n * m, -1);
        int splitter_count = 0;
        has_collection = false;
        collection_tile = -1;
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int id = idx(r, c);
                tiles[id].type = grid[r][c];
                if (grid[r][c] == 's') {
                    tiles[id].id = splitter_count++;
                    splitter_ids[id] = tiles[id].id;
                }
            }
        }
        
        vector<vector<int>> adjacency(n * m);
        
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int id = idx(r, c);
                char ch = grid[r][c];
                
                if (ch == '.') {
                }
                else if (ch == 'x') {
                }
                else if (ch == '^') {
                    if (r > 0) {
                        int nr = r - 1, nc = c;
                        if (grid[nr][nc] != '.') {
                            adjacency[id].push_back(idx(nr, nc));
                        }
                    } else {
                        has_collection = true;
                        collection_tile = id;
                    }
                }
                else if (ch == 'v') {
                    if (r < n - 1) {
                        int nr = r + 1, nc = c;
                        if (grid[nr][nc] != '.') {
                            adjacency[id].push_back(idx(nr, nc));
                        }
                    } else {
                        has_collection = true;
                        collection_tile = id;
                    }
                }
                else if (ch == '<') {
                    if (c > 0) {
                        int nr = r, nc = c - 1;
                        if (grid[nr][nc] != '.') {
                            adjacency[id].push_back(idx(nr, nc));
                        }
                    } else {
                        has_collection = true;
                        collection_tile = id;
                    }
                }
                else if (ch == '>') {
                    if (c < m - 1) {
                        int nr = r, nc = c + 1;
                        if (grid[nr][nc] != '.') {
                            adjacency[id].push_back(idx(nr, nc));
                        }
                    } else {
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
                        
                        if (!is_valid(nr, nc)) continue;
                        
                        char neighbor = grid[nr][nc];
                        if (neighbor == '.') continue;
                        
                        bool valid = false;
                        if (neighbor == 'x') {
                            valid = true;
                        } else if (neighbor == '^' || neighbor == 'v' || neighbor == '<' || neighbor == '>') {
                            if (!conveyor_points_to(nr, nc, -dr[d], -dc[d])) {
                                valid = true;
                            }
                        }
                        
                        if (valid) {
                            adjacency[id].push_back(idx(nr, nc));
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n * m; i++) {
            tiles[i].outputs = adjacency[i];
        }
        
        for (int i = 0; i < n * m; i++) {
            tiles[i].flow = fraction(0, 1);
        }
        
        int start = idx(0, 0);
        tiles[start].flow = fraction(1, 1);
        
        bool changed;
        do {
            changed = false;
            vector<fraction> new_flows(n * m, fraction(0, 1));
            
            for (int i = 0; i < n * m; i++) {
                if (tiles[i].flow.p == 0) continue;
                
                if (grid[i / m][i % m] == 'x') {
                    continue;
                }
                
                if (tiles[i].outputs.empty()) {
                    continue;
                }
                
                if (tiles[i].type == 's') {
                    fraction per_output = tiles[i].flow / tiles[i].outputs.size();
                    for (int out : tiles[i].outputs) {
                        new_flows[out] = new_flows[out] + per_output;
                        changed = true;
                    }
                } else {
                    for (int out : tiles[i].outputs) {
                        new_flows[out] = new_flows[out] + tiles[i].flow;
                        changed = true;
                    }
                }
            }
            
            for (int i = 0; i < n * m; i++) {
                if (new_flows[i].p != 0) {
                    tiles[i].flow = new_flows[i];
                }
            }
            
        } while (changed);
        
        fraction collected(0, 1);
        if (has_collection) {
            collected = collected + tiles[collection_tile].flow;
        }
        
        cout << collected.p << " " << collected.q << "\n";
    }
    
    return 0;
}