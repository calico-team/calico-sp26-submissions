#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>

using namespace std;
#define int long long

int powMod(int base, int exp, int mod) {
    if (exp == 1) return base;
    else if (exp == 0) return 1;
    else if (base < 2) return base;

    int ans = 1;

    while (exp > 0) {
        if (exp % 2) {
            ans *= base;
        }

        base = base * base % mod;
        exp /= 2;
        ans %= mod;
    }
    return ans;
}

int mex(vector<int> arr) {
    int N = arr.size();
    sort(arr.begin(), arr.end());

    int mex = 0;
    for (int idx = 0; idx < N; idx++) {
        if (arr[idx] == mex) {
            mex += 1;
        }
    }

    return mex;
}

void solve() {
    int m, n; cin >> m >> n;
    vector<vector<int> > ans(m, vector<int> (n, -1));

    for (int i = 0; i < n; i++) ans[0][i] = (i + 3) % 5;
    for (int i = 0; i < n; i++) ans[1][i] = i % 5;

    for (int i = 2; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> m;
            if (j == 0) {
                m.push_back(ans[i - 1][0]); m.push_back(ans[i - 1][1]); m.push_back(ans[i - 2][0]);
            } else if (j == n - 1) {
                m.push_back(ans[i - 1][n - 1]); m.push_back(ans[i - 1][n - 2]); m.push_back(ans[i - 2][n - 1]);
            } else {
                m.push_back(ans[i - 1][j - 1]); m.push_back(ans[i - 1][j]); m.push_back(ans[i - 1][j + 1]); m.push_back(ans[i - 2][j]);
            }
            
            ans[i][j] = mex(m);
        }
    }


    for (auto a: ans) {
        for (int b: a) {
            cout << b << ' ';
        }
        cout << '\n';
    }
}


signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}