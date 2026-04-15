#include <algorithm>
#include <iostream>

using namespace std;

const int Y = 1000;
const int Z = Y * 2;
const int N = Y * Y;

char cc[Y + 1];
int xx[N], yy[N], aa[N], ii[N], kk[Z], ii_[N];

bool check(int n, int x_, int m, int d) {
	for (int y = 0; y < x_; y++)
		kk[y] = 0;
	for (int x = 0, hl = 0, hr = 0; x < x_; x++) {
		for ( ; hl < n && xx[ii[hl]] == x - d - 1; hl++)
			kk[yy[ii[hl]]]--;
		for ( ; hr < n && xx[ii[hr]] == x; hr++)
			kk[yy[ii[hr]]]++;
		for (int s = 0, y = 0; y < x_; y++) {
			s += kk[y];
			if (y > d)
				s -= kk[y - d - 1];
			if (s >= m) {
				int h = 0;
				for (int i = 0; i < n && h < m; i++)
					if (x - d <= xx[i] && xx[i] <= x + d && y - d <= yy[i] && yy[i] <= y + d)
						ii_[h++] = i;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		int x_, y_, m; cin >> x_ >> y_ >> m;
		int n = 0;
		for (int x = 0; x < x_; x++) {
			cin >> cc;
			int k_ = 0;
			for (int y = 0; y < y_; y++)
				if (cc[y] == '#')
					k_++;
			for (int k = 0, y = 0; y < y_; y++)
				if (cc[y] == '-')
					xx[n] = x + y, yy[n] = x - y + y_, aa[n] = min(k, k_ - k), ii[n] = n, n++;
				else
					k++;
		}
		sort(ii, ii + n, [] (int i, int j) { return xx[i] < xx[j]; });
		int lower = -1, upper = x_ + y_;
		while (upper - lower > 1) {
			int d = lower + upper >> 1;
			if (check(n, x_ + y_, m, d))
				upper = d;
			else
				lower = d;
		}
		check(n, x_ + y_, m, upper);
		for (int h = 0; h < m; h++) {
			int i = ii_[h], x = xx[i], y = yy[i];
			cout << (x + y - y_) / 2 << ' ' << (x - y + y_) / 2 << '\n';
		}
	}
	return 0;
}
