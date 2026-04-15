#include <bits/stdc++.h>
using namespace std;

string solve(int N, vector<string> S1, vector<string> S2) {
    int maxv = 0;
    int minv = 0;
    for (int i = 0; i < N; i++) {
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < N; i++) {
            if (S1[i][i] == '#') s1++;
            if (S2[i][i] == '#') s2++;
        }
        maxv += s1 * s2;
        minv += max(s1, s2);
    }
    return to_string(maxv) + " " + to_string(minv);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        vector<string> S1(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        vector<string> S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }
        cout << solve(N, S1, S2) << '\n';
    }
}
