#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    priority_queue<long long> pq;
    vector<long long> b(N);

    for (int i = 0; i < N; ++i) {
        pq.push(A[i]);
        pq.push(A[i]);
        pq.pop();
        b[i] = pq.top();
    }

    for (int i = N - 2; i >= 0; --i) {
        if (b[i] > b[i + 1]) b[i] = b[i + 1];
    }

    for (int i = 0; i < N; ++i) {
        cout << b[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) solve();
    return 0;
}