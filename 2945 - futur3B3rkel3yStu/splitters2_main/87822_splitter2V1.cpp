#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int P, int A, int B) {
    vector<int> div;
    for (int i = 0; i < A; ++i) div.push_back(2);
    for (int i = 0; i < B; ++i) div.push_back(3);

    vector<int> tak;
    long long cur = P;
    for (int i = (int)div.size() - 1; i >= 0; --i) {
        tak.push_back(cur % div[i]);
        cur /= div[i];
    }
    reverse(tak.begin(), tak.end());

    int m = 2 * (A + B) + 2;
    vector<string> ret(3, string(m, '.'));

    ret[0][0] = 'v';
    ret[1][0] = '>';

    for (int i = 0; i < A + B; ++i) {
        int c = 2 * i + 1;
        ret[1][c] = 'S';
        ret[1][c + 1] = '>';

        if (div[i] == 2) {
            if (tak[i] == 1) {
                ret[2][c] = 'v';
            } else {
                ret[2][c] = 'x';
            }
        } else {
            if (tak[i] == 0) {
                ret[0][c] = 'x';
                ret[2][c] = 'x';
            } else if (tak[i] == 1) {
                ret[0][c] = '^';
                ret[2][c] = 'x';
            } else {
                ret[0][c] = '^';
                ret[2][c] = 'v';
            }
        }
    }

    ret[1][m - 1] = 'x';

    return ret;
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