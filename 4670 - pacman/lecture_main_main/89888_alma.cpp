/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
#define int ll
#define ln '\n'
#define INFll 1e18

struct node {
    int x, y, u, v, aura;
};

const int MAX_DIM = 2005;
int P[MAX_DIM][MAX_DIM];
vector<node> st[MAX_DIM];
int mx;

int get_sum(int r1, int c1, int r2, int c2) {
    if (r1 < 1) r1 = 1;
    if (c1 < 1) c1 = 1;
    if (r2 >= mx) r2 = mx - 1;
    if (c2 >= mx) c2 = mx - 1;
    if (r1 > r2 || c1 > c2) return 0;
    return P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1];
}

void solve() {
    int _n, _m, _k;
    if (!(cin >> _n >> _m >> _k)) return;

    mx = _n + _m + 2;
    vector<node> can;
    can.reserve(_n * _m);

    for (int i = 0; i <= mx; ++i) {
        for (int j = 0; j <= mx; ++j) {
            P[i][j] = 0;
        }
        st[i].clear();
    }

    for (int i = 0; i < _n; ++i) {
        string row;
        cin >> row; 
        vector<int> L(_m, 0), R(_m, 0);

        int cnt = 0;
        for (int j = 0; j < _m; ++j) {
            L[j] = cnt;
            if (row[j] == '#') cnt++;
        }
        cnt = 0;
        for (int j = _m - 1; j >= 0; --j) {
            R[j] = cnt;
            if (row[j] == '#') cnt++;
        }

        for (int j = 0; j < _m; ++j) {
            if (row[j] == '-') {
                int u = i + j;
                int v = i - j + _m - 1;
                int aura = min(L[j], R[j]);
                can.push_back({i, j, u, v, aura});
                
                P[u + 1][v + 1]++;
                st[u].push_back({i, j, u, v, aura});
            }
        }
    }

    if (_k == 1) {
        node best = can[0];
        for (const auto &s : can) {
            if (s.aura < best.aura) best = s;
        }
        cout << best.x << " " << best.y << ln;
        return;
    }

    for (int i = 1; i <= mx; ++i) {
        for (int j = 1; j <= mx; ++j) {
            P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }

    auto check = [&](int D) {
        for (int i = 0; i < mx - D - 1; ++i) {
            for (int j = 0; j < mx - D - 1; ++j) {
                if (get_sum(i + 1, j + 1, i + D + 1, j + D + 1) >= _k)
                    return true;
            }
        }
        return false;
    };

    int l = 0, r = _n + _m, res = _n + _m, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    // `v`-yə görə sıralayırıq
    for (int i = 0; i < mx; ++i) {
        sort(st[i].begin(), st[i].end(), [](const node &a, const node &b) {
            return a.v < b.v;
        });
    }

    long long anss = INFll;
    vector<node> ans;
    ans.reserve(_k);
    
    vector<node> cand;
    cand.reserve(can.size());

    for (int i = 0; i < mx - res - 1; ++i) {
        for (int j = 0; j < mx - res - 1; ++j) {
            if (get_sum(i + 1, j + 1, i + res + 1, j + res + 1) >= _k) {
                cand.clear();
                for (int u = i; u <= min(i + res, mx - 1); ++u) {
                    auto it = lower_bound(st[u].begin(), st[u].end(), j, [](const node &s, int val) {
                        return s.v < val;
                    });
                    while (it != st[u].end() && it->v <= j + res) {
                        cand.push_back(*it);
                        ++it;
                    }
                }
                if (cand.size() >= _k) {
                    nth_element(cand.begin(), cand.begin() + _k, cand.end(), [](const node &a, const node &b){
                        return a.aura < b.aura;
                    });
                    
                    long long cur_sum = 0;
                    for(int cnt = 0; cnt < _k; cnt++) {
                        cur_sum += cand[cnt].aura;
                    }
                    
                    if(cur_sum < anss) {
                        anss = cur_sum;
                        ans.assign(cand.begin(), cand.begin() + _k);
                    }
                    
                    if (anss == 0) goto end_search;
                }
            }
        }
    }

end_search:
    for (const auto &s : ans) {
        cout << s.x << " " << s.y << ln;
    }
}

signed main() {
    // Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    if (cin >> t) {
        for (int cases = 0; cases < t; cases++) {
            solve();
        }
    }
    return 0;
}