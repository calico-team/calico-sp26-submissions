/*
*/

#include <bits/stdc++.h>
#define int long long
#define setmax(a, b) a = std::max(a,b);
#define setmin(a, b) a = std::min(a,b);
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = a; i >= (b); --i)
const int INF = std::numeric_limits<int>::max()/20;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<string> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        vector<int> cts(n);
        rep(i,0,n) {
            int ct = 0;
            rep(j,0,n) {
                if (a[i][j] == '#') ++ct;
            }
            cts[i] = ct;
        }
        int mx = 0, mn = 0;
        rep(i,0,n) rep(j,0,n) {
            if (b[i][j] == '#') mx += cts[i];
        }


        rep(i,0,n){
            int j = 0, k = 0;
            while (j < n && k < n) {
                if (a[i][j] == '#' && b[i][k] == '#') {
                    ++mn;
                    ++j,++k;
                } else if (a[i][j] != '#') ++j;
                else if (b[i][k] != '#') ++k;
            }
            while (j < n) {
                if (a[i][j++] == '#') ++mn;
            }
            while (k < n) {
                if (b[i][k++] == '#') ++mn;
            }
        }
        cout << mx << " " << mn << '\n';
    }   

    return 0;
}