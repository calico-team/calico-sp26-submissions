#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */

vector<ll BOOM(int N, vector<ll>& A) {
    vector<ll> b(N);
    b[0] = A[0];

    for (int i = 1; i < N; i++) {
       if (i < N - 1) {
            vector<ll> eq = {b[i-1], A[i], A[i+1]};
            sort(eq.begin(), eq.end());
            b[i] = eq[1]; 
        } else {
            b[i] = A[i]; 
        }
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
        vector<ll> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }


        vector<ll> result = BOOM(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}