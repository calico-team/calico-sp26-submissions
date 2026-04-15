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

int findMiddle(int a, int b, int c) {
    if (a > b) {
        if (c < b) {
            return b;
        }
        if (c > a) {
            return a;
        }
        return c;
    }
    if (c < a) {
        return a;
    }
    if (c > b) {
        return b;
    }
    return c;
}

vector<int> solve(int N, vector<int>& A) {
    vector<int> B(A);
    if (N <= 2) {
        return B;
    }
    bool changed = true;
    while (changed) {
        changed = false;
        if (A[0] > B[0] && B[1] > B[0]) {
            B[0] = A[0] > B[1] ? B[1] : A[0];
            changed = true;
        }
        if (A[0] < B[0] && B[1] < B[0]) {
            B[0] = A[0] < B[1] ? B[1] : A[0];
            changed = true;
        }
        if (A[N - 1] > B[N - 1] && B[N - 2] > B[N - 1]) {
            B[N - 1] = A[N - 1] > B[N - 2] ? B[N - 2] : A[N - 1];
            changed = true;
        }
        if (A[N - 1] < B[N - 1] && B[N - 2] < B[N - 1]) {
            B[N - 1] = A[N - 1] < B[N - 2] ? B[N - 2] : A[N - 1];
            changed = true;
        }

        for (int i = 1; i < N - 1; i++) {
            int up = (A[i] > B[i] ? 1 : 0) + (B[i + 1] > B[i] ? 1 : 0) + (B[i - 1] > B[i] ? 1 : 0);
            int down = (A[i] < B[i] ? 1 : 0) + (B[i + 1] < B[i] ? 1 : 0) + (B[i - 1] < B[i] ? 1 : 0);
            if (up >= 2 || down >= 2) {
                B[i] = findMiddle(A[i], B[i + 1], B[i - 1]);
                changed = true;
            }
        }
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