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
char mas[5][335];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> kolt;

	rep(hod, kolt) {
		ll P;
		cin >> P >> a >> b;
		if (P == 0) {
			printf("1 1\n");
			printf("X\n");
			continue;
		}

		//++a;
		ll t = P;
		VI b3, b2;
		rept(i, b) {
			b3.pb(t % 3);
			t /= 3;
		}
		reverse(all(b3));
		rept(i, a) {
			b2.pb(t % 2);
			t /= 2;
		}
		reverse(all(b2));

		rept(i, 3) rept(j, 252) mas[i][j] = '.';
		mas[0][0] = 'v';
		mas[1][0] = '>';
		int cj = 1;
		bool fr = 0;
		rept(i, L(b2)) {
			mas[1][cj] = 'S';
			if (b2[i] == 1) {
				if (fr) {
					mas[0][cj] = 'X';
					++cj;
					mas[1][cj] = '>';
					++cj;
				} else fr = 1;
				mas[1][cj] = 'S';
				mas[0][cj] = '^';
				++cj;
			} else {
				mas[0][cj] = 'X';
				++cj;
			}
			mas[1][cj] = '>';
			++cj;
		}
	
		rept(i, L(b3)) {
			mas[1][cj] = 'S';
			if (b3[i] == 1) {
				if (1 || fr) {
					mas[0][cj] = 'X';
					mas[2][cj] = 'X';
					++cj;
					mas[1][cj] = '>';
					++cj;
				} else fr = 1;
				mas[1][cj] = 'S';
				mas[0][cj] = '^';
				mas[2][cj] = 'v';
				++cj;
			} else if (b3[i] == 2) {
				if (fr) {
					mas[0][cj] = 'X';
					mas[2][cj] = 'X';
					++cj;
					mas[1][cj] = '>';
					++cj;
				} else fr = 1;
				mas[1][cj] = 'S';
				mas[0][cj] = '^';
				mas[2][cj] = 'X';
				++cj;
			}
			else {
				mas[0][cj] = 'X';
				mas[2][cj] = 'X';
				++cj;
			}
			mas[1][cj] = '>';
			++cj;
		}

		printf("%d %d\n", 3, cj);
		rept(i, 3) {
			rept(j, cj) {
				printf("%c", mas[i][j]);
			}
			printf("\n");
		}
	}
}
