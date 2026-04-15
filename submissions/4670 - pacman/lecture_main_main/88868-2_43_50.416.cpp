/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

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

int _n, _m, _k;
vector<vector<char>> g;

inline void systemd() {
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
    vector < array < int , 2 > > v;
    for (int i = 0; i < mx - 1; ++i) {
        for (int j = 0; j < mx - 1; ++j) {
            if (sum(P, i + 1, j + 1, i + res + 1, j + res + 1) >= _k) {
                v.push_back({i, j});
            }
        }
    }

    for(auto [i, j] : v){
      vector<node> cand;
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
          long long cur = 0;
          for (int k = 0; k < _k; ++k) {
              cur += cand[k].aura;
          }
          if (cur < anss) {
              anss = cur;
              ans.assign(cand.begin(), cand.begin() + _k);
          }
      }
    }

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
таАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтвАтгАтгАтаАтаАтаАтвАтг┤тг╛таАтаАтаАтбАтвАтаАтаАтаАтаА
таАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтв╕тг┐тг┐тг┐тгжтг╛тг┐тг┐тг┐тг┐тг┐тбЖтаБтаАтвАтаАтаАтаАтаА
таАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАта╣тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тб┐таБтаАтбатаВтаАтаАтаАтаА
таАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтгАтаатаФтаЪтг┐тг┐тг┐тг┐тг┐тгжтбДтаАтаБтаАтаАтаАтаАтаАтаА
таАтаАтаАтаАтаАтаАтвАтаатаРтвВтаЙтбАтгАтгдтгДтв╗тг┐тг┐тбЯтвИтб╣тг┐тбАтаАтаАтаАтаАтаАтаАтаА
таАтаАтбАтаДтаВтаИтаАтг╢тгдтг╛тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐таШтг╖тбАтаАтбАтаРтаВтаРтвД
таАтаАтаАтаАтаАтаАтаАтг┐тг┐таЯта┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тгзтгАтг╛тг╖таптаАтадтадтаДтаИ
таАтаАтаАтаАтаАтаАтг╝тг┐тбЯтаАтаАтг╣тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг┐тг╖тгДтбАтаАтаАтаАтаА
таАтаАтаАтаАтаАтг░тг┐таЛтаАтаАтватг╛тг┐тг┐тг┐тг┐тг┐тгнтаЯтв╗тг┐тг┐тг┐тг┐тб┐таБтаАтаАтаАтаА
таАтаАтаАтгАтг╢тбЯтаБтаАтв╛тг╢тг┐таЯтаЙтаИтв╗тг┐тг┐тг┐тгжтгЬтаАтаЫтаЫта┐таБтаАтаАтаАтаАтаА
таЪта╗та┐та┐тб┐таБтаАтватг┐тг┐таБтаАтгатаЦтаЛтаЙта╗тг┐тг┐тг┐тг╢тбАтаАтаАтаАтаАтаАтаАтаАтаА
таАтаАтаАтаАтаАтаАтг░тг┐тб┐таГтаатаКтаБтаАтаАтаАтаАтаИтв┐тг┐тг┐таЯтаАтаАтаАтаАтаАтаАтаАтаА
таАтаАтаАтаАтвАтг┤тб┐таЛтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаШтаБтаАтаАтаАтаАтаАтаАтаАтаАтаА
таАтаАтаАтгатг╛таПтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаА
твАтг┤та╛таЯтаЫтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаАтаА
*/