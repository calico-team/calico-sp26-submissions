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



signed main (signed argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<pair<int, int>, pair<int, int>>> vt(m);
	for (auto &i: vt) {
		cin >> i.f.f >> i.f.s >> i.s.f >> i.s.s;
		i.f.f--;
		i.f.s--;
	}
	vector<int> arr(n, 0);
	vector<double> tot(n, 0), num(n, 0);
	for (auto i: vt) {
		tot[i.f.f] += (double)i.s.f*(double)i.s.s;
		tot[i.f.s] += (double)i.s.f*(double)i.s.s;
		num[i.f.f] += i.s.s;
		num[i.f.s] += i.s.s;
	}
	for (int i = 0; i < n; i++) arr[i] = num[i] ? round(sqrt(tot[i]/num[i])) : 0;
	vector<int> cons(m);
	iota(cons.begin(), cons.end(), 0);
	auto calc = [&](int a) {
			return (double)vt[a].s.s*fabs((double)(arr[vt[a].f.f]*arr[vt[a].f.s])-(double)vt[a].s.f)/(double)vt[a].s.f;
			};

	sort(cons.begin(), cons.end(), [&](int a, int b) { return calc(a) < calc(b);});
	vector<bool> bad(m, 0);
	for (int i = 0; i < k; i++) {
		bad[cons.back()] = true;
		cons.pop_back();
	}
	tot = vector<double>(n, 0), num = vector<double>(n, 0);
	for (int j = 0; j < m; j++) {
		if (bad[j]) continue;
		auto i = vt[j];
		tot[i.f.f] += (double)i.s.f*(double)i.s.s;
		tot[i.f.s] += (double)i.s.f*(double)i.s.s;
		num[i.f.f] += i.s.s;
		num[i.f.s] += i.s.s;
	}
	for (int i = 0; i < n; i++) arr[i] = num[i] ? round(sqrt(tot[i]/num[i])) : 0;
	for (int i: arr) cout << i << " ";
	cout << "\n";
	cout << k << " ";
	for (int i = 0; i < m; i++) if (bad[i]) cout << i+1 << " ";
	cout << "\n";
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

