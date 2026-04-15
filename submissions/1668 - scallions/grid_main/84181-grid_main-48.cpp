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
#define pi 3.1415926535897932384626433832795028841971
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

int a, b, c, d, n, m, k, kolt;
int A[100002];
int B[100002];

int BR[100002];

set<tuple<int, int, int> > q;

inline void add(int pos) {
	if (pos == 0 || pos == n - 1) return;
	
	int s = 0;
	int delta = -1;
	if (B[pos] > B[pos - 1] && B[pos] > B[pos + 1]) {
		int mn = min(B[pos] - B[pos - 1], B[pos] - B[pos + 1]);
		delta = -mn;
		s = mn;
	} else if (B[pos] < B[pos - 1] && B[pos] < B[pos + 1]) {
		int mn = min(B[pos - 1] - B[pos], B[pos + 1] - B[pos]);
		delta = s = mn;
	} else {
		return;
	}

	q.insert(make_tuple(s, delta, pos));
}
inline void rm(int pos) {
	if (pos == 0 || pos == n - 1) return;
	
	int s = 0;
	int delta = -1;
	if (B[pos] > B[pos - 1] && B[pos] > B[pos + 1]) {
		int mn = min(B[pos] - B[pos - 1], B[pos] - B[pos + 1]);
		delta = -mn;
		s = mn;
	} else if (B[pos] < B[pos - 1] && B[pos] < B[pos + 1]) {
		int mn = min(B[pos - 1] - B[pos], B[pos + 1] - B[pos]);
		delta = s = mn;
	} else {
		return;
	}

	auto it = q.find(make_tuple(s, delta, pos));
	if (it != q.end()) {
		q.erase(it);
	}
}


ll BS = -1;
void rec(int v, ll sum) {
	if (sum > BS) return;

	if (v >= n) {
		BS = min(BS, sum);
		if (sum == 27) {
			rept(i, n) {
				cerr << BR[i] << " ";
			}
			cerr << endl;
		}
		return;
	}
	rep(i, 12) {
		BR[v] = i;

		ll ns = sum + abs(A[v] - BR[v]);
		if (v > 0) {
			ns += abs(A[v] - A[v - 1]);
			ns += abs(BR[v] - BR[v - 1]);
		}
		rec(v + 1, ns);
	}
}

inline ll brute() {
	BS = 8LL * INF * INF;
	rec(0, 0);
	return BS;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d", &kolt);
	//kolt = INF;
	rep(hod, kolt) {
		//n = rand() % 4 + 2;
		scanf("%d", &n);
		rept(i, n) {
			//A[i] = rand() % 10 + 1;
			scanf("%d", &A[i]);
		}
		//if (hod != 21) continue;

		rept(i, n) {
			B[i] = A[i];
		}
		q.clear();

		rep(i, n - 1) {
			add(i);
		}

		while (!q.empty()) {
			auto t = *q.rbegin();
			q.erase(--q.end());
			//q.erase(q.begin());

			int pos = get<2>(t);
			rm(pos - 1);
			rm(pos + 1);
			B[pos] += get<1>(t);
			add(pos);
			add(pos - 1);
			add(pos + 1);
		}

		rept(i, n) {
			if (i) printf(" ");
			printf("%d", B[i]);
		}
		printf("\n");
		/*ll sum = 0;
		rept(i, n) {
			sum += abs(A[i] - B[i]);
			if (i) {
				sum += abs(A[i] - A[i - 1]);
				sum += abs(B[i] - B[i - 1]);
			}
		}

		ll br = brute();

		if (sum != br) {
			cerr << "HER " << hod << " " << sum << " " << br << endl;
			cerr << n << endl;
			rept(i, n) {
				cerr << A[i] << " ";
			}
			cerr << endl;
			exit(0);
		}

		cerr << "OK " << hod << " " << sum << endl;*/
	}
}
