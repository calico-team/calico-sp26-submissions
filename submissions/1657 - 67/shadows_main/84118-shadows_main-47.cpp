#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N; if (!(cin >> N)) return;
    vector<string> s1(N);
    for (int i = 0; i < N; ++i) {
        cin >> s1[i];
    }
    vector<string> s2(N);
    for (int i = 0; i < N; ++i) cin >> s2[i];
    ll nvol = 0;
    ll xvol = 0;
    for (int i = 0; i < N; ++i) {
        ll c1 = 0; ll c2 = 0;
        for (int j = 0; j < N; ++j) {
            if (s2[i][j] == '#') c2++;
            if (s1[i][j] == '#') c1++;
        }
        if (c1 == 0 || c2 == 0) {
            continue; 
        }
        nvol += max(c1, c2);
        xvol += (c1 * c2);
    }
    cout << xvol << " " << nvol << endl;
}
int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) solve();
}
