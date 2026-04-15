#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using ll = long long;
using str = string;
using pi = pair<int,int>;
using vb = vector<bool>;

#define sz(x) int(size(x))
#define lb lower_bound
#define ub upper_bound
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
const int MOD = 1000000000;
const int INF = 1e18;


void solve() {
    int n; cin >> n;
    vector<vector<bool>> l(n, vector<bool> (n));
    vector<vector<bool>> r(n, vector<bool> (n));
    
    
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') {
                l[i][j] = true;
            } else l[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') {
                r[i][j] = true;
            } else r[i][j] = false;
        }
    }
    

    // Min
    vector<int> ct1(n);
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (l[i][j]) c++;
        }
        ct1[i] = c;
    }
    
    int ans1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (r[i][j]) {
                ans1++;
                ct1[i]--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans1 += max(0LL, ct1[i]);
    }

    // Max

    int ans2 = n * n * n;
    vector<int> ct(n);
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (!r[i][j]) {
                ans2 -= n;
                c++;
            }
        }
        ct[i] = c;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!l[i][j]) ans2 -= (n - ct[i]);
        }
    }

    cout << ans2 << " " << ans1 << '\n';
    
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}


