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
    vector<int> c(N);
    for (int i = 0; i < N; i++){
        c[i] = A[i];
    }
    map<int, int> cnt;
    for(int i = 0; i < N; i++){
        cnt[A[i]]++;
    }
    int mx = 0, mxv = 0;
    for(int i = 0; i < N; i++){
        if(cnt[A[i]] > mx){
            mx = cnt[A[i]];
            mxv = A[i];
        }
    }
    vector<int> e(N, mxv);
    int s1 = 0, s2 = 0;
    for(int i = 0; i < N; i++){
        s1 += abs(A[i] - e[i]);
        s2 += abs(A[i] - c[i]);
    }
    for(int i = 1; i < N; i++){
        s1 += abs(A[i] - A[i - 1]);
        s2 += abs(A[i] - A[i - 1]);
        s1 += abs(e[i] - e[i - 1]);
        s2 += abs(c[i] - c[i - 1]);
    }
    if(s1 < s2){
        return e;
    } 
    return c;
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
