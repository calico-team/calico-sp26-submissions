/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <vector>

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 4e18

#ifdef ONPC
#include <algo.hpp>
#else
#define dbg(...)
#define dbg_out(...)
#endif
#define int ll

struct node {
    int x, y, u, v, aura;
};

int sum(const vector<vector<int>> &P, int r1, int c1, int r2, int c2) {
    r1 = max<ll>(1, r1);
    c1 = max<ll>(1, c1);
    r2 = min((int)P.size() - 1, r2);
    c2 = min((int)P[0].size() - 1, c2);
    if (r1 > r2 || c1 > c2)
        return 0;
    return P[r2][c2] - P[r1 - 1][c2] - P[r2][c1 - 1] + P[r1 - 1][c1 - 1];
}

int _n, _m, _k, N;
vector<vector<char>> g;

inline void systemd() {
    N = 0; // i learned from prevus question
    g.clear();
    g.resize(_n, vector<char>(_m));
}

char solve() {
    if (!(cin >> _n >> _m >> _k))
        return 1;
    systemd();

    vector<node> can;

    for (int i = 0; i < _n; ++i) {
        for (int j = 0; j < g[i].size(); j++) {
            cin >> g[i][j];
        }
        vector<int> L(_m, 0);
        vector<int> R(_m, 0);

        int cnt = 0;
        for (int j = 0; j < _m; ++j) {
            L[j] = cnt;
            if (g[i][j] == '#')
                cnt++;
        }
        cnt = 0;
        for (int j = _m - 1; j >= 0; --j) {
            R[j] = cnt;
            if (g[i][j] == '#')
                cnt++;
        }

        for (int j = 0; j < _m; ++j) {
            if (g[i][j] == '-') {
                int u = i + j;
                int v = i - j + _m - 1;
                int aura = min(L[j], R[j]);
                can.push_back({i, j, u, v, aura});
                N = max(N, aura);
            }
        }
    }

    if (_k == 1) {
        node best = can[0];
        for (const auto &s : can) {
            if (s.aura < best.aura)
                best = s;
        }
        cout << best.x << " " << best.y << "\n";
        return 0;
    }

    int mx = _n + _m + 2;
    vector<vector<int>> P(mx, vector<int>(mx, 0));

    for (const auto &s : can) {
        P[s.u + 1][s.v + 1]++;
    }

    for (int i = 1; i < mx; ++i) {
        for (int j = 1; j < mx; ++j) {
            P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }

    auto check = [&](int D) {
        for (int i = 0; i < mx - 1; ++i) {
            for (int j = 0; j < mx - 1; ++j) {
                if (sum(P, i + 1, j + 1, i + D + 1, j + D + 1) >= _k)
                    return true;
            }
        }
        return false;
    };

    int l = 0, r = _n + _m, res = _n + _m, mid;
    while (l <= r) {
        mid = (l + r) >> 1LL;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    vector<vector<node>> st(mx);
    for (const auto &s : can) {
        st[s.u].push_back(s);
    }
    for (int i = 0; i < mx; ++i) {
        sort(st[i].begin(), st[i].end(), [](const node &a, const node &b) {
            return a.v < b.v;
        });
    }

    long long anss = INFll;
    vector<node> ans;
    // XXX: Time limit is strict about rules
    // for (int i = 0; i < mx - 1; ++i) {
    //     for (int j = 0; j < mx - 1; ++j) {
    //         if (sum(P, i + 1, j + 1, i + res + 1, j + res + 1) >= _k) {
    //             vector<node> cand;
    //             for (int u = i; u <= min(i + res, mx - 1); ++u) {
    //                 auto it = lower_bound(st[u].begin(), st[u].end(), j, [](const node &s, int val) {
    //                     return s.v < val;
    //                 });
    //                 while (it != st[u].end() && it->v <= j + res) {
    //                     cand.push_back(*it);
    //                     ++it;
    //                 }
    //             }
    //
    //             if (cand.size() >= _k) {
    //                 long long cur = 0;
    //                 for (int k = 0; k < _k; ++k) {
    //                     cur += cand[k].aura;
    //                 }
    //                 if (cur < anss) {
    //                     anss = cur;
    //                     ans.assign(cand.begin(), cand.begin() + _k);
    //                 }
    //             }
    //         }
    //     }
    // }

    int ansi = -1, ansj = -1;

    int mxa = mx * 2;
    vector<vector<int>> ptb(mxa);
    for (int p = 0; p < (int)can.size(); ++p) {
        ptb[can[p].v].push_back(p);
    }
    for (int v = 0; v < mxa; ++v) {
        if (!ptb[v].empty()) {
            sort(ptb[v].begin(), ptb[v].end(), [&](int a, int b) {
                return can[a].u < can[b].u;
            });
        }
    }

    vector<int> L(mxa, 0), R(mxa, 0);
    vector<int> freq(N + 1, 0);

    for (int i = 0; i < mx; ++i) {
        for (int v = 0; v < mxa; ++v) {
            while (L[v] < (int)ptb[v].size() && can[ptb[v][L[v]]].u < i)
                L[v]++;
            while (R[v] < (int)ptb[v].size() && can[ptb[v][R[v]]].u <= i + res)
                R[v]++;
        }

        fill(freq.begin(), freq.end(), 0);
        int cnt = 0;

        int vmax = min(res, mxa - 1);
        for (int v = 0; v <= vmax; ++v) {
            for (int idx = L[v]; idx < R[v]; ++idx) {
                freq[can[ptb[v][idx]].aura]++;
                cnt++;
            }
        }

        auto calc = [&](int curj) {
            if (cnt >= _k) {
                long long cur = 0;
                int tar = _k;
                for (int a = 0; a <= N && tar > 0; ++a) {
                    if (freq[a] > 0) {
                        int take = min(freq[a], tar);
                        cur += (long long)take * a;
                        tar -= take;
                        if (cur >= anss)
                            break;
                    }
                }
                if (tar == 0 && cur < anss) {
                    anss = cur;
                    ansi = i;
                    ansj = curj;
                }
            }
        };

        calc(0);

        for (int j = 1; j < mx; ++j) {
            for (int idx = L[j - 1]; idx < R[j - 1]; ++idx) {
                freq[can[ptb[j - 1][idx]].aura]--;
                cnt--;
            }
            if (j + res < mxa) {
                for (int idx = L[j + res]; idx < R[j + res]; ++idx) {
                    freq[can[ptb[j + res][idx]].aura]++;
                    cnt++;
                }
            }

            calc(j);
        }
    }

    vector<node> cands;
    for (const auto &p : can) {
        if (p.u >= ansi && p.u <= ansi + res && p.v >= ansj && p.v <= ansj + res) {
            cands.push_back(p);
        }
    }

    sort(cands.begin(), cands.end(), [](const node &a, const node &b) {
        return a.aura < b.aura;
    });

    for (int k = 0; k < _k; ++k) {
        cout << cands[k].x << " " << cands[k].y << ln;
    }
    // dbg(cands);
    for (const auto &s : ans) {
        cout << s.x << " " << s.y << ln;
    }
    // dbg(ans);
    return 0;
}

// Attack on titan<3

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1e9;
    cin >> t;
    for (int cases = 0; cases < t; cases++) {
        if (solve())
            break;
#ifdef ONPC
        cerr << "__________\n";
#endif
    }
}
// Just Imaginary
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⢀⣴⣾⠀⠀⠀⡀⢀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣦⣾⣿⣿⣿⣿⣿⡆⠁⠀⢀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⡠⠂⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠠⠔⠚⣿⣿⣿⣿⣿⣦⡄⠀⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⠠⠐⢂⠉⡀⣀⣤⣄⢻⣿⣿⡟⢈⡹⣿⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡀⠄⠂⠈⠀⣶⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠘⣷⡀⠀⡀⠐⠂⠐⢄
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠟⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣾⣷⠯⠀⠤⠤⠄⠈
⠀⠀⠀⠀⠀⠀⣼⣿⡟⠀⠀⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣰⣿⠋⠀⠀⢠⣾⣿⣿⣿⣿⣿⣭⠟⢻⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀
⠀⠀⠀⣀⣶⡟⠁⠀⢾⣶⣿⠟⠉⠈⢻⣿⣿⣿⣦⣜⠀⠛⠛⠿⠁⠀⠀⠀⠀⠀
⠚⠻⠿⠿⡿⠁⠀⢠⣿⣿⠁⠀⣠⠖⠋⠉⠻⣿⣿⣿⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⣿⡿⠃⠠⠊⠁⠀⠀⠀⠀⠈⢿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣠⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⣴⠾⠟⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
