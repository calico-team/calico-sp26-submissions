#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> s1(N), s2(N);
        for (int i = 0; i < N; ++i) cin >> s1[i];
        for (int i = 0; i < N; ++i) cin >> s2[i];

        vector<int> cnt1(N), cnt2(N);
        for (int i = 0; i < N; ++i) {
            cnt1[i] = count(s1[i].begin(), s1[i].end(), '#');
            cnt2[i] = count(s2[i].begin(), s2[i].end(), '#');
        }

        long long min_vol = 0, max_vol = 0;
        for (int i = 0; i < N; ++i) {
            min_vol += max(cnt1[i], cnt2[i]);
            max_vol += 1LL * cnt1[i] * cnt2[i];
        }

        cout << max_vol << " " << min_vol << "\n";
    }
    return 0;
}
