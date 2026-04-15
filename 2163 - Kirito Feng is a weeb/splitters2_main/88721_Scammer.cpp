// quote from sucram: if you dont think you problem is original
// just swap the input and output and see what happens
// p9 and 10 be like
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll P;
    int A, B;
    cin >> P >> A >> B;

    vector<int> d;
    for (int i = 0; i < A; ++i)d.push_back(2);
    for (int i = 0; i < B; ++i)d.push_back(3);

    int k = A + B;
    vector<int> c(k);
    ll tP = P;
    
    for (int i = k - 1; i >= 0; --i) {
        c[i] = tP % d[i];
        tP /= d[i];
    }

    int N = 5;
    int M = 2 + 2 * k + 3;
    vector<string> g(N, string(M,'.'));

    g[0][0] = 'v';
    g[1][0] = 'v';
    g[2][0] = '>';
    g[2][1] = '>';
    bool f1 = false;
    bool f2 = false;

    for (int i = 0; i < k;++i) {
        int j = 2 + 2 * i;
        g[2][j] = 'S';
        g[2][j + 1] = '>';

        if (d[i] == 3) {
            if (c[i] == 2) {
                g[1][j] = '^';
                f1 = true;
            } else {
                g[1][j] = 'x';
            }
        }

        g[0][j] = f1 ?'>' : '.';
        g[0][j + 1] = f1 ? '>' : '.';
        if (d[i] == 3) {
            if (c[i] >= 1) {
                g[3][j] = 'v';
                f2 = true;
            } else {
                g[3][j] = 'x';
            }
        } else if (d[i] == 2) {
            if (c[i] == 1) {
                g[3][j] = 'v';
                f2 = true;
            } else {
                g[3][j] = 'x';
            }
        }

        g[4][j] = f2 ? '>' : '.';
        g[4][j + 1] = f2 ? '>' : '.';
    }
    int e = 2 + 2 * k;
    g[2][e] = 'x';
    if (f1) {
        g[0][e] = '>';
        g[0][e + 1] = 'v';
        g[1][e + 1] = 'v';
        g[2][e + 1] = 'v';
        g[3][e + 1] = 'v';
    }
    if (f1 || f2) {
        g[4][e] = f2 ? '>' : '.';
        g[4][e + 1] = '>';
        g[4][e + 2] = '>';
    }
    cout << N << " " << M << "\n";
    for (int i = 0; i < N; ++i) {
        cout << g[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

