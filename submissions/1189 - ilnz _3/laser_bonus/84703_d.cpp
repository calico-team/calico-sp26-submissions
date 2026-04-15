#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#ifdef LOCAL
#define err cerr
#else
#define err if (0) cerr
#endif

int exp (int a, int b, int mod) {
	if (!b) return 1;
	int r = exp(a, b>>1, mod);
	if (b&1) return r*r%mod*a%mod;
	return r*r%mod;
}

int inv (int a, int mod) { err << a << " " << mod << "\n"; return exp(a%mod, mod-2, mod);}

int calc (int a, int n, int b, int m) {
	int d = gcd(n, m);
	if ((b-a) % d != 0) return -1; 
	int n1 = n/d, m1 = m/d;
	if (m1 == 1) return a;
	int k = ((b-a)/d%m1+m1)%m1;
	k = (k*inv(n1%m1, m1))%m1;
	return a+k*n;
}

void solve() {
	int k, n, m, p, q;
	cin >> k >> n >> m >> p >> q;
	swap(p, q);
	p = p%n;
	q = q%m;
	vector<pair<int, int>> vt(k);
	for (pair<int, int> &i: vt) cin >> i.f >> i.s;
	for (int i = 1; i < k; i++) vt[i].f = ((vt[i].f-vt[0].f)%n+n)%n;
	for (int i = 1; i < k; i++) vt[i].s = ((vt[i].s-vt[0].s)%m+m)%m;
	int a = gcd(p, n), b = gcd(q, m);
	pair<int, int> best = {INT_MAX, 0};
	for (int i = 1; i < k; i++) {
		if (vt[i].f%a == 0 && vt[i].s%b == 0) {
			int ta = (inv(p/a, n/a)*(vt[i].f/a))%(n/a);
			int tb = (inv(q/b, m/b)*(vt[i].s/b))%(m/b);
			int ret = calc(ta, n/a, tb, m/b);
			if (~ret) best = min(best, {ret, i});
		}
	}
	cout << best.s << "\n";
}

signed main (signed argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}

/*
 *
 *  ┏┓   ┏┓+ +
 * ┏┛┻━━━┛┻┓ + +
 * ┃   ━   ┃ ++ + + +
 * ████━████+
 * ◥██◤ ◥██◤ +
 * ┃   ┻   ┃ 
 * ┗━┓   ┏━┛  + + 
 *   ┃   ┃ + + + +Code is far away from  
 *   ┃   ┃ + bug with the llama protecting
 *   ┃    ┗━━━┓ 神兽保佑,代码无bug 
 *   ┃        ┣┓
 *   ┃        ┏┛
 *   ┗┓┓┏━┳┓┏┛ + + + +
 *    ┃┫┫ ┃┫┫
 *    ┗┻┛ ┗┻┛+ + + +
 */

//thanks cindy

