#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll score = 1e18;
int A[5], b[5], c[5];

void rek(int level) {
    if (level == n) {
        ll new_score = (ll) abs(A[n - 1] - c[n - 1]);
        for (int j = 0; j < n - 1; j++) {
            new_score += (ll) abs(A[j] - A[j + 1]);
            new_score += (ll) abs(c[j] - c[j + 1]);
            new_score += (ll) abs(A[j] - c[j]);
        }
        if (new_score < score) {
            for (int j = 0; j < n; j++) {
                b[j] = c[j];
            }
            score = new_score;
        }
    } else {
        for (int i = 0; i < n; i++) {
            c[level] = A[i];
            rek(level + 1);
        }
    }
}

void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    score = 1e18;
    rek(0);

    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n" [i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
