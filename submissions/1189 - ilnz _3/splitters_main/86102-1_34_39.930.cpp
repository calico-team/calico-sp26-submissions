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

struct T{
    int p,q;
    T():p(0),q(1){}
    T(int a,int b){p=a;q=b;int g=gcd(p,q);p/=g;q/=g;}
};
T operator*(T a,T b){return T(a.p*b.p,a.q*b.q);}
void operator*=(T&a,T b){a=a*b;}
T operator+(T a,T b){return T(a.p*b.q+b.p*a.q,a.q*b.q);}
void operator+=(T&a,T b){a=a+b;}
bool operator==(T a,T b){return a.p==b.p and a.q==b.q;}
bool operator==(T a,int b){return a.q==1 and a.p==b;}

void solve() {
	int n, m;
	cin >> n >> m;
	int upto = 2;
	vector<vector<int>> num(n, vector<int>(m));
	vector<string> grid(n);
	for (auto &i: grid) cin >> i;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j] != '.') 
		num[i][j] = upto++;
	vector<vector<int>> adj(upto);
	adj[0].push_back(num[0][0]);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (grid[i][j] == '^') {
			if (i) adj[num[i][j]].push_back(num[i-1][j]);
			else adj[num[i][j]].push_back(1);
		}
		if (grid[i][j] == 'v') {
			if (i+1 < n) adj[num[i][j]].push_back(num[i+1][j]);
			else adj[num[i][j]].push_back(1);
		}
		if (grid[i][j] == '<') {
			if (j) adj[num[i][j]].push_back(num[i][j-1]);
			else adj[num[i][j]].push_back(1);
		}
		if (grid[i][j] == '>') {
			if (j+1 < m) adj[num[i][j]].push_back(num[i][j+1]);
			else adj[num[i][j]].push_back(1);
		}
		if (grid[i][j] == 'S') {
			if (i && grid[i-1][j] != '.' && grid[i-1][j] != 'v') adj[num[i][j]].push_back(num[i-1][j]);
			if (j && grid[i][j-1] != '.' && grid[i][j-1] != '>') adj[num[i][j]].push_back(num[i][j-1]);
			if (i+1 < n && grid[i+1][j] != '.' && grid[i+1][j] != '^') adj[num[i][j]].push_back(num[i+1][j]);
			if (j+1 < m && grid[i][j+1] != '.' && grid[i][j+1] != '<') adj[num[i][j]].push_back(num[i][j+1]);
		}
	}
	vector<int> breh(upto);
	for (auto i: adj) for (int j: i) breh[j]++;
	queue<int> q;
	q.push(0);
	vector<T> dp(upto, T());
	dp[0] = T(1, 1);
	while (q.size()) {
		for (int j: adj[q.front()]) {
			dp[j] += dp[q.front()]*T(1, adj[q.front()].size());
			if (!--breh[j]) q.push(j);
		}
		q.pop();
	}
	cout << dp[1].p << " " << dp[1].q << "\n";
}

signed main (signed argc, char **argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
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

