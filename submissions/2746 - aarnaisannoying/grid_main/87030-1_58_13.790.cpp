#include <bits/stdc++.h>
using namespace std;

/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */
vector<int> solve(int N, vector<int>& A) {
    vector<int> lb(N), rb(N);

    lb[0] = rb[0] = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] < lb[i - 1]) {
            lb[i] = A[i];
            rb[i] = lb[i - 1];
        } else if (A[i] > rb[i - 1]) {
            lb[i] = rb[i - 1];
            rb[i] = A[i];
        } else {
            lb[i] = rb[i] = A[i];
        }
    }

    vector<int> B(N);
    B[N - 1] = lb[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        B[i] = min(rb[i], max(lb[i], B[i + 1]));
    }

    return B;
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
