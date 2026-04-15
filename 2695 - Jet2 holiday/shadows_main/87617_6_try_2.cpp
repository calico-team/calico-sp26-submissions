#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> s1(N), s2(N);
        for (int i=0; i<N; i++) cin >> s1[i];
        for (int i=0; i<N; i++) cin >> s2[i];

        ll max_vol = 0;
        ll min_vol = 0;

        for (int z = 0; z < N; z++) {
            // 统计这一层：S1 有多少 #
            int c1 = count(s1[z].begin(), s1[z].end(), '#');
            // 统计这一层：S2 有多少 #
            int c2 = count(s2[z].begin(), s2[z].end(), '#');

            max_vol += 1LL * c1 * c2;
            min_vol += max(c1, c2); 
        }

        cout << max_vol << " " << min_vol << "\n";
    }
    return 0;
}