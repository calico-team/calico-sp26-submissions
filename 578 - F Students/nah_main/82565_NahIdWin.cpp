#include <iostream>
#include <vector>

using namespace std;

/*
6
5 60 5 1
12 6 23 8 10
4 42 10 3
40 10 5 8
3 10 5 2
5 5 5
3 20 50 3
10 10 10
4 5 10 1
4 10 10 10
1 10 100 1
15
*/

int main() {
	int t;
	cin >> t;
	for (int ab = 0; ab < t; ab++) {
		int n, p, r, k;
		cin >> n >> p >> r >> k;
		int curr = k;
		vector<int> curse(n);
		for (int x = 0; x < n; x++) cin >> curse[x];
		bool yes = true;
		for (int x = 0; x < n; x++) {
			p -= curse[x];
			curr--;
			if (p < 0) {
				cout << "nah i'd lose" << endl;
				yes = false;
				break;
			}
			if (curr == 0) {
				p += r;
				curr = k;
			}
			
		}
		if (yes) cout << "nah i'd win" << endl;
	}
}