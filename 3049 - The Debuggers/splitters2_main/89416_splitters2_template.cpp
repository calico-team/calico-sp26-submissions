#include <bits/stdc++.h>
using namespace std;

/*
 * Build a factory with N rows and M columns that produces the target rate.
 *
 * P: the target numerator of the fraction P / (2^A * 3^B)
 * A: the exponent of 2 in the denominator
 * B: the exponent of 3 in the denominator
 */
vector<string> solve(int P, int A, int B) {
    vector<int> D;
    for (int i=0;i<A;i++) D.push_back(2);
    for (int i=0;i<B;i++) D.push_back(3);

    int k= A+B;
    vector<int> R(k);

    for (int i=k-1;i>=0;i--) {
        R[i] = P%D[i];
        P/=D[i];
    }

    int N = 5;
    int M = 2*k+4;
    vector<string> grid(N, string(M, '.'));

    grid[0][0] = 'v';
    grid[1][0] = 'v';
    grid[2][0] = '>';
    grid[2][1] = '>';

    for (int i=0;i<k;i++) {
        int c = 2*i+2;
        grid[2][c] = 'S';
        grid[2][c+1] = '>';
        int rem = R[i];

        if (D[i]==2) {
            if (rem==1) {
                grid[3][c] = 'v';
                grid[4][c] = 'v';
            } else {
                grid[3][c] = 'X';
            }
        }else if (D[i]==3) {
            if (rem==0) {
                grid[1][c] = 'X';
                grid[3][c] = 'X';
            }else if (rem==1) {
                grid[1][c] = '^';
                grid[0][c] = '^';
                grid[3][c] = 'X';
            }else if (rem==2) {
                grid[1][c] = '^';
                grid[0][c] = '^';
                grid[3][c] = 'v';
                grid[4][c] = 'v';
            }
        }
    }

    grid[2][2*k+2] = 'X';
    return grid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        vector<string> factory = solve(P, A, B);
        int N = (int) factory.size();
        int M = (int) factory[0].size();
        cout << N << ' ' << M << '\n';
        for (const string& row : factory) {
            cout << row << '\n';
        }
    }
    return 0;
}
