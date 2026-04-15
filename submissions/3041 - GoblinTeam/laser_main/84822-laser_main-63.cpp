/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<int> xs(k), ys(k);
        for (int i = 0; i < k; ++i) {
            cin >> xs[i] >> ys[i];
        }

        int sx = xs[0], sy = ys[0];
        long long mt = 1e18;
        int ans = -1;

        for (int i = 1; i < k; ++i) {
            int tx = xs[i], ty = ys[i];

            int dx = (tx - sx + n) % n;
            int dy = (ty - sy + m) % m;
            int g1 = __gcd(q, n);
            if (dx % g1 != 0) continue;

            long long t1 = -1;
            for (int step = 1; step <= n;step++) {
                if ((1LL * step * q) % n == dx) {
                    t1 = step;
                    break;
                }
            }
            long long p1 = n / g1;

            int g2 = __gcd(p, m);
            if (dy % g2 != 0) continue;

            long long t2 = -1;
            for (int step = 1; step <= m; ++step) {
                if ((1LL * step * p) % m == dy) {
                    t2 = step;
                    break;
                }
            }
            long long p2 = m / g2;
            long long ft = -1;
            if (p1 < p2) {
                for (long long t = t1; t <= min(mt, t1 + p1 * p2); t += p1) {
                    if (t >= t2 && (t - t2) % p2 == 0) {
                        ft = t;
                        break;
                    }
                }
            } else {
                for (long long t = t2; t <= min(mt, t2 + p1 * p2); t += p2) {
                    if (t >= t1 && (t - t1) % p1 == 0) {
                        ft = t;
                        break;
                    }
                }
            }

            if (ft != -1 && ft < mt) {
                mt = ft;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}