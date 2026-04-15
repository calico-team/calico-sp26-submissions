#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <iomanip>
#include <array>
#include <functional>
#include <bitset>
using namespace std;

void baseIO(string s = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (s.size()){
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

#define int long long
#define all(x) (x).begin(), (x).end()

pair<int, int> add(int a, int b, int c, int d) {
    int e = lcm(b, d);
    a *= e / b;
    c *= e / d;

    a += c;

    int g = gcd(a, e);
    a /= g;
    e /= g;

    return {a, e};
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (auto &x : g) cin >> x;

    vector<vector<vector<int>>> a(n, vector<vector<int>>(m, {0, 1}));

    a[0][0] = {1, 1};

    queue<pair<int, int>> q;
    q.push({0, 0});

    int ansp = 0, ansq = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        int i = x, j = y;
        if (g[x][y] == 'v') {
            i++;
            if (i == n) {
                auto ret = add(ansp, ansq, a[x][y][0], a[x][y][1]);
                ansp = ret.first;
                ansq = ret.second;
            } else {
                a[i][j] = a[x][y];
                q.push({i, j});
            }
        } else if (g[x][y] == '<') {
            j--;
            if (j == -1) {
                auto ret = add(ansp, ansq, a[x][y][0], a[x][y][1]);
                ansp = ret.first;
                ansq = ret.second;
            } else {
                a[i][j] = a[x][y];
                q.push({i, j});
            }
        } else if (g[x][y] == '>') {
            j++;
            if (j == m) {
                auto ret = add(ansp, ansq, a[x][y][0], a[x][y][1]);
                ansp = ret.first;
                ansq = ret.second;
            } else {
                a[i][j] = a[x][y];
                q.push({i, j});
            }
        } else if (g[x][y] == '^') {
            i--;
            if (i == -1) {
                auto ret = add(ansp, ansq, a[x][y][0], a[x][y][1]);
                ansp = ret.first;
                ansq = ret.second;
            } else {
                a[i][j] = a[x][y];
                q.push({i, j});
            }
        } else if (g[x][y] == 'X') {
            continue;
        } else if (g[x][y] == 'S') {

            auto ok = [&](int i, int j, int x, int y) {
                if (i < 0 || i >= n || j < 0 || j >= m) return true;
                if (g[i][j] == '.') return false;
                if (g[i][j] == '>' && j == y - 1) return false;
                if (g[i][j] == '<' && j == y + 1) return false;
                if (g[i][j] == '^' && i == x + 1) return false;
                if (g[i][j] == 'v' && i == x - 1) return false;
                return true;
            };

            auto outofbounds = [&](int i, int j) {
                if (i < 0 || i >= n || j < 0 || j >= m) return true;
                return false;
            };

            vector<pair<int, int>> pos;
            if (ok(x - 1, y, x, y)) pos.push_back({x - 1, y});
            if (ok(x + 1, y, x, y)) pos.push_back({x + 1, y});
            if (ok(x, y - 1, x, y)) pos.push_back({x, y - 1});
            if (ok(x, y + 1, x, y)) pos.push_back({x, y + 1});

            int sa = a[x][y][0], sb = a[x][y][1];
            int divide = pos.size();

            int G = gcd(sa, divide);
            sa /= G;
            divide /= G;
            sb *= divide;

            for (auto &pr : pos) {
                int xx = pr.first, yy = pr.second;
                if (outofbounds(xx, yy)) {
                    auto ret = add(ansp, ansq, sa, sb);
                    ansp = ret.first;
                    ansq = ret.second;
                } else if (g[xx][yy] == 'X') continue;
                else a[xx][yy] = {sa, sb}, q.push(pr);
            }
        }
    }
    cout << ansp << ' ' << ansq;
}

signed main() {
    baseIO();

    int t;
    cin >> t;
    while (t--){
        solve(), cout << '\n';
    }

    return 0;
}