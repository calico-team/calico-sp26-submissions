#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

auto pos(ll x, ll y, ll minX, ll minY, ll W) {
    return (y - minY + 1) * W + (x - minX + 1);
}

ll solve(int X_G, int Y_G, int X_M, int Y_M) {

    int R = (abs(X_G - X_M) + abs(Y_G - Y_M)) * 2 / 5 + 2; 

    ll minX = min(X_G, X_M - R), maxX = max(X_G, X_M + R);
    ll minY = min(Y_G, Y_M - R), maxY = max(Y_G, Y_M + R);

    ll W = maxX - minX + 3, H = maxY - minY + 3;

    vector<char> grid(W * H, 0);

    for (ll i = 0; i < W; i++) grid[i] = grid[(H - 1) * W + i] = 3;
    for (ll i = 0; i < H; i++) grid[i * W] = grid[i * W + W - 1] = 3;

    vector<ll> qg = {pos(X_G, Y_G, minX, minY, W)}, 
               qm = {pos(X_M, Y_M, minX, minY, W)};

    grid[qg[0]] = 1; grid[qm[0]] = 2;

    ll mycelium_count = 1, t = 0, d[] = {-1, 1, -W, W};

    vector<ll> ng, nm; 

    while (!qm.empty()) {
        t++;
        if (t % 2 == 0) {
            ng.clear(); 
            for (ll u : qg) {
                for (int i = 0; i < 4; i++) {
                    ll v = u + d[i];

                    if (v >= 0 && v < (ll)grid.size() && grid[v] == 0) {
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
                    if (v >= 0 && v < (ll)grid.size() && grid[v] == 0) {
                        grid[v] = 2;
                        mycelium_count++;
                        nm.push_back(v);
                    }
                }
            }
            qm = move(nm);
        }
        if (t > 200000) break;
    }

    return mycelium_count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}