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
    vector<int> res(N);
    res[0] = A[0];
    res[N - 1] = A[N - 1];
    for (int i = 1; i < N - 1; i++) {
        if (A[i - 1] == res[i - 1]) {
            int x = A[i - 1], y = A[i], z = A[i + 1];
            if (x <= y && x >= z || x >= y && x <= z) {
                res[i] = x;
            }
            if (y <= x && y >= z || y >= x && y <= z) {
                res[i] = y;
                // cout<<1<<endl;
            }
            if (z <= y && z >= x || z >= y && z <= x) {
                res[i] = z;
            }
        }
        else{
            int x = res[i - 1], y = A[i], z = A[i + 1];
            if (x <= y && x >= z || x >= y && x <= z) {
                res[i] = x;
            }
            if (y <= x && y >= z || y >= x && y <= z) {
                res[i] = y;
                // cout<<1<<endl;
            }
            if (z <= y && z >= x || z >= y && z <= x) {
                res[i] = z;
            }
        }
    }
    return res;
    // 1 4 1 2 3 4
    // 1 3 1 5 1
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
            if (i > 0)
                cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
