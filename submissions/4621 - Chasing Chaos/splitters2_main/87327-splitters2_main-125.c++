#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int P, int A, int B) {
    int N = 1, M = 1;
    vector<string> g(1, string(1, 'X'));
    if (P == 0) return g;
    g[0][0] = '>';
    return g;
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