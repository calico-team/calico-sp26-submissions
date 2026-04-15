#include <bits/stdc++.h>
using namespace std;

/*
 * Find an array B of n integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * n: the number of columns in the 2 x n grid
 * A: vector of n integers giving the first row of the grid
 */
vector<int> solve(int n, vector<int>& A) {
    // YOUR CODE HERE
    int sum = 0;
    int i;
    vector<int>ans(n);
    sort(A.begin(), A.end());
    for(i = 0; i < 3; ++i){
        ans[i] = A[1];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        vector<int> result = solve(n, A);
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
