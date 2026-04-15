#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> B;

    // Find median
    sort(A.begin(), A.end());
    int median = A[N / 2];

    // Construct b array
    for (int i = 0; i < N; i++) {
        B.push_back(median);  // if same values of b then apas m diff 0 hoga and median of a hogi to a s vertical diff b minimum hi hoga.
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