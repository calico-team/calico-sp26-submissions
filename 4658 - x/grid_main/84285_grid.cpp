#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        vector<long long> S = A;
        sort(S.begin(), S.end());

        for (int i = 0; i < N; i++) {
            cout << S[N / 2] << (i + 1 < N ? ' ' : '\n');
        }
    }
    return 0;
}