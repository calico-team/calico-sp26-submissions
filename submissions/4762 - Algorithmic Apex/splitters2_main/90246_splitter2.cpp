#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvii = vector<vii>;
using vvi = vector<vi>;

#define rep(i, a, b)  for (int i = int(a); i < int(b); i++)
#define repr(i, a, b) for (int i = int(a); i > int(b); i--)
#define cinn(a, n)    rep(_, 0, n) cin >> a[_];
#define all(x)        begin(x), end(x)
#define each(x, l)    for (auto x : l)

const int MOD = 1e9 + 7;

void solve() {
    ll gp, ga, gb;
    cin >> gp >> ga >> gb;

    int num_2 = ga;
    int num_3 = gb;

    vector<vector<bool>> used(num_3 + 1, vector<bool>(num_2 + 1, false));

    bool last_23 = false;

    auto f = [&](auto self, ll p, ll a, ll b) -> void {
        // cout << "called " << p << " " << a << " " << b << endl;
        while (p % 2 == 0 && a > 0) {
            p /= 2;
            a--;
        }

        if (p == 1) {
            // use current setup
            used[b][a] = true;
            return;
        }

        // start dividing by 3
        if (a == 0) {
            while (p % 3 == 0 && b > 0) {
                p /= 3;
                b--;
            }

            if (b == 0) {
                // cannot do more
                used[b][a] = true;
                return;
            }

            // have to make last one channel as well
            if (p == 2) {
                last_23 = true;
                return;
            }

            // odd and a not zero
            self(self, p / 3, a, b - 1);
            self(self, p % 3, a, b);
            return;
        }

        // odd and a not zero
        self(self, p / 2, a - 1, b);
        self(self, 1, a, b);
    };

    f(f, gp, ga, gb);

    // for (auto l : used) {
    //     for (auto e : l) {
    //         cout << int(e) << " ";
    //     }
    //     cout << endl;
    // }

    string nothing = "...";
    vector<string> s2 = { ">>>", ".X.", ">S>", "..." };
    vector<string> s3 = { ".v.", ".v.", "XS>", ".v." };
    vector<string> s3_special = { ".v.", ".v.", ".>>", "..." };
    string s2_use_str = ".^.";
    string s3_use_str = "<S>";

    string base_str;
    int width = 0, height = 0;

    // if 0,0 is used then 1 = p / 2^a * 3^b
    if (used[0][0]) {
        base_str += ">^.";
    } else {
        base_str += ">v.";
    }
    rep(i, 0, num_2 + 1) {
        base_str += nothing;
    }
    base_str += "^";
    base_str += "\n";
    height++;

    for (int i = 0; i < num_3 + 1; i++) {
        rep(line, 0, 4) {
            string curr_line = "";

            if (i != 0) {
                if (line == 2 && used[i][0]) {
                    curr_line += s3_use_str;
                } else {
                    curr_line += s3[line];
                }
            } else {
                // check if any are used
                bool any_in =
                  find(used[0].begin(), used[0].end(), true) != used[0].end();

                if (any_in) {
                    // row being used, make special pattern
                    curr_line += s3_special[line];
                } else {
                    // not using first line
                    continue;
                }
            }

            for (int j = 1; j < num_2 + 1; j++) {
                if (line == 1 && used[i][j]) {
                    curr_line += s2_use_str;
                } else {
                    curr_line += s2[line];
                }
            }

            if (line == 0) {
                curr_line += ">>>";
            } else {
                curr_line += "X..";
            }

            curr_line += "^";
            width = max(width, int(curr_line.size()));

            // cout << curr_line.size() << endl;
            base_str += curr_line;
            base_str += "\n";
            height++;
        }
    }

    if (!last_23) {
        rep(i, 0, num_2 + 2) {
            base_str += "XXX";
        }
        base_str += ".";
        base_str += "\n";
        height++;
    }

    cout << height << " " << width << endl;
    cout << base_str;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) solve();
}
