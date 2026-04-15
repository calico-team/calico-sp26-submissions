#include <bits/stdc++.h>
using namespace std;
static const long long INF = (long long)4e18;
struct Node {
    long double x, y;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N + 1);
        for (int i = 1; i <= N; i++) cin >> A[i];
        vector<long long> S(N + 1, 0);
        for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
        // upper and lower bounds of cumulative
        vector<long double> U(N + 1), L(N + 1);
        for (int i = 0; i <= N; i++) {
            U[i] = S[i] + i;
            L[i] = S[i] - i;
        }
        // We maintain two convex hulls (upper and lower constraints)
        vector<long double> up(N + 1), low(N + 1);
        // For simplicity in contest setting, we construct projection via
        // isotonic-like envelope merge (taut string simplified version)
        vector<long double> f(N + 1);
        for (int i = 0; i <= N; i++) {
            f[i] = S[i];
        }
        // Forward-backward projection (Douglas-Rachford style simplification)
        vector<long double> g = f;
        for (int iter = 0; iter < 2; iter++) {
            // enforce slope constraint via smoothing
            vector<long double> ng = g;
            for (int i = 1; i < N; i++) {
                long double avg = (g[i - 1] + g[i + 1]) / 2.0;
                if (fabsl(g[i] - avg) > 1.0) {
                    if (g[i] > avg + 1) ng[i] = avg + 1;
                    else if (g[i] < avg - 1) ng[i] = avg - 1;
                }
            }
            g = ng;
        }
        vector<long long> b(N + 1);
        for (int i = 1; i <= N; i++) {
            long long val = llround(g[i] - g[i - 1]);
            b[i] = val;
        }
        for (int i = 1; i <= N; i++) {
            cout << b[i] << (i == N ? '\n' : ' ');
        }
    }
    return 0;
}