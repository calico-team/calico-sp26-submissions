#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int>& A) {
    vector<int> l(N), r(N), b(N);
    l[0] = r[0] = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] < l[i - 1]) {
            l[i] = A[i];
            r[i] = l[i - 1];
        } else if (A[i] > r[i - 1]) {
            l[i] = r[i - 1];
            r[i] = A[i];
        } else {
            l[i] = r[i] = A[i];
        }
    }
    b[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (b[i + 1] < l[i]) b[i] = l[i];
        else if (b[i + 1] > r[i]) b[i] = r[i];
        else b[i] = b[i + 1];
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}