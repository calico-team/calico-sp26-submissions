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
typedef __int128_t i128;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {

        int r, c;
        cin >> r >> c;

        vector<string> g(r);
        for (int i = 0; i < r; ++i) {
            cin >> g[i];
        }

        vector<vector<pair<i128, i128>>> f(
            r, vector<pair<i128, i128>>(c, {0, 1})
        );

        f[0][0] = {1, 1};
        pair<i128, i128> out = {0, 1};

        for (int step = 0; step < r * c + 5; ++step) {

            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {

                    if (f[i][j].first == 0) continue;

                    i128 n = f[i][j].first;
                    i128 d = f[i][j].second;

                    f[i][j] = {0, 1};

                    char tile = g[i][j];

                    if (tile == 'X' || tile == '.') continue;

                    if (tile == 'S') {

                        vector<pair<int,int>> nexts;

                        int dr[] = {-1, 1, 0, 0};
                        int dc[] = {0, 0, -1, 1};
                        char rev[] = {'v', '^', '>', '<'};

                        for (int k = 0; k < 4; ++k) {

                            int ni = i + dr[k];
                            int nj = j + dc[k];

                            if (ni >= 0 && ni < r && nj >= 0 && nj < c) {

                                if (g[ni][nj] == 'X' ||
                                   (g[ni][nj] != '.' &&
                                    g[ni][nj] != 'S' &&
                                    g[ni][nj] != rev[k])) {

                                    nexts.push_back({ni, nj});
                                }
                            }
                        }

                        i128 sz = nexts.size();

                        for (auto &p : nexts) {

                            i128 nn = n;
                            i128 dd = d * sz;

                            i128 a = nn, b = dd;
                            while (b) {
                                i128 t = a % b;
                                a = b;
                                b = t;
                            }
                            nn /= a;
                            dd /= a;

                            i128 &fn = f[p.first][p.second].first;
                            i128 &fd = f[p.first][p.second].second;

                            fn = fn * dd + nn * fd;
                            fd = fd * dd;

                            i128 x = fn, y = fd;
                            while (y) {
                                i128 t = x % y;
                                x = y;
                                y = t;
                            }
                            fn /= x;
                            fd /= x;
                        }
                    }

                    else {

                        int ni = i, nj = j;

                        if (tile == '^') ni--;
                        else if (tile == 'v') ni++;
                        else if (tile == '<') nj--;
                        else if (tile == '>') nj++;

                        if (ni < 0 || ni >= r || nj < 0 || nj >= c) {

                            i128 a = out.first * d + n * out.second;
                            i128 b = out.second * d;

                            i128 x = a, y = b;
                            while (y) {
                                i128 t = x % y;
                                x = y;
                                y = t;
                            }

                            out.first = a / x;
                            out.second = b / x;
                        }

                        else {

                            i128 &fn = f[ni][nj].first;
                            i128 &fd = f[ni][nj].second;

                            fn = fn * d + n * fd;
                            fd = fd * d;

                            i128 x = fn, y = fd;
                            while (y) {
                                i128 t = x % y;
                                x = y;
                                y = t;
                            }
                            fn /= x;
                            fd /= x;
                        }
                    }
                }
            }
        }

        if (out.first == 0) {
            cout << "0 1\n";
        } else {

            i128 a = out.first, b = out.second;
            i128 x = a, y = b;

            while (y) {
                i128 t = x % y;
                x = y;
                y = t;
            }

            a /= x;
            b /= x;

            if (a == 0) {
                cout << "0 1\n";
            } else {
                string sa, sb;

                i128 tmp = a;
                while (tmp) {
                    sa.push_back(char('0' + tmp % 10));
                    tmp /= 10;
                }
                reverse(sa.begin(), sa.end());

                tmp = b;
                while (tmp) {
                    sb.push_back(char('0' + tmp % 10));
                    tmp /= 10;
                }
                reverse(sb.begin(), sb.end());

                cout << sa << " " << sb << "\n";
            }
        }
    }
}
