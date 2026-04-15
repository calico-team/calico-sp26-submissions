#include <bits/stdc++.h>
using namespace std;
#define v vector

void solve() {
        int N; cin >> N;
        v<v<char>> s1(N, v<char>(N)), s2(N, v<char>(N));
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        cin >> s1[i][j];
                }
        }
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        cin >> s2[i][j];
                }
        }
        int mx = 0, mn = 0;
        for (int i = 0; i < N; i++) {
                int a = 0, b = 0;
                for (int j = 0; j < N; j++) {
                        if (s1[i][j] == '#') a++;
                }
                for (int j = 0; j < N; j++) {
                        if (s2[i][j] == '#') b++;
                }
                mx += a * b;
                mn += max(a, b);
        }
        cout << mx << " " << mn << "\n";
}

int main() {
        int T; cin >> T;
        while (T--) solve();
}