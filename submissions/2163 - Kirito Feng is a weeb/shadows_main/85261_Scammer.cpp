#include <bits/stdc++.h>
using namespace std;
typedef ll ll;

void solve() {
    int n;
    cin >> n;


    vector<string> s1(n);
    for (int i = 0; i < n; ++i) {
        cin >> s1[i];
    }
    vector<string> s2(n);
    for (int i = 0; i < n; ++i) {
        cin >> s2[i];
    }
    ll mx = 0;
    ll mn = 0;
    for (int i = 0; i < n; ++i) {
        ll r1 = 0,r2 = 0;
        for (char c : s1[i]) {
            if (c == '#') r1++;
        }
        for (char c :s2[i]) {
            if (c == '#') r2++;
        }
        mx += r1 * r2;
        mn += max(r1, r2);
    }

    cout << mx << " "<< mn << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}