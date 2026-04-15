#include <bits/stdc++.h>
#define GOOD_LUCK ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
constexpr int MAX = 1e+3 + 500, INF = 2e+16, MOD = 1e+9 + 7, K = 31;
int T = MAX / 2;
vector <vector <int>> v1(MAX+2, vector <int>(MAX+2, INF)), v2(MAX+2, vector <int>(MAX+2, INF));

void _() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            v1[i][j] = INF, v2[i][j] = INF;
        }
    }
    queue <pair<int, int>> q;
    q.push({c, d});
    v2[c + T][d + T] = 0;
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();
        for (int z = 0; z < 4; z++) {
            int ix = ux + dx[z], iy = uy + dy[z];
            if (ix + T < 0 || iy + T < 0 || ix + T > MAX || iy + T > MAX) continue;
            if (v2[ix + T][iy + T] == INF) {
                v2[ix + T][iy + T] = v2[ux + T][uy + T] + 7;
                q.push({ix, iy});
            }
        }
    }
    q.push({a, b});
    v1[a + T][b + T] = 0;
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();
        for (int z = 0; z < 4; z++) {
            int ix = ux + dx[z], iy = uy + dy[z];
            if (ix + T < 0 || iy + T < 0 || ix + T > MAX || iy + T > MAX) continue;
            if (v1[ix + T][iy + T] != INF) continue;
            if (v1[ux + T][uy + T] + 2 <= v2[ix + T][iy + T]) {
                v1[ix + T][iy + T] = v1[ux + T][uy + T] + 2;
                q.push({ix, iy});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            if (v2[i][j] != INF && v1[i][j] == INF) ans++;
        }
    }
    cout << ans;
}

signed main() {

    GOOD_LUCK

    int tests=1;
    cin >> tests;
    for (int i=1; i <= tests; i++) {
        _();
        cout << endl;
    }

    return 0;
}
