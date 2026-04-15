#include <bits/stdc++.h>
using namespace std;

bool step(vector<int>& b) {
    bool changed = false;
    for (int i = 1; i < b.size()-1; i++) {
        if (b[i] > b[i-1] && b[i] > b[i+1]) {
            b[i] = max(b[i-1], b[i+1]);
            changed = true;
        } else if (b[i] < b[i-1] && b[i] < b[i+1]) {
            b[i] = min(b[i-1], b[i+1]);
            changed = true;
        }
    }
    return changed;
}

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

    bool changed = true;
    changed = step(b);
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
