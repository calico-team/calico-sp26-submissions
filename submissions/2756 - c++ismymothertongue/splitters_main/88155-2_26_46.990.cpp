#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
const int mod = 1e9 + 7;
long long gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<string> ggrid(r);
        for (int i = 0; i < r; i++) {
            cin >> ggrid[i];
        }
        vector<vector<pair<long long,long long>>> f(
            r, vector<pair<long long,long long>>(c, {0, 1})
        );
        f[0][0] = {1, 1};
        pair <long long,long long> out = {0, 1};
        for (int step = 0; step < r * c + 5; step++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (f[i][j].first == 0) continue;
                    long long n = f[i][j].first;
                    long long d = f[i][j].second;
                    f[i][j] = {0, 1};
                    char tile = ggrid[i][j];
                    if (tile == 'X' || tile == '.') continue;
                    if (tile == 'S') {
                        vector<pair<int,int>> nexts;
                        int dr[] = {-1, 1, 0, 0};
                        int dc[] = {0, 0, -1, 1};
                        char rev[] = {'v', '^', '>', '<'};
                        for (int k = 0; k < 4; k++) {
                            int ni = i + dr[k];
                            int nj = j + dc[k];
                            if (ni >= 0 && ni < r && nj >= 0 && nj < c) {
                                if (ggrid[ni][nj] == 'X' ||
                                   (ggrid[ni][nj] != '.' &&
                                    ggrid[ni][nj] != 'S' &&
                                    ggrid[ni][nj] != rev[k])) {
                                    nexts.push_back({ni, nj});
                                }
                            }
                        }
                        long long sz = nexts.size();
                        for (auto &p : nexts) {
                            long long x, y;
                            long long g = gcd(d * sz, d, x, y);
                            long long nn = n / g;
                            long long dd = (d * sz) / g;
                            long long &fn = f[p.first][p.second].first;
                            long long &fd = f[p.first][p.second].second;
                            fn = fn * dd + nn * fd;
                            fd = fd * dd;
                            long long gx, gy;
                            long long gg = gcd(fn, fd, gx, gy);
                            fn /= gg;
                            fd /= gg;
                        }
                    }
                    else {
                        int ni = i, nj = j;
                        if (tile == '^') ni--;
                        else if (tile == 'v') ni++;
                        else if (tile == '<') nj--;
                        else if (tile == '>') nj++;
                        if (ni < 0 || ni >= r || nj < 0 || nj >= c) {
                            long long x, y;
                            long long g = gcd(out.first * d + n * out.second,
                                             out.second * d,
                                             x, y);

                            out.first = (out.first * d + n * out.second) / g;
                            out.second = (out.second * d) / g;

                        } else {
                            long long x, y;
                            long long g = gcd(f[ni][nj].first * d + n * f[ni][nj].second,
                                             f[ni][nj].second * d,
                                             x, y);

                            f[ni][nj].first =
                                (f[ni][nj].first * d + n * f[ni][nj].second) / g;

                            f[ni][nj].second =
                                (f[ni][nj].second * d) / g;
                        }
                    }
                }
            }
        }
        long long x, y;
        long long g = gcd(out.first, out.second, x, y);
        cout << out.first / g << " " << out.second / g << "\n";
    }
}
