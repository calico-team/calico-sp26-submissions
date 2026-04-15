#include <algorithm>
#include <iostream>

using namespace std;

const int     N = 15;
const int     M = 15;
const int ddi[] = { -1, 1, 0, 0 };
const int ddj[] = { 0, 0, -1, 1 };

char cc[N][M + 1];
int pp[N][M], qq[N][M], pp_[N][M], qq_[N][M];

long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}

void add(int &p, int &q, int p_, int q_) {
	long long q__ = (long long) q * q_, p__ = (long long) p * q_ + (long long) p_ * q, d = gcd(p__, q__);
	p = p__ / d, q = q__ / d;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> cc[i];
		int ansp = 0, ansq = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				pp[i][j] = 0, qq[i][j] = 1;
		pp[0][0] = 1;
		for (int r = 0; r < n * m; r++) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					pp_[i][j] = 0, qq_[i][j] = 1;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					int p = pp[i][j], q = qq[i][j];
					if (!p)
						continue;
					if (cc[i][j] == '<') {
						if (j)
							add(pp_[i][j - 1], qq_[i][j - 1], p, q);
						else
							add(ansp, ansq, p, q);
					} else if (cc[i][j] == '>') {
						if (j + 1 < m)
							add(pp_[i][j + 1], qq_[i][j + 1], p, q);
						else
							add(ansp, ansq, p, q);
					} else if (cc[i][j] == '^') {
						if (i)
							add(pp_[i - 1][j], qq_[i - 1][j], p, q);
						else
							add(ansp, ansq, p, q);
					} else if (cc[i][j] == 'v') {
						if (i + 1 < n)
							add(pp_[i + 1][j], qq_[i + 1][j], p, q);
						else
							add(ansp, ansq, p, q);
					} else if (cc[i][j] == 'S') {
						int k = 0;
						for (int h = 0; h < 4; h++) {
							int i_ = i + ddi[h], j_ = j + ddj[h];
							if (0 <= i_ && i_ < n && 0 <= j_ && j_ < m && cc[i_][j_] != '.' && (cc[i_][j_] == 'X' || cc[i_][j_] != (h == 0 ? 'v' : h == 1 ? '^' : h == 2 ? '>' : '<')))
								k++;
						}
						for (int h = 0; h < 4; h++) {
							int i_ = i + ddi[h], j_ = j + ddj[h];
							if (0 <= i_ && i_ < n && 0 <= j_ && j_ < m && cc[i_][j_] != '.' && (cc[i_][j_] == 'X' || cc[i_][j_] != (h == 0 ? 'v' : h == 1 ? '^' : h == 2 ? '>' : '<')))
								add(pp_[i_][j_], qq_[i_][j_], p, q * k);
						}
					}
				}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					pp[i][j] = pp_[i][j], qq[i][j] = qq_[i][j];
		}
		cout << ansp << ' ' << ansq << '\n';
	}
	return 0;
}
