#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
using ll = long long;

int main() {
	int t; cin >> t;
	while (t--)
	{
		int l, w, e ,r; cin >> l >> w >> e >> r;
		int result = e / ((w + l) * 2 * r);
		if (e % ((w+l) * 2 * r) > 0) result++;
		cout << result << endl;
	}
	return 0;
}