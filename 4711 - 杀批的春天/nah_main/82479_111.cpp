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
		int n, p, r, k; cin >> n >> p >> r >> k;
		vector<int> power(n);
		for (int i = 0; i < n; i++) cin >> power[i];
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			p -= power[i];
			if (p < 0) flag = false;
			if ((i + 1) % k == 0) p += r;
		}
		if (flag) cout << "nah i'd win" << endl;
		else cout << "nah i'd lose" << endl;
	}
	return 0;
}