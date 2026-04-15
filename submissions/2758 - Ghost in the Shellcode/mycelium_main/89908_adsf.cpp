#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(int X_G, int Y_G, int X_M, int Y_M) {
    map<pair<int, int>, int> grd;
    queue<pair<int, int>> q;
    grd[{X_M, Y_M}] = 0;
    q.push({X_M, Y_M});

    int c = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        c++;

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];
            if (grd.find({nx, ny}) == grd.end()) {
                ll dist_m = abs((ll)nx - X_M) + abs((ll)ny - Y_M);
                ll dist_g = abs((ll)nx - X_G) + abs((ll)ny - Y_G);
                if (7 * dist_m < 2 * dist_g) {
                    grd[{nx, ny}] = 0;
                    q.push({nx, ny});
                } else {
                    grd[{nx, ny}] = 1;
                }
            }
        }
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
    return 0;
}