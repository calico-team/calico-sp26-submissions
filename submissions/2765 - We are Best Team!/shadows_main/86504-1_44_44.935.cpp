#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;


        vector<string> s1(N), s2(N);
        for (int i = 0; i < N; i++) cin >> s1[i];
        for (int i = 0; i < N; i++) cin >> s2[i];

        long long mx = 0, mn = 0;

        for (int i = 0; i < N; i++) {
            int a = 0, b = 0;
            for (int j = 0; j < N; j++) {
                if (s1[i][j] == '#') {
                    a++;
                }
                if (s2[i][j] == '#') {
                    b++;
                }
            }
            mx += 1LL * a * b;
            mn += max(a, b);
        }

        cout << mx << ' ' << mn << '\n';
    }

    return 0;
}