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
        string s,t; cin >> s >> t;
        int n = s.size(), j = 0;
        rep(i,0,n) {
            if (s[i] == t[j]) {
                ++j;
            } else s[i] = '#';
        }
        cout << s << '\n';
    }
    return 0;
}