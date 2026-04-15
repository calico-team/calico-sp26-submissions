#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

using ll = long long;

bool isConv(char ch) {
    return ch == '<' || ch == '>' || ch == '^' || ch == 'v';
}

char backChar(int dir) {
    if (dir == 0) return 'v';
    if (dir == 1) return '^';
    if (dir == 2) return '>';
    return '<';
}

ll gcdll(ll a, ll b) {
    if (a < 0) a=-a;
    if (b < 0) b=-b;
    while (b) {
        ll t = a%b;
        a=b;
        b=t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >>T;

    while (T--) {
        int numR, numC; cin>>numR>>numC;
        vector<string> grid(numR);
        for (string &row: grid) cin >> row;

        vector<vector<int>> id(numR, vector<int>(numC, -1));
        vector<pair<int,int>> cells;
        vector<int> splitDeg;

        for (int r = 0; r < numR; r++) {
            for (int c = 0; c < numC; c++) {
                if (grid[r][c] != '.') {
                    id[r][c] = cells.size();
                    cells.push_back({r, c});
                    splitDeg.push_back(0);
                }
            }
        }

        int numV = cells.size();
        vector<vector<int>> adj(numV);
        vector<int> indeg(numV);
        vector<char> collect(numV);

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for (int u = 0; u < numV; u++) {
            int r = cells[u].first, c = cells[u].second;
            char ch = grid[r][c];

            if (ch == 'X') continue;

            if (isConv(ch)) {
                int nr = r, nc = c;
                if (ch == '<') nc--;
                if (ch == '>') nc++;
                if (ch == '^') nr--;
                if (ch == 'v') nr++;

                if (0 <= nr && nr < numR && 0 <= nc && nc < numC) {
                    int v = id[nr][nc];
                    adj[u].push_back(v);
                    indeg[v]++;
                } else {
                    collect[u] = 1;
                }
                continue;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir], nc = c + dc[dir];
                if (nr < 0 || nr >= numR || nc < 0 || nc >= numC) continue;

                char nxt = grid[nr][nc];
                if (nxt == 'X' || (isConv(nxt) && nxt != backChar(dir))) {
                    int v = id[nr][nc];
                    adj[u].push_back(v);
                    indeg[v]++;
                }
            }

            splitDeg[u] = adj[u].size();
        }

        ll den = 1;
        for (int u = 0; u < numV; u++) {
            if (splitDeg[u]){
                den *= splitDeg[u];
            }
        }

        vector<int> topo, q;
        for (int u = 0; u < numV; u++) {
            if (!indeg[u]) q.push_back(u);
        }

        for (int i = 0; i < (int)q.size(); i++) {
            int u = q[i];
            topo.push_back(u);

            for (int v: adj[u]) {
                indeg[v]--;
                if (!indeg[v]) q.push_back(v);
            }
        }

        vector<ll> ways(numV);
        ways[id[0][0]] = den;
        ll num = 0;

        for (int u: topo) {
            ll cur = ways[u];
            if (!cur) continue;

            int r = cells[u].first, c = cells[u].second;
            char ch = grid[r][c];
            if (ch == 'X') continue;

            if (collect[u]) {
                num += cur;
            } else if (splitDeg[u]) {
                ll each = cur / splitDeg[u];
                for (int v: adj[u]) ways[v] += each;
            } else {
                ways[adj[u][0]] += cur;
            }
        }

        if (!num) {
            cout << "0 1\n";
            continue;
        }

        ll g = gcdll(num, den);
        cout<<num/g<<' '<<den/g<<'\n';
    }
}
