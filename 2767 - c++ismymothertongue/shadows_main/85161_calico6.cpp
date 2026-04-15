#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<string> s1(N), s2(N);
    for (int i = 0; i < N; ++i) cin >> s1[i];
    for (int i = 0; i < N; ++i) cin >> s2[i];

    long long max_vol = 0;
    long long min_vol = 0;

    for (int i = 0; i < N; ++i) {
        long long c1 = 0, c2 = 0;
        for (char c : s1[i]) if (c == '#') c1++;
        for (char c : s2[i]) if (c == '#') c2++;

        if (c1 > 0 && c2 > 0) {
            max_vol += (c1 * c2);
            min_vol += max(c1, c2);
        }
    }

    cout << max_vol << " " << min_vol << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}