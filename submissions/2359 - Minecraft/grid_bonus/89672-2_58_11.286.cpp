#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cout << A[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
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