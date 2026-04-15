#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    long long minv = 0, maxv = 0;

    vector<vector<char>> a(n, vector<char>(n)), b(n, vector<char>(n));

    long long a_chars = 0, b_chars = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            a[i][j] = s[j];
            if (s[j] == '#') a_chars++;
        }
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            b[i][j] = s[j];
            if (s[j] == '#') b_chars++;
        }
    }

    vector<int> hashtags_in_a_at_row(n);
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) if (a[i][j] == '#') temp++;
        hashtags_in_a_at_row[i] = temp;
    }

    // max volume
    maxv = a_chars * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] == '.') {
                // subtract number of # in row i of a
                maxv -= hashtags_in_a_at_row[i];
            }
        }
    }

    // min volume
    for (int i = 0; i < n; i++) {
        int chars_a = 0, chars_b = 0;
        for (char c : a[i]) if (c == '#') chars_a++;
        for (char c : b[i]) if (c == '#') chars_b++;
        minv += max(chars_a, chars_b);
    }

    cout << maxv << " " << minv << endl;
}

int main() {
	int t; cin >> t;
    while (t--) solve();
}
