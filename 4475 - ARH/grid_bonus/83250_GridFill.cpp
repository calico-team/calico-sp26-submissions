#include <bits/stdc++.h>
using namespace std;

/*
 * Find an array B of n long longegers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * n: the number of columns in the 2 x n grid
 * A: vector of n long longegers giving the first row of the grid
 */
vector<long long> solve(long long n, vector<long long>& A) {
    // YOUR CODE HERE
    long long sum = 0;
    long long i;
    vector<long long>ans(n);
    sort(A.begin(), A.end());
    long long median = A[n/2];
    if(n % 2 == 0){
        median = (A[n/2]+A[n/2+1])/2;
    }
    for(i = 0; i < n; ++i){
        ans[i] = median;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        vector<long long> A(n);
        for (long long i = 0; i < n; i++) {
            cin >> A[i];
        }
        vector<long long> result = solve(n, A);
        for (long long i = 0; i < n; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
