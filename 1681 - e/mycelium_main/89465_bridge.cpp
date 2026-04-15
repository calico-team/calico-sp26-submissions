#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

auto pos(ll x, ll y, ll minX, ll minY, ll W) {
    return (y - minY + 1) * W + (x - minX + 1);
}

ll solve() {
    int XG, YG, XM, YM;
    cin >> XG >> YG >> XM >> YM;

    if (XG == XM && YG == YM) return 0;

    int R = (abs(XG - XM) + abs(YG - YM)) * 2 / 5 + 10;

    ll minX = min(XG, XM) - R;
    ll maxX = max(XG, XM) + R;
    ll minY = min(YG, YM) - R;
    ll maxY = max(YG, YM) + R;

    ll W = maxX - minX + 3;
    ll H = maxY - minY + 3;

    vector<char> grid(W * H, 0);

    ll d[] = {-1, 1, -W, W};

    for (ll x = 0; x < W; x++) {
        grid[x] = 3;
        grid[(H - 1) * W + x] = 3;
    }
    for (ll y = 0; y < H; y++) {
        grid[y * W] = 3;
        grid[y * W + (W - 1)] = 3;
    }

    vector<ll> qg = {pos(XG, YG, minX, minY, W)};
    vector<ll> qm = {pos(XM, YM, minX, minY, W)};

    grid[qg[0]] = 1;
    grid[qm[0]] = 2;

    ll mycelium_total = 1;
    int t = 0;

    vector<ll> ng, nm;

    while (!qm.empty()) {
        t++;

        if (t % 2 == 0) {
            ng.clear();
            for (ll u : qg) {
                for (int i = 0; i < 4; i++) {
                    ll v = u + d[i];
                    if (grid[v] == 0) {
                        grid[v] = 1;
                        ng.push_back(v);
                    }
                }
            }
            qg = move(ng);
        }

        if (t % 7 == 0) {
            nm.clear();
            for (ll u : qm) {
                for (int i = 0; i < 4; i++) {
                    ll v = u + d[i];
                    if (grid[v] == 0) {
                        grid[v] = 2;
                        mycelium_total++;
                        nm.push_back(v);
                    }
                }
            }
            qm = move(nm);
        }
    }

    return mycelium_total;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
}