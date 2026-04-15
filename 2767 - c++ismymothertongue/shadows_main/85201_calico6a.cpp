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
        long long row_bits = 0;
        long long col_bits = 0;

        for (int j = 0; j < N; ++j) {
            if (s1[i][j] == '#') row_bits++;
            if (s2[i][j] == '#') col_bits++;
        }

        if (row_bits > 0 && col_bits > 0) {
            max_vol += (row_bits * col_bits);
            min_vol += max(row_bits, col_bits);
        } else if (row_bits > 0 || col_bits > 0) {
            
        }
    }

    cout << max_vol << " " << min_vol << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}