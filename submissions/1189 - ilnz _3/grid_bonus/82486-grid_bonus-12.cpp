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
	int t;
	cin >> t;
	while (t--) {
	int n;
	cin >> n;
	vector<int> vt(n);
	for (int &i: vt) cin >> i;
	for (int i = 1; i < n-1; i++) {
		if (vt[i] < vt[i-1] && vt[i] < vt[i+1]) vt[i] = min(vt[i-1], vt[i+1]);
		if (vt[i] > vt[i-1] && vt[i] > vt[i+1]) vt[i] = max(vt[i-1], vt[i+1]);
	}
	for (int i: vt) cout << i << " ";
	cout << "\n";
	}
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

