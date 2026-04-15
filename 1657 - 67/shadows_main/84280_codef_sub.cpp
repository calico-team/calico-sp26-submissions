#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<string> s1(N);
    for (int i = 0; i < N; ++i) {
        cin >> s1[i];
    }
    vector<string> s2(N);
    for (int i = 0; i < N; ++i) {
        cin >> s2[i];
    }
    ll mxvol = 0;
    ll minvol = 0;
    for (int i = 0; i < N; ++i) {
        ll c2 = 0; ll c1 = 0;
        for (int j = 0; j < N; ++j) {
            if (s1[i][j] == '#') c1++;
            if (s2[i][j] == '#') c2++;
        }
        if (c1 == 0 || c2 == 0) {
            continue; 
        }
        mxvol += (c1 * c2);
        minvol += max(c1, c2);
    }
    cout << mxvol << " " << minvol << endl;
}
int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) solve();
}
