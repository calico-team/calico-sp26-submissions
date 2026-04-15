#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    #include <debug.h>
#else
    #define debug(...)
#endif
#define GOOD_LUCK ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()
using namespace std;

constexpr int MAX = 2e+5 + 1, INF = 2e+16, MOD = 1e+9 + 7, K = 31;

void _() {
    string a, b;
    cin >> a >> b;
    int id = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[id]) {
            id++;
        }
        else a[i] = '#';
    }
    cout <<a;
}

signed main() {

    GOOD_LUCK

    int tests=1;
    cin >> tests;
    for (int i=1; i <= tests; i++) {
        _();
        cout << endl;
    }

    return 0;
}
