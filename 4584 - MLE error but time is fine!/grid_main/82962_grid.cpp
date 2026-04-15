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
    vector<int> L(N),R(N);
    L[0]=R[0]=A[0];

    for(int i=1;i<N;i++){
        int x=A[i];
        if(x<L[i-1]){
            L[i]=x;
            R[i]=L[i-1];
        }else if(x>R[i-1]){
            L[i]=R[i-1];
            R[i]=x;
        }else{
            L[i]=R[i]=x;
        }
    }

    vector<int> B(N);
    int cur=L[N-1];
    B[N-1]=cur;
    for(int i=N-2;i>=0;i--){
        if(cur<L[i])cur=L[i];
        else if(cur>R[i])cur=R[i];
        B[i]=cur;
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
