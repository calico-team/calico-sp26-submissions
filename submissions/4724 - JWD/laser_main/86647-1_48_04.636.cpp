#include <iostream>
using namespace std;
int t, x[10005], y[10005];
int main()
{
    cin >> t;
    while (t--) {
        int k, n, m, p, q; cin >> k >> n >> m >> p >> q;
		for (int i = 1; i <= k; i++)
			cin >> x[i] >> y[i];
		int x1 = x[1], y1 = y[1]; bool g = true;
		while (g) {
			x1+=p;
			y1+=q;
//			cout << x1 << ' ' << y1 << '\n';
			if (x1 >= n) x1 -= n;
			if (y1 >= m) y1 -= m;
//			cout << x1 << ' ' << y1 << '\n';
			for (int i = 1; i <= k; i++) {
				if (x1==y[i] && y1 == x[i]) {
					cout << i - 1 << '\n';
					g = false;
				}
			}
		}
    }
    return 0;
}