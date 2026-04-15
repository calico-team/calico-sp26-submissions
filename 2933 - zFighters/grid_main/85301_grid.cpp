#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int>& A) {

    vector<int> B = A;

    for (int i = 1; i < N; i++) {
        B[i] = (B[i] + B[i - 1]) / 2;
    }

    for (int i = N - 2; i >= 0; i--) {
        B[i] = (B[i] + B[i + 1]) / 2;
    }

    return B;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        vector<int> B = solve(N, A);

        for (int i = 0; i < N; i++) {
            cout << B[i] << " ";
        }
        cout << "\n";
    }
}