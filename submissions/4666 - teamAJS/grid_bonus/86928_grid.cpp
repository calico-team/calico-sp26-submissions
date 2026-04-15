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
 
int medofthree(int a, int b, int c){
    if(a<=b && a<=c){
        return min(b,c);
    }else if(b <= c){
        return min(a,c);
    }else{
        return min (a,b);
    }
} 

vector<int> solve(int N, vector<int>& A) {
    if(N==1 || N==2){
        return A;
    }
    vector<int> B = A;
    for (int i = 1; i < N - 1; i++){
        B[i] = medofthree(A[i-1], A[i], A[i+1]);
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
