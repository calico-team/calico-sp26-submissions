#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
6
2
##
##
##
##
3
#.#
#.#
###
#.#
#.#
###
3
#.#
#.#
###
###
#.#
#.#
3
#.#
#.#
###
###
##.
##.
4
#...
..##
##.#
##..
..##
..##
##.#
#.##
2
..
..
..
..

*/


int main() {
	int t;
	cin >> t;
	for (int ab = 0; ab < t; ab++) {
		int n;
		cin >> n;
		vector<vector<int>> lshadow(n, vector<int>(n));
		vector<vector<int>> rshadow(n, vector<int>(n));
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				char a;
				cin >> a;
				if (a == '#') {
					lshadow[x][y] = 1;
				}
				else lshadow[x][y] = 0;
			}
		}
		int maxans = 0, minans = 0;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				char a;
				cin >> a;
				if (a == '#') {
					rshadow[x][y] = 1;
				}
				else rshadow[x][y] = 0;
			}
		}
		
		vector<int> countl(n), countr(n);
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				countl[x] += lshadow[x][y];
				countr[x] += rshadow[x][y];
			}
		}
		for (int x = 0; x < n; x++) {
			minans += max(countl[x], countr[x]);
			maxans += countl[x] * countr[x];
		}

		cout << maxans << " "<<minans<<endl;
	}
}