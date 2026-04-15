#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;

    vector<long long> A(N);
    vector<long long> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sorted_A[i] = A[i];
    }

    sort(sorted_A.begin(), sorted_A.end());

    long long median = sorted_A[N / 2];

    for (int i = 0; i < N; ++i) {
        cout << median << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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