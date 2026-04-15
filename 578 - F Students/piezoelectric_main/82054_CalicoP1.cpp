#include <iostream>
#include <vector>

using namespace std;
/*
3
5 3 128 2
10 5 300 10
2 2 400 5

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		int l, w, e, r;
		cin >> l >> w >> e >> r;
		int perimeter = l * 2 + w * 2;
		int steps = e / r;
		//cout << perimeter << " " << steps;
		cout << steps / perimeter << endl;
	}
}