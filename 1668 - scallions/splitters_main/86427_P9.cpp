#if defined(__GNUC__) && defined(__has_include) && __has_include(<bits/allocator.h>)
#include <bits/allocator.h>
#endif

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <chrono>
using namespace std;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

inline ll gcd(ll a, ll b) {
	for (; b; swap(a, b)) a %= b;
	return a;
}

struct Frac {
	ll a, b;
	Frac(ll _a, ll _b): a(_a), b(_b) {}

	inline void norm() {
		ll g = gcd(a, b);
		a /= g;
		b /= g;
	}
};

inline Frac operator +(const Frac& a, const Frac &b) {
	Frac res(a.a * b.b + a.b * b.a, a.b * b.b);
	res.norm();
	return res;
}



int a, b, c, d, n, m, k, kolt;
char mas[21][21];
bool used[21][21];
vector<pii> sm[21][21];
map<pii, int> ind;

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};
const char* dd = ">v<^";
inline int gd(char ch) {
	if (ch == '>') return 0;
	else if (ch == 'v') return 1;
	else if (ch == '<') return 2;
	else if (ch == '^') return 3;
	else return 4;
}

void dfs(int ci, int cj, vector<pii>& ts, int pi, int pj) {
	if (used[ci][cj]) return;
	used[ci][cj] = 1;
	if (ci == n && cj == m) {
		ts.emplace_back(n, m);
		return;
	}

	if (mas[ci][cj] == 'X') {
		ts.emplace_back(ci, cj);
		return;
	}

	if (mas[ci][cj] == 'S') {
		rept(i, 4) {
			int ni = ci + di[i];
			int nj = cj + dj[i];

			if (ni == pi && nj == pj) continue;
			if (ni < 0 || ni >= n || nj < 0 || nj > m) {
				sm[ci][cj].pb(mp(n, m));
				dfs(n, m, ts, ci, cj);
			}
			if (mas[ni][nj] == '.') continue;
			sm[ci][cj].pb(mp(ni, nj));
			dfs(ni, nj, ts, ci, cj);
		}
		ts.emplace_back(ci, cj);
		return;
	}

	int g = gd(mas[ci][cj]);
	if (g >= 4) return;
	int ni = ci + di[g];
	int nj = cj + dj[g];
	if (ni >= n || ni < 0 || nj >= m || nj < 0) {
		dfs(n, m, ts, ci, cj);
		sm[ci][cj].pb(mp(n, m));
		ts.emplace_back(ci, cj);
		return;
	}
	dfs(ni, nj, ts, ci, cj);
	sm[ci][cj].pb(mp(ni, nj));
	ts.emplace_back(ci, cj);
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	scanf("%d", &kolt);
	rep(hod, kolt) {
		scanf("%d%d", &n, &m);
		rept(i, n) {
			scanf("%s", mas[i]);
		}
		rept(i, n) {
			rept(j, n) {
				sm[i][j].clear();
				used[i][j] = 0;
			}
		}

		vector<pii> ts;
		dfs(0, 0, ts, -1, -1);
		reverse(all(ts));
		ind.clear();
		rept(i, L(ts)) {
			ind[ts[i]] = i;
		}
		if (ind.count(mp(n, m)) == 0) {
			cout << 0 << " " << 1 << "\n";
			continue;
		}
		vector<Frac> mem(L(ts), Frac(0, 1));
		mem[0] = Frac(1, 1);

		rept(i, L(ts)) {
			pii t = ts[i];
			if (t.x == n && t.y == m) break;

			int ci = t.x;
			int cj = t.y;
			int len = L(sm[ci][cj]);

			Frac add = mem[i];
			if (len > 1) {
				add.b *= len;
				add.norm();
			}
			rept(j, len) {
				int ni = sm[ci][cj][j].x;
				int nj = sm[ci][cj][j].y;
				int pos = ind.at(mp(ni, nj));
				mem[pos] = mem[pos] + add; 
			}
		}

		int pos = ind[mp(n, m)];
		auto ans = mem[pos];
		cout << ans.a << " " << ans.b << "\n";
	}
}
