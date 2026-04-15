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
static inline int CI(int x, int L, int R){
    if (x<L) return L;
    if (x>R) return R;
    return x;
}
vector<int> solve(int N, vector<int>& A) {
    int M = (int)A.size();

    vector<int> L(N), R(N);
    L[0] = R[0] = A[0];

    for (int i = 1; i < M; i++){
        int a = A[i];
        if (a < L[i-1]){
            L[i] = a;
            R[i] = L[i-1];
        }else if (a > R[i-1]){
            L[i] = R[i-1];
            R[i] = a;
        }else{
            L[i]= R[i]= a;
        }
    }
    vector<int> b(N);
    b[N-1] = L[N-1];
    for (int i= M-2; i >= 0 ; i--){
        b[i] =CI(b[i+1],L[i], R[i]);
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
