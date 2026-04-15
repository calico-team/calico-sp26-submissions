#include <bits/stdc++.h>
using namespace std;

int t;
int k, n, m, p, q;

int eea(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}

	int x1, y1;
	int d = eea(b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;

	while (t--) {
		cin >> k >> n >> m >> p >> q;

		int vx, vy;

		int mn = 1000000000;
		int el = 0;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;

			if (i == 0) {
				vx = x;
				vy = y;
				continue;
			}

			// Do x
			int t, s;
			int d = eea(q, n, t, s);

			int dx = (x - vx + n) % n;
			if (dx % d)
				continue;

			int xb = n / d;
			int xa = t * (dx / d) % xb;

			// Do y
			d = eea(p, m, t, s);

			dx = (y - vy + m) % m;
			if (dx % d)
				continue;

			int yb = (m / d);
			int ya = t * (dx / d) % yb;

			// Check for intersections
			d = eea(xb, yb, t, s);
			if ((xa - ya) % d)
				continue;

			t *= (abs(xa - ya) / d) % (yb / d);

			int res = xa + (t)*xb;
			if (res < mn) {
				mn = res;
				el = i;
			}
		}

		cout << el << '\n';
	}

	return 0;
}
