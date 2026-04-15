#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N;
    cin >> N;
    vector<string> s1(N), s2(N);
    for (int i = 0; i < N; i++) cin >> s1[i];
    for (int i = 0; i < N; ++i) cin >> s2[i];
    ll mxvol = 0;
    ll mnvol = 0;

    for (int i = 0; i < N; i++) {
        ll c2 = 0
        ll c1 = 0;
        for (char c : s1[i]) {
            if (c == '#') c1++;
        }
        for (char c : s2[i]) {
            if (c == '#') c2++;
        }
        mxvol += c1 * c2;
        mnvol += max(c1, c2);
    }
    cout << mxvol << " " << mnvol << endl;
}

int main() {
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
}
