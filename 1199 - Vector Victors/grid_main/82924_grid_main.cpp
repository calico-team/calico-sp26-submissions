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
vector<int> solve(int N, vector<int>& a) {
    // YOUR CODE HERE
    vector<int> b(N);
    for (int i = 0; i < a.size(); i++) {
        b[i] = a[i];
    }
    if (N == 1 || N == 2) {
        return b;
    } else {
        if (b[1]>b[2] && b[1]>b[0]) {
            b[1] = max(b[2], b[0]);
        } else if (b[1] < b[2] && b[1] < b[0]) {
            b[1] = min(b[2], b[0]);
        }
        return b;
    }
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
