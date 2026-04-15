#include <iostream>
#include <queue>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
#define MAXN (ll)(50)
#define f first
#define s second

bool v[MAXN + 1][MAXN + 1];
ll T, xg, yg, xm, ym, dx, dy, ans;

ll md(pair<ll, ll> c) {
    return (abs(25 - c.f) + abs(25 - c.s)) * 7;
}

bool val(pair<ll, ll> c) {
    return (c.f > 0 && c.f <= MAXN && c.s > 0 && c.s <= MAXN && !v[c.f][c.s]);
}

void solve() {
    cin >> xg >> yg >> xm >> ym;
    dx = 25 - xm;
    dy = 25 - ym;
    xg += dx, yg += dy;
    xm += dx, ym += dy;
    queue<pair<ll, pair<ll, ll>>> q;
    v[xg][yg] = 1;
    q.push({0, {xg, yg}});
    while (q.size()) {
        pair<ll, pair<ll, ll>> cur = q.front();
        q.pop();
        cur.f += 2;
        cur.s.f++;
        if (val(cur.s) && cur.f <= md(cur.s)) {
            v[cur.s.f][cur.s.s] = 1;
            q.push(cur);
        }
        cur.s.f -= 2;
        if (val(cur.s) && cur.f <= md(cur.s)) {
            v[cur.s.f][cur.s.s] = 1;
            q.push(cur);
        }
        cur.s.f++, cur.s.s++;
        if (val(cur.s) && cur.f <= md(cur.s)) {
            v[cur.s.f][cur.s.s] = 1;
            q.push(cur);
        }
        cur.s.s -= 2;
        if (val(cur.s) && cur.f <= md(cur.s)) {
            v[cur.s.f][cur.s.s] = 1;
            q.push(cur);
        }
    }
    ans = MAXN * MAXN;
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 1; j <= MAXN; j++) {
            ans -= v[i][j];
            v[i][j] = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}