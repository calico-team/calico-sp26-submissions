#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> frac;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

frac reduce(ll p, ll q) {
    if (q < 0) { p = -p; q = -q; }
    ll g = gcd(abs(p), q);
    return make_pair(p/g, q/g);
}

frac fadd(frac a, frac b) {
    return reduce(a.first * b.second + b.first * a.second, a.second * b.second);
}

int N, M;
vector<string> factory;
ll col_p, col_q;

int drs[] = {-1, 1, 0, 0};
int dcs[] = {0, 0, -1, 1};
char back_char[] = {'v', '^', '>', '<'};

pair<int,int> getDirOffset(char c) {
    if (c == '^') return make_pair(-1, 0);
    if (c == 'v') return make_pair(1, 0);
    if (c == '<') return make_pair(0, -1);
    if (c == '>') return make_pair(0, 1);
    return make_pair(0, 0);
}


pair<ll,ll> solve() {
    col_p = 0; col_q = 1;

  
    vector<vector<int> > in_deg(N, vector<int>(M, 0));


    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            char tile = factory[r][c];
            if (tile == 'X' || tile == 'x' || tile == '.') continue;

            if (tile == '^' || tile == 'v' || tile == '<' || tile == '>') {
                pair<int,int> d = getDirOffset(tile);
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                    in_deg[nr][nc]++;
                }
            } else if (tile == 'S') {
                for (int d = 0; d < 4; d++) {
                    int nr = r + drs[d], nc = c + dcs[d];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    char ntile = factory[nr][nc];
                    if (ntile == 'X' || ntile == 'x') {
                        in_deg[nr][nc]++;
                    } else if (ntile == '^' || ntile == 'v' || ntile == '<' || ntile == '>') {
                        if (ntile != back_char[d]) {
                            in_deg[nr][nc]++;
                        }
                    }
                }
            }
        }
    }

  
    vector<vector<frac > > weight(N, vector<frac >(M, make_pair(0LL, 1LL)));
    weight[0][0] = make_pair(1LL, 1LL);

   
    queue<pair<int,int> > q;
  

    vector<vector<int> > remaining(N, vector<int>(M, 0));
    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++)
            remaining[r][c] = in_deg[r][c];

   
    q.push(make_pair(0, 0));

    while (!q.empty()) {
        pair<int,int> pos = q.front();
        q.pop();
        int r = pos.first, c = pos.second;

        frac w = weight[r][c];
        char tile = factory[r][c];

        if (tile == 'X' || tile == 'x') continue;

        if (tile == '^' || tile == 'v' || tile == '<' || tile == '>') {
            pair<int,int> d = getDirOffset(tile);
            int nr = r + d.first, nc = c + d.second;
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                // collected
                frac sum = fadd(make_pair(col_p, col_q), w);
                col_p = sum.first; col_q = sum.second;
            } else {
                weight[nr][nc] = fadd(weight[nr][nc], w);
                remaining[nr][nc]--;
                if (remaining[nr][nc] == 0) {
                    q.push(make_pair(nr, nc));
                }
            }
            continue;
        }

        if (tile == 'S') {
            vector<pair<int,int> > valid;
            for (int d = 0; d < 4; d++) {
                int nr = r + drs[d], nc = c + dcs[d];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                char ntile = factory[nr][nc];
                if (ntile == 'X' || ntile == 'x') {
                    valid.push_back(make_pair(nr, nc));
                } else if (ntile == '^' || ntile == 'v' || ntile == '<' || ntile == '>') {
                    if (ntile != back_char[d]) {
                        valid.push_back(make_pair(nr, nc));
                    }
                }
            }
            int k = (int)valid.size();
            if (k == 0) continue;
            frac each = reduce(w.first, w.second * (ll)k);
            for (int i = 0; i < k; i++) {
                int nr = valid[i].first, nc = valid[i].second;
                weight[nr][nc] = fadd(weight[nr][nc], each);
                remaining[nr][nc]--;
                if (remaining[nr][nc] == 0) {
                    q.push(make_pair(nr, nc));
                }
            }
            continue;
        }
    }

    if (col_p == 0) return make_pair(0LL, 1LL);
    return reduce(col_p, col_q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M;
        factory.assign(N, "");
        for (int i = 0; i < N; i++) cin >> factory[i];
        pair<ll,ll> ans = solve();
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
