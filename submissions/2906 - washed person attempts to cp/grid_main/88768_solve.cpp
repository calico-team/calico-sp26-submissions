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
    vector<int> vals = A; // candidate values
    vector<int> bestB(N);
    long long bestCost = LLONG_MAX;

    vector<int> B(N);

    function<void(int)> dfs = [&](int i) {
        if (i == N) {
            long long cost = 0;

            // vertical
            for (int j = 0; j < N; j++) {
                cost += abs(A[j] - B[j]);
            }

            // bottom row
            for (int j = 0; j + 1 < N; j++) {
                cost += abs(B[j] - B[j+1]);
            }

            if (cost < bestCost) {
                bestCost = cost;
                bestB = B;
            }
            return;
        }

        for (int v : vals) {
            B[i] = v;
            dfs(i + 1);
        }
    };

    dfs(0);
    return bestB;
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
